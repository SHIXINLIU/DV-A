#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTextCodec>
#include <QMessageBox>
#include <QPainter>
#include <match.h>
#include <restaurant.h>
#include <dataprocessing.h>
#include <iostream>
#include <QDebug>
#include <QWidget>
#include <myimgtest.h>

using namespace std;
QList <class restaurant> result;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


void MainWindow::enableSearchButton(const QString &text)
{
    ui->SearchButton->setEnabled(!text.isEmpty());
}

void MainWindow::on_SearchButton_clicked()
{
    QList<restaurant> data;
    data.clear();
    data=dataprocessing();
    QString searchs = ui->SearchEdit->text();

    if (searchs.isEmpty() == 0)
    {
        //QList<restaurant> result;
        result=match(method,searchs,data);
        QString R;

        if (result.isEmpty()==0)
        {
            int i=1;
            Q_FOREACH(restaurant r, result)
            {
                R+=     QString::number(i)+": \n"+
                        r.getname().toUpper()+"\n"+
                        "Address: "+r.getaddress()+"\n"+
                        "Average Stars: "+QString::number(r.getstars())+"\n"+
                        "Review Count: "+QString::number(r.getreview_count())+"\n"+
                        "\n";
                i++;
            }
            ui->ListLabel->setText(R);
            //MyImgTest* widget = new MyImgTest();
            //    widget->show();
            //QMessageBox::information(this, tr("list"),R)
        }
        else {
            ui->ListLabel->setText("No result.");
        }

    }
    else {
        ui->ListLabel->setText("No result.");
    }
    //show_results(searchs);

}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_NameButton_clicked()
{
    MainWindow::set_method(1);
}

void MainWindow::on_AddressButton_clicked()
{
    MainWindow::set_method(2);
}

/*void MainWindow::on_TypeButton_clicked()
{
    MainWindow::set_method(3);
}*/

void MainWindow::on_MapButton_clicked()
{
    QList<restaurant> data;
    data.clear();
    data=dataprocessing();
    QString searchs = ui->SearchEdit->text();

    if (searchs.isEmpty() == 0)
    {
        //QList<restaurant> result;
        result=match(method,searchs,data);
        QString R;

        if (result.isEmpty()==0)
        {
            int i=1;
            Q_FOREACH(restaurant r, result)
            {
                R+=     QString::number(i)+": \n"+
                        r.getname().toUpper()+"\n"+
                        "Address: "+r.getaddress()+"\n"+
                        "Average Stars: "+QString::number(r.getstars())+"\n"+
                        "Review Count: "+QString::number(r.getreview_count())+"\n"+
                        "\n";
                i++;
            }
            ui->ListLabel->setText(R);
            MyImgTest* widget = new MyImgTest();
                widget->show();
        }
    }
}
