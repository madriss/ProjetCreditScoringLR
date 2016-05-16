#include "mainwindow.h" // ligne générée automatiquement par QT pour afficher l'interface graphique
#include "ui_mainwindow.h" // ligne générée automatiquement par QT pour afficher l'interface graphique
#include <mlpack/core.hpp> // mlpack : librairie de machine learning qui contient armadillo (librarie de calcul matricielle)
#include <QMessageBox> // librarie de QT pour afficher des msgbox
#include <QInputDialog> // librairie QT pour les inputbox
#include <QFileDialog> // librairie de QT pour ouvrire une fenetre explorateur de fichier
#include <math.h>   // pour utiliser la fonction exponentielle
#include <string>   // on manipule des chaînes de caractère
#include <fstream> // pour la lecture de csv de la fonction nettoyer_csv
#include <vector> // pour tableau dynamique

using namespace arma; // pour faciliter le codage
using namespace mlpack; // pour faciliter le codage

//Déclaration des variables globales
arma::mat parameters; // paramètres estimés par le modèle de regression linéaire
arma::mat P; // matrice des individus à tester
int individu; // variable globale contenant le numero de l'individu à tester
arma::mat Probas; // matrice avec les probas de chaque individus à tester
double seuil_proba; //contient la valeur du spinner

MainWindow::MainWindow(QWidget *parent) : // code généré automatiquement par QT
    QMainWindow(parent),// code généré automatiquement par QT
    ui(new Ui::MainWindow)// code généré automatiquement par QT
{
    ui->setupUi(this);// code généré automatiquement par QT
}

MainWindow::~MainWindow()// code généré automatiquement par QT
{
    delete ui;// code généré automatiquement par QT
}

double string_to_double(std::string texte){
    return std::stod(texte.c_str(),NULL);
}
void Nettoyer_csv(std::string nom_fichier){// on nettoie les entêtes
    std::fstream fichier;
    std::vector <std::string> tableau; //vecteur dynamique de string
    std::string ligne;
    QMessageBox msgbox;
    // on avertit l'utilisateur qu'une entête a été detectée et est en cours de nettoyage
    msgbox.setText("Entete detectee dans :\n\n"+ QString::fromStdString(nom_fichier)+"\n\nNettoyage en cours ..."); // string en QString
    msgbox.setWindowTitle("Nettoyage des entetes en cours");
    msgbox.setIcon(QMessageBox::Warning);
    msgbox.exec();
    int i = 0;
    fichier.open(nom_fichier,ios::in);
    while(getline(fichier,ligne)){ // on enregistre tout le fichier dans un tableau
        tableau.push_back(ligne);
        i++;
    }
    fichier.close();
    fichier.open(nom_fichier,ios::out);
    for (int k = 1; k < i;k++){
        fichier << tableau[k] << std::endl;
    }
    fichier.close();
    msgbox.setText("Nettoyage termine avec succes !");
    msgbox.setWindowTitle("Nettoyage reussi");
    msgbox.setIcon(QMessageBox::Information);
    msgbox.exec();
}
void Verif_csv(std::string nom_fichier){//on verifie la présence de texte dans la première ligne pour la nettoyer
    std::fstream fichier;
    std::string lexeme;
    fichier.open(nom_fichier,ios::in);
    while(getline(fichier,lexeme,',')){ // ajout de ',' pour lire entre les virgules
        try{
            string_to_double(lexeme); // on tente de convertir le string en nombre
        }
        catch(const std::invalid_argument& e){// si une erreur invalid_argument est rencontrée dans try (impossibilité de convertir le string en double), on ferme le fichier et on le nettoie en supprimant la première ligne
            fichier.close();
            Nettoyer_csv(nom_fichier);
            return;
        }
    }
    fichier.close();
    return;
}

mat arrondi_seuil(mat A, int colonne, double seuil){
int nb_lignes = A.n_rows;
for (int i = 0; i < nb_lignes; i++){
    if(A(i,colonne) < seuil){
        A(i,colonne) = 0;
    }
    else{
        A(i,colonne) = 1;
    }
}
    return A;
}
mat Ajout_col_num_lignes(mat A){
vec Vecteur_nul = zeros(A.n_rows); // création d'un vecteur de zéros, qui sera rempli avec les numéros de lignes
    A.insert_cols(1,Vecteur_nul);
    return A;
}

