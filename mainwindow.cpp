#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVector>
#include <QString>
#include <QMap>

int numOfStudents = 0;
class Student;
class Course;
class Group;
class Faculty;
class Subject;
QMap <int, Student> allStudents;
QMap <int, Student> ::iterator it1;
QVector <Faculty> ::iterator it2;


QStringList fkbTEK = {"КА","КИ"};
QStringList razrabotka= {"ТА","ТВ"};
QStringList truba= {"РБ","РГ"};


class Faculty {
public:
    QString name;
    QVector <Student> students;
    QVector <Student> deadStudents;
    QVector <Course> courses;
    Faculty() {
    }
    Faculty(QString n) {
        name = n;
    }
};

class Course {
public:
    int nomer;
    int numStudents;
    int numDis;
    QVector <Group> groups;
    QVector <Student> students;
    QVector <Student> deadStudents;
    Course(int nomer) {
        this->nomer = nomer;
    }
    Course() {
    }
};

class Group {
public:
    QString name;
    int numDis;
    int numStudents;
    QVector <Student> students;
    QVector <Student> deadStudents;
    Group() {}
    Group(QString name) {
        this->name = name;
    }
};

class Subject {
public:
    QString name;
    int grade;
    Subject() {
    }
    Subject(QString name) {
        this->name = name;
    }
};

class Student {
public:
    int id;
    QString name;
    QString surname;
    int course;
    QString group;
    int idGroup;
    QString faculty;
    int idFaculty;
    bool stillStudent = true;
    std::vector <Subject> subs{ Subject("Математический анализ"), Subject("Экономика"), Subject("Физика"), Subject("Иностранный язык") };
   /*void setGrades(int g1, int g2, int g3, int g4) {
        subs[0].grade = g1; //math grade
        subs[1].grade = g1; //economy grade
        subs[2].grade = g1; //physics grade
        subs[3].grade = g4; // foreign language grade
    }*/
    Student() {
        this->id = numOfStudents;
    }
    Student(QString name, QString surname, int course, int idFaculty, int idGroup) {
        numOfStudents++;
        this->id = numOfStudents;
        this->name = name;
        this->surname = surname;
        this->course = course;
        this->idFaculty = idFaculty;
        this->idGroup = idGroup;
        switch (idFaculty) {
        case 1:
            this->faculty = "факультет комплексной безопасности ТЭК";
            this->idFaculty = 0;
            if (idGroup == 1) {
                group = "KA";
            }
            else {
                group = "КИ";
            }
            break;
        case 2:
            this->faculty = "факультет разработки нефтяных и газовых месторождений";
            this->idFaculty = 1;
            if (idGroup == 1) {
                group = "TA";
            }
            else {
                group = "ТВ";
            }
            break;
        case 3:
            this->faculty = "факультет проектирования, сооружения и эксплуатации систем трубопроводного транспорта";
            this->idFaculty = 2;
            if (idGroup == 1) {
                group = "РБ";
            }
            else {
                group = "РГ";
            }
            break;
        }
    }
};







MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
        QVector <Faculty> facs;
        QVector <Faculty> :: iterator it1;
        Faculty fac1;
        fac1.name = "ФКБ ТЭК";
        Faculty fac2;
        fac2.name = "Труба";
        Faculty fac3;
        fac3.name = "Разработка";
        facs.push_back(fac1);
        facs.push_back(fac2);
        facs.push_back(fac3);
        Course one(1);
        Course two(2);
        Course three(3);
        Course four(4);
        for (int i = 0; i < 3; i++) {
            facs[i].courses.push_back(one);
            facs[i].courses.push_back(two);
            facs[i].courses.push_back(three);
            facs[i].courses.push_back(four);
        }

        Group group0("KA");
        Group group1("KИ");
        for (int i = 0; i < 4; i++) {
            facs[0].courses[i].groups.push_back(group0);
            facs[0].courses[i].groups.push_back(group1);
        }
        Group group3("ТА");
        Group group4("ТВ");
        for (int i = 0; i < 4; i++) {
            facs[1].courses[i].groups.push_back(group3);
            facs[1].courses[i].groups.push_back(group4);
        }
        Group group5("РБ");
        Group group6("РГ");
        for (int i = 0; i < 4; i++) {
            facs[2].courses[i].groups.push_back(group5);
            facs[2].courses[i].groups.push_back(group6);
        }
    ui->setupUi(this);
    ui->tableWidget->setRowCount(150);
    ui->tableWidget->setColumnCount(9);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "id" << "ФИО" << "Факультет" << "Курс" << "Группа" << "Матан" << "Экономика"<< "Физика"<< "Ин. яз");
    ui->tableWidget->setColumnWidth(0,40);
    ui->tableWidget->setColumnWidth(1,400);
    ui->tableWidget->setColumnWidth(2,150);
    ui->tableWidget->setColumnWidth(3,80);
    ui->tableWidget->setColumnWidth(4,80);
    ui->tableWidget->setColumnWidth(5,150);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    newSt = new addingNewStudent();
    //connect(newSt,SIGNAL(sendData(QString,QString)),this,SLOT(receiveData(QString,QString)));
    //connect(this,SIGNAL(sendData(QString,QString)),newSt,SLOT(receiveData(QString,QString)));
    newSt->exec();
}

QString receivedname="";
QString receivedsurn ="";
void MainWindow::receiveData(QString Name,QString Surn){
    if (Name!="" && Surn!=""){
        receivedname=Name;
        receivedsurn=Surn;
    }
    else {receivedname="";
        receivedsurn="";}
}



