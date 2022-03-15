#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QString>
#include <math.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public:
    void  setnum1(double num);
    void  setnum2(double num);
    void  setOpcode(int opcode);
    double calculate();


private:
    double num1,num2;
    int Opcode;
    double memory;
    QString fucCode;
    int startfuc;
public:
    double result_;

private slots:
    void on_action_button_start_clicked();
    void on_number_button_clicked();
    void on_Opcode_button_clicked();
    void on_action_button_equral_clicked();

    void on_action_button_del_clicked();
    void on_action_button_point_clicked();

    void on_action_button_Mplus_clicked();
    void on_action_button_Msub_clicked();
    void on_action_button_MR_clicked();
    void on_action_button_MC_clicked();

    void on_fuction_button_clicked();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