mat Ordonner_matrice(mat A,bool ordre){
    uvec indices; // on crée une variable de type uvec, obligatoire pour utiliser la fonciton sort_index
    vec colonne_a_ordonner = A.col(0); // création d'une variable vecteur, contenant la première colonne à ordonner
    int nb_lignes = A.n_rows;
    if(ordre == 1){
        indices = sort_index(colonne_a_ordonner,"ascend");//fonction qui donne les anciens indices de lignes après avoir été ordonné
        A = sort(A,"ascend");
        for (int i = 0; i < nb_lignes; i++){ // boucle pour attribuer les bons numéros de lignes à la colonne de zéros
            A(i,1)=indices(i);
        }
        return A;
    }

    else{ // pareil qu'avant mais ordre décroissant
        indices = sort_index(colonne_a_ordonner, "descend");//fonction qui donne les anciens indices de lignes après avoir été ordonné
        A = sort(A,"descend");
        for (int i = 0; i < nb_lignes;i++){ // boucle pour attribuer les bons numéros de lignes à la colonne de zéros
            A(i,1)=indices(i);
        }
        return A;
    }
}
mat Multiplier_Matrices(mat A, mat B){ // fonction pour multiplier deux matrices entre elles
    int nb_colsA = A.n_cols;
    int nb_lignesB = B.n_rows;
    QMessageBox msgbox;
    if(nb_colsA != nb_lignesB)
    {
        msgbox.setText("Multiplication matricielle impossible, mauvaises dimensions");
        msgbox.setWindowTitle("Impossible de multiplier les matrices");
        msgbox.setIcon(QMessageBox::Critical);
        msgbox.exec();
        exit(0); // ferme tout le programme pour éviter d'avoir des bugs après
    }
    return A*B;
}

mat Inverse_Mat(mat A){ // fonction pour inverser une matrice
    QMessageBox msgbox;
    double determinant = det(A);
    if(determinant == 0){
        msgbox.setText("Inversion impossible, determinant nul");
        msgbox.setWindowTitle("Inversion impossible");
        msgbox.setIcon(QMessageBox::Critical);
        msgbox.exec();
        exit(0); // quitter le programme pour éviter les erreurs
    }
    return inv(A);
}

mat probas_logistique_regression(mat X, mat Betas){

    return 1/(1+exp(-Multiplier_Matrices(X,Betas)));

}

