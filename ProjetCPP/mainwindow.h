#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Lancer_clicked();

    void on_Import_X_clicked();

    void on_Pred_clicked();

    void on_Import_Y_clicked();

    void on_Import_Test_clicked();


    void on_Trier_toggled();

    void on_About_Button_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
