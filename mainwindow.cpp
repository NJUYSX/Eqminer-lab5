#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QFileDialog>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Eqminer");
    setFixedSize(800,600);
    ui->label->setAlignment(Qt::AlignCenter);

    //设置选择文件价按钮
    connect(ui->Select_Directory,&QPushButton::clicked,[=](){
       QString DirectoryPath=QFileDialog::getExistingDirectory(this,"选取文件夹");
       ui->lineEdit->setText(DirectoryPath);
    });

    //设置开始判等按钮
    connect(ui->StartJudgementBtn,&QPushButton::clicked,[=](){
      QString DirectoryPath=ui->lineEdit->text();
      StartJudgement(DirectoryPath.toStdString());//等价判断工具
      this->hide();
      Confirmation *confirmation=new Confirmation(this);
      confirmation->show();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