void MainWindow::on_Lancer_clicked() // code du bouton "Lancer"
{
        // First, load the data.
        bool ok; // booléen à utiliser pour l'inputbox
        QMessageBox msgbox; // Creation d'un objet Qmessagebox pour afficher des msgbox
        std::string chemin_X = ui->Regresseurs->toPlainText().toStdString();
        std::string chemin_Y = ui->Reponses->toPlainText().toStdString();
        std::string chemin_Test = ui->Fichier_test->toPlainText().toStdString();
        arma::mat X; // Matrice des regresseurs
        arma::mat y; // Matrice des réponses
        // Programmation défensive : empêcher obliger l'utilisateur à choisir des fichiers à importer
        if(chemin_X==""|| chemin_Y=="" || chemin_Test==""){
            msgbox.setText("Veuillez renseigner les champs demandes, operation impossible!");
            msgbox.setWindowTitle("Impossible de continuer, champs vides");
            msgbox.setIcon(QMessageBox::Critical);
            msgbox.exec();
            exit(0);
        }
        //nettoyage des entêtes s'il y'en a
        Verif_csv(chemin_X);
        Verif_csv(chemin_Y);
        Verif_csv(chemin_Test);

        X.load(ui->Regresseurs->toPlainText().toStdString()); // On importe la matrice qui se situe dans la textEdit puis on convertit le format QString en String
        y.load(ui->Reponses->toPlainText().toStdString()); // On importe la matrice qui se situe dans la textEdit puis on convertit le format QString en String
        P.load(ui->Fichier_test->toPlainText().toStdString()); // On importe la matrice qui se situe dans la textEdit puis on convertit le format QString en String

        // Ajout de la constante dans le modèle

        vec Vecteur_Unitaire = ones <vec>(X.n_rows);
        X.insert_cols(0,Vecteur_Unitaire);

        // Obtenir les parameters, ou coefficients.
        parameters = Multiplier_Matrices(X.t(),X);
        ui->progressBar->setValue(25); // 25 car on a fait 1/4 des opérations
        parameters = Multiplier_Matrices(Inverse_Mat(parameters),X.t());
        ui->progressBar->setValue(50); // 50 car on a fait 1/2 des opérations
        parameters = Multiplier_Matrices(parameters,y);
        ui->progressBar->setValue(75); // 75 car on a fait 1/2 des opérations
        Probas = probas_logistique_regression(X,parameters);
        ui->progressBar->setValue(100); // 100 car fin des opérations

        // ajout du numéro de lignes avant d'ordonner les matrices
        Probas = Ajout_col_num_lignes(Probas);
        // ordonner matrice proba si case cochée
        if (ui->Trier->isChecked()){ // si case cochée
            if(ui->Ordre->currentText().toStdString()=="Ascendant"){ //.toStdString pour pouvoir comparer le QString à du String standard
                Probas = Ordonner_matrice(Probas,1); // fonction pour ordonner avec 1 qui correspond à ascendant
            }
            if(ui->Ordre->currentText().toStdString()=="Descendant"){//.toStdString pour pouvoir comparer le QString à du String standard
                Probas = Ordonner_matrice(Probas,0); // fonction pour ordonner avec 1 qui correspond à descendant
            }
        }
        // arrondi si case seuil coché
        seuil_proba = ui->seuil->value();
        if (ui->Probas_Seuil->isChecked()==true){
            Probas = arrondi_seuil(Probas,0,seuil_proba);
        }


        msgbox.setText("Les probas ont ete correctement estimees, exporter sous format csv?");
        msgbox.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
        msgbox.setDefaultButton(QMessageBox::Yes);
        msgbox.setIcon(QMessageBox::Question);
        msgbox.setWindowTitle("Estimation des probas reussie !");
        int ret = msgbox.exec(); // appuyer sur un bouton va renvoyer un entier qui sera stocké dans ret
        switch(ret){
            case QMessageBox::Yes:{
                // Exporter les probas.
                QString nom_fichier_probas = QInputDialog::getText(this, tr("Nom fichier matrice probas"),
                                                                   tr("Veuillez choisir un nom de ficheir a exporter pour la matrice des probabilites"),QLineEdit::Normal, QDir::home().dirName(), &ok);
                if (ok && nom_fichier_probas.isEmpty()){
                    nom_fichier_probas = "probas.csv";
                }
                if (nom_fichier_probas.right(4) != ".csv"){
                    nom_fichier_probas.append(".csv");
                }
                Probas.save(nom_fichier_probas.toStdString(),csv_ascii); // on enregistre les probas sous un fichier csv, on précise le format avec csv_ascii
                msgbox.setText("Exportation effectuee sous "+nom_fichier_probas);
                msgbox.setStandardButtons(QMessageBox::Ok);
                msgbox.setWindowTitle("Exportation reussie !");
                msgbox.setIcon(QMessageBox::Information);
                msgbox.exec();// pour faire sortir le msgbox
                break;
                }
            case QMessageBox::No:
                msgbox.setText("Les probas ont ete estimees mais pas exportees");
                msgbox.setStandardButtons(QMessageBox::Ok);
                msgbox.setWindowTitle("Probas non exportees");
                msgbox.setIcon(QMessageBox::Information);
                msgbox.exec();// pour faire sortir le msgbox
                break;
        }
        // exportation des paramèetres si la checkbock est cochée
        if (ui->Export_Params->isChecked()){
            QString nom_fichier_params = QInputDialog::getText(this, tr("Nom fichier parametres"),
                                                               tr("Veuillez choisir un nom de ficheir a exporter pour la matrice des parametres"),QLineEdit::Normal, QDir::home().dirName(), &ok);
            if (ok && nom_fichier_params.isEmpty()){
                nom_fichier_params = "probas.csv";
            }
            if (nom_fichier_params.right(4) != ".csv"){
                nom_fichier_params.append(".csv");
            }
            parameters.save(nom_fichier_params.toStdString(),csv_ascii);
            msgbox.setText("Les parametres ont aussi ete sauvegardes dans le repertoire courant sous " + nom_fichier_params);
            msgbox.setWindowTitle("Parametres enregistres");
            msgbox.exec();
        }

        ui->Pred->setEnabled(1); // on active le bouton permettant de faire des prédictions
        ui->individu_i->setMaximum(Probas.n_rows); // maximum de la spin box
}

