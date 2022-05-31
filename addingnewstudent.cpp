#include "addingnewstudent.h"
#include "ui_addingnewstudent.h"


int CurrentFac = -1;
QStringList fkbTEK = {"КА","КИ"};
QStringList razrabotka= {"ТА","ТВ"};
QStringList truba= {"РБ","РГ"};


addingNewStudent::addingNewStudent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addingNewStudent)
{
    ui->setupUi(this);
    if ()
}

addingNewStudent::~addingNewStudent()
{
    delete ui;
}

void addingNewStudent::recieveData(QString Name,QString Surn){
    ui->lineEdit->setText(Name);
    ui->lineEdit_2->setText(Surn);
    this->setWindowTitle("Изменение студента");
}
