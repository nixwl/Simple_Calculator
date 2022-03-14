#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QString>

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
    void  setnum1(int num);
    void  setnum2(int num);
    void  setOpcode(int opcode);
    int calculate();

private:
    int num1,num2,Opcode;
    int memory;
public:
    int result_;

private slots:
    void on_action_button_start_clicked();
    void on_number_button_clicked();
    void on_Opcode_button_clicked();
    void on_action_button_equral_clicked();

    void on_action_button_del_clicked();

    void on_action_button_Mplus_clicked();
    void on_action_button_Msub_clicked();
    void on_action_button_MR_clicked();
    void on_action_button_MC_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
