#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "HarrixQtLibrary.h"
#include "HarrixMathLibrary.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->textEdit->clear();

    int i;

    //Первая выборка
    QString SX;
    SX = ui->textEdit_2->toPlainText();
    QStringList QStringListX;
    QStringListX = HQt_QStringToQStringList(SX);

    int NX=HQt_CountOfRowsFromQStringList(QStringListX);

    double *X = new double[NX];

    THQt_ReadVectorFromQStringList(QStringListX, X);

//    for (i=0;i<NX;i++)
//        ui->textEdit->insertPlainText(QString::number(X[i])+"\n");
//    ui->textEdit->insertPlainText("\n");

    //Вторая выборка
    QString SY;
    SY = ui->textEdit_3->toPlainText();
    QStringList QStringListY;
    QStringListY = HQt_QStringToQStringList(SY);

    int NY=HQt_CountOfRowsFromQStringList(QStringListY);

    double *Y = new double[NY];

    THQt_ReadVectorFromQStringList(QStringListY, Y);

//    for (i=0;i<NY;i++)
//        ui->textEdit->insertPlainText(QString::number(Y[i])+"\n");
//    ui->textEdit->insertPlainText("\n");

    ui->textEdit->insertHtml("<b>Размер первой выборки:</b><br>");
    ui->textEdit->insertHtml("n<sub>1</sub> = "+QString::number(NX)+"<br>");

    ui->textEdit->insertHtml("<b>Размер второй выборки:</b><br>");
    ui->textEdit->insertHtml("n<sub>2</sub> = "+QString::number(NY)+"<br><br>");

    int VMHL_Result;
    double Q;

    QString Space="";

    for (i=0;i<6;i++)
    {
        if (i==0) {Q=0.002;Space="0.002";}
        if (i==1) {Q=0.01;Space="0.010";}
        if (i==2) {Q=0.02;Space="0.020";}
        if (i==3) {Q=0.05;Space="0.050";}
        if (i==4) {Q=0.1;Space="0.100";}
        if (i==5) {Q=0.2;Space="0.200";}

        VMHL_Result=MHL_WilcoxonW(X,Y,NX,NY,Q);

        ui->textEdit->insertHtml("При уровне значимости Q = "+Space+": ");

        if (VMHL_Result==-1)
            ui->textEdit->insertHtml("<b>Объемы выборок не позволяют провести проверку при данном уровне значимости.</b><br><br>");
        if (VMHL_Result==0)
            ui->textEdit->insertHtml("<b>Выборки <font color=\"red\">неоднородны</font>  при данном уровне значимости.</b><br><br>");
        if (VMHL_Result==1)
            ui->textEdit->insertHtml("<b>Выборки <font color=\"green\">однородны</font>  при данном уровне значимости.</b><br><br>");
    }

    ui->textEdit->insertHtml("<b>Примечание.</b><br>");
    ui->textEdit->insertHtml("В качестве результата лучше брать ответ при Q=0.002.");

    delete[] X;
    delete[] Y;
}
