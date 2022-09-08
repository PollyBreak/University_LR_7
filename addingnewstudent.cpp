#include "addingnewstudent.h"
#include "ui_addingnewstudent.h"
#include <QMessageBox>

int CurrentFac = -1;
QStringList fkbTEK = {"КА","КИ"};
QStringList razrabotka= {"РБ","РГ"};
QStringList truba= {"ТА","ТВ"};


addingNewStudent::addingNewStudent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addingNewStudent)
{
    ui->setupUi(this);

}

addingNewStudent::~addingNewStudent()
{
    delete ui;
}

void addingNewStudent::recieveData(QString name,QString surn, QString patr,int fac, int course, int group){
    ui->lineEdit->setText(surn);
    ui->lineEdit_2->setText(name);
    ui->lineEdit_3->setText(patr);
    ui->comboBox->setCurrentIndex(fac);
    ui->comboBox_2->setCurrentIndex(course);
    ui->comboBox_3->setCurrentIndex(group);
    this->setWindowTitle("Изменение студента");
}


void addingNewStudent::on_comboBox_activated(int index)
{
    CurrentFac = index;
    if (CurrentFac == 0) {
        ui->comboBox_3->clear();
        ui->comboBox_3->addItems(fkbTEK);
    } else if (CurrentFac == 1) {
        ui->comboBox_3->clear();
        ui->comboBox_3->addItems(razrabotka);
    } else if (CurrentFac == 2) {
        ui->comboBox_3->clear();
        ui->comboBox_3->addItems(truba);
    }
}

void addingNewStudent::on_buttonBox_accepted()
{
    ui->lineEdit->setText(ui->lineEdit->text().trimmed());
    ui->lineEdit_2->setText(ui->lineEdit_2->text().trimmed());
    ui->lineEdit_3->setText(ui->lineEdit_3->text().trimmed());
    if (ui->lineEdit->text() == "" || ui->lineEdit_2->text() == "" || ui->comboBox->currentIndex() == -1 || ui->comboBox_2->currentIndex() == -1 || ui->comboBox_3->currentIndex() == -1 ) {
        QMessageBox q1;
        q1.setWindowTitle("Ошибка!");
        q1.setText("Недостаточно данных. Заполните пустые строки.");
        q1.exec();
    }
    else {
        emit sendData(ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text(),ui->comboBox_2->currentIndex(), ui->comboBox->currentIndex(),ui->comboBox_3->currentIndex());
        this->close();
    }
}

