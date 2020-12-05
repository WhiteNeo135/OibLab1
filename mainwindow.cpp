#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "ctime"
#include"cmath"

//using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_WorkButton_clicked()
{
    srand(time(nullptr));

    std::string login = ui->LoginLine->text().toStdString();
    char randomChar[]={'!','"','#','$','%','&','\'',',','*'};
    std::string password;
    QString translateToQt;
    int randomNumber;
    int functionP=(login.length() * login.length()) %10 + (login.length() * login.length() * login.length()) %10 + 1;

    for (int i=0; i<3;++i)
    {
        randomNumber=rand()%10;
        password+=std::to_string(randomNumber);
    }

    for (int i=0; i<3; ++i)
        password+=randomChar[rand()%8];

    password+=(char) 65 + rand()%26;
    password+=(char) 64+functionP;

    translateToQt=QString::fromStdString(password);

    ui->PasswordLine->setText(translateToQt);
}