void MainWindow::on_Pred_clicked() // bouton prédire
{

    individu = ui->individu_i->value(); // récupérer le contenu de la spinbox
    double proba_i = Probas(individu,0); //on veut le numéro dans la matrice des probas
    QString doubleAsString = QString::number(proba_i*100, 'd',4); // Conversion d'un double en QString affin de l'afficher dans QT (label)
    QString intAsString = QString::number(Probas(individu,1));// Obtenir le num de l'individu avant que la matrice soit ordonnée pour l'afficher dans le label
    QString individu_i_QString = QString::number(individu);// conversion du contenu de la spinbox en QString pour l'afficher dans le label
    if ((ui->Trier->isChecked()== false)|| (ui->Probas_Seuil->isChecked()== true)){
        ui->label_7->setText("Proba de defaut de l'individu "+individu_i_QString+" est de "+doubleAsString+"%"); // affichage de la variable de type QString dans l'interface
    }
    else if(ui->Trier->isChecked()== true){
        ui->label_7->setText("Proba ordonnee "+individu_i_QString+" est de "+doubleAsString+"%"+" correspondant a i = " +intAsString); // affichage de la variable de type QString dans l'interface
    }
}

void MainWindow::on_Import_X_clicked() // code permettant d'ouvrir une fenetre explorateur
{
    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Ouvrir le fichier csv des regresseurs"),
                                                    qApp->applicationDirPath(),
                                                    "All files (*.*)");
    //tr : titre de la fenetre
    // qApp-> applicationDirPath() :

    ui->Regresseurs->document()->setPlainText(filename); // une fois que le fichier est selectionné et placé dans le QString filename, on le met dans la textbox correspondante
}

void MainWindow::on_Import_Y_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Ouvrir le fichier csv des reponses"),
                                                    qApp->applicationDirPath(),
                                                    "All files (*.*)");

    //tr : titre de la fenetre
    // qApp-> applicationDirPath() :
    ui->Reponses->document()->setPlainText(filename);// une fois que le fichier est selectionné et placé dans le QString filename, on le met dans la textbox correspondante
}

void MainWindow::on_Import_Test_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Ouvrir le fichier csv des individus a tester"),
                                                    qApp->applicationDirPath(),
                                                    "All files (*.*)");

    //tr : titre de la fenetre
    // qApp-> applicationDirPath() :
    ui->Fichier_test->document()->setPlainText(filename); // une fois que le fichier est selectionné et placé dans le QString filename, on le met dans la textbox correspondante
}



void MainWindow::on_Trier_toggled()
{
    ui->Ordre->clear(); // on vide la QCombobox avant d'y réajouter des éléments
    ui->Ordre->addItem(tr("Descendant")); // code pour ajouter un élément
    ui->Ordre->addItem(tr("Ascendant"));

}

void MainWindow::on_About_Button_clicked()
{
    QMessageBox msgbox;
    msgbox.setText("Logistic Regression Software \nFor Credit Scoring and Fraud Detection \n\n\nBy Raphael Zanotto and Madriss Seksaoui\n2016 all rights reserved");
    msgbox.setWindowTitle("About this Software");
    msgbox.setIcon(QMessageBox::Information);
    msgbox.exec();
}
