#include "MainWindow.h"
#include "ui_MainWindow.h"

#include<QtDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 初始化存储器
    memory = 0;
    startfuc = 0;
   // this->setWindowIcon(QIcon("E:\\OJ\\QtApplication\\QtApplication1\\Icon\\Apptitle.jpg"));

    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(on_number_button_clicked()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(on_number_button_clicked()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(on_number_button_clicked()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(on_number_button_clicked()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(on_number_button_clicked()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(on_number_button_clicked()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(on_number_button_clicked()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(on_number_button_clicked()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(on_number_button_clicked()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(on_number_button_clicked()));

    connect(ui->ADD,SIGNAL(clicked()),this,SLOT(on_Opcode_button_clicked()));
    connect(ui->SUB,SIGNAL(clicked()),this,SLOT(on_Opcode_button_clicked()));
    connect(ui->DIV,SIGNAL(clicked()),this,SLOT(on_Opcode_button_clicked()));
    connect(ui->MUL,SIGNAL(clicked()),this,SLOT(on_Opcode_button_clicked()));

    connect(ui->equal,SIGNAL(clicked()),this,SLOT(on_action_button_equral_clicked()));
    connect(ui->Clean,SIGNAL(clicked()),this,SLOT(on_action_button_start_clicked()));

    connect(ui->DEL,SIGNAL(clicked()),this,SLOT(on_action_button_del_clicked()));
    connect(ui->point,SIGNAL(clicked()),this,SLOT(on_action_button_point_clicked()));

    connect(ui->M_plus,SIGNAL(clicked()),this,SLOT(on_action_button_Mplus_clicked()));
    connect(ui->M_sub,SIGNAL(clicked()),this,SLOT(on_action_button_Msub_clicked()));
    connect(ui->MR,SIGNAL(clicked()),this,SLOT(on_action_button_MR_clicked()));
    connect(ui->MC,SIGNAL(clicked()),this,SLOT(on_action_button_MC_clicked()));

    connect(ui->x2,SIGNAL(clicked()),this,SLOT(on_fuction_button_clicked()));
    connect(ui->fuc1x,SIGNAL(clicked()),this,SLOT(on_fuction_button_clicked()));
    //connect(ui->Tan,SIGNAL(clicked()),this,SLOT(on_fuction_button_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
// 设置计算参数、计算函数
void MainWindow::setnum1(double num)
{
    num1 = num;
}
void MainWindow::setnum2(double num)
{
    num2 = num;
}
void MainWindow::setOpcode(int opcode)
{
      Opcode = opcode;
}

double MainWindow::calculate()
{
    if(startfuc == 1)
    {
        if(fucCode == "1/x")
        {
            result_ = 1 / num1;
        }
        else if(fucCode == "x2")
        {
            result_ = num1 * num1;
        }

        result_ = result_ + memory;
        return result_;
    }
    else
    {
        switch(Opcode)
        {
            case 0:{ result_ = num1 + num2;break;}// +
            case 1:{ result_ = num1 - num2;break;};// -
            case 2:{ result_ = num1 * num2;break;}// *
            case 3:
            {
                if(num2 == 0) return -1;
                else
                    result_ = num1 / num2;
                break;
            };// /
            default:{ result_ = 0;}
        }
        result_ = result_ + memory;
        return result_;
    }
}

// 槽函数合集
void MainWindow::on_action_button_start_clicked()
{
    setnum1(0);
    setnum2(0);
    setOpcode(-1);
    ui->input->clear();
    ui->output->clear();
}
void MainWindow::on_number_button_clicked()
{
    QPushButton* btn = qobject_cast<QPushButton*>(sender());
    QString number_0 = btn->text();
    QString temp = ui->input->toPlainText();
    QString str;

    if(temp.contains("x2",Qt::CaseSensitive) ==1 ||
       temp.contains("1/x",Qt::CaseSensitive)==1
       )
    {
        str = number_0;
        setnum1(str.toDouble());
    }
    else
    {
        str = temp + number_0;
        ui->input->clear();
        ui->input->insertPlainText(str);
    }
}
void  MainWindow::on_Opcode_button_clicked()
{
    double number = ui->input->toPlainText().toDouble();
    setnum1(number);

    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    QString Opcode = btn->text();
    ui->input->insertPlainText(Opcode);


    if(Opcode == "+") setOpcode(0);
    else if (Opcode == "-") {setOpcode(1);}
    else if (Opcode == "*") {setOpcode(2);}
    else if(Opcode == "/")  {setOpcode(3);}
    else setOpcode(4);

}
void MainWindow::on_action_button_equral_clicked()
{
    if(startfuc == 1)
    {
        double result = calculate();
        QString resultstr;
        resultstr.setNum(result);
        ui->output->insertPlainText(resultstr);
    }
    else
    {
        QString ssr = ui->input->toPlainText();
        QString check;
        for(int i=0;ssr[i]!='\0';i++)
        {
            if(ssr[i] == "+" || ssr[i] == "-" || ssr[i] == "*" || ssr[i] == "/")
            {
               for(int j=i+1;ssr[j]!='\0';j++)
               {
                   check = check + ssr[j];
               }
            }
        }

        double number = check.toDouble();
        setnum2(number);


        double result = calculate();

        QString resultstr;
        resultstr.setNum(result);
        ui->output->insertPlainText(resultstr);
    }

}

void MainWindow::on_action_button_del_clicked()
{
    QString temp = ui->input->toPlainText();
    int position = temp.size()-1;
    temp.remove(position,1);
    ui->input->clear();
    ui->input->insertPlainText(temp);
}

void MainWindow::on_action_button_Mplus_clicked()
{
    double number = ui->output->toPlainText().toDouble();
    memory = number;
    ui->M->insertPlainText("M");
}
void MainWindow::on_action_button_Msub_clicked()
{
    double number = ui->output->toPlainText().toDouble();
    memory = number * -1;
    ui->M->insertPlainText("M");
}

void MainWindow::on_action_button_MR_clicked()
{
    ui->output->clear();

    ui->output->insertPlainText(QString("%1").arg(memory));

}
void MainWindow::on_action_button_MC_clicked()
{
    ui->M->clear();
    memory = 0;
}


void MainWindow::on_action_button_point_clicked()
{
    ui->input->insertPlainText(".");
}

void MainWindow::on_fuction_button_clicked()
{
    QPushButton* btn = qobject_cast<QPushButton*>(sender());
    fucCode = btn->text();
    //可以进行fuc运算；
    startfuc = 1;
    ui->input->insertPlainText(fucCode);
}
















