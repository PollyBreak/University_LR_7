#include "addinggrades.h"
#include "ui_addinggrades.h"

addingGrades::addingGrades(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addingGrades)
{
    ui->setupUi(this);
}

addingGrades::~addingGrades()
{
    delete ui;
}

void addingGrades::recieveGrades(int m,int e,int f,int i){
    ui->comboBox->setCurrentIndex(m);
    ui->comboBox_2->setCurrentIndex(e);
    ui->comboBox_3->setCurrentIndex(f);
    ui->comboBox_4->setCurrentIndex(i);
}

void addingGrades::on_buttonBox_accepted()
{
    emit sendGrades(ui->comboBox->currentIndex(),ui->comboBox_2->currentIndex(),ui->comboBox_3->currentIndex(),ui->comboBox_4->currentIndex());
    this->close();
}


