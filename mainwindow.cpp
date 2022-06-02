#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVector>
#include <QString>
#include <QMap>
#include <QMessageBox>

int numOfStudents = 0;
class Student;
class Course;
class Group;
class Faculty;
class Subject;
QVector <Faculty> facs;
QMap <int, Student> allStudents;
QVector <int> delId;
QMap <int, Student> ::iterator it1;
QVector <Faculty> ::iterator it2;
void programAddSt(Student st, QVector <Faculty>& f);


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
    QString patr;
    int course;
    QString group;
    int idGroup;
    QString faculty;
    int idFaculty;
    bool stillStudent = true;
    std::vector <Subject> subs{ Subject("Математический анализ"), Subject("Экономика"), Subject("Физика"), Subject("Иностранный язык") };
    void defaultGrades(){
        subs[0].grade = -1;
        subs[1].grade = -1;
        subs[2].grade = -1;
        subs[3].grade = -1;
    }
    void setGrades(int g1, int g2, int g3, int g4) {
        subs[0].grade = g1; //math grade
        subs[1].grade = g2; //economy grade
        subs[2].grade = g3; //physics grade
        subs[3].grade = g4; // foreign language grade
    }
    void setGrades(int grades[4]) {
        subs[0].grade = grades[0];
        subs[1].grade = grades[1];
        subs[2].grade = grades[2];
        subs[3].grade = grades[3];
    }
    Student() {
        this->id = numOfStudents;
        defaultGrades();
    }
    Student(QString surname, QString name,QString patr, int course, int idFaculty, int idGroup) {
        numOfStudents++;
        this->id = numOfStudents;
        this->name = name;
        this->surname = surname;
        this->patr = patr;
        this->course = course;
        this->idFaculty = idFaculty;
        this->idGroup = idGroup;
        defaultGrades();
        switch (idFaculty) {
        case 0:
            this->faculty = "КБТЭК";
            if (idGroup == 0) {
                group = "KA";
            }
            else {
                group = "КИ";
            }
            break;
        case 1:
            this->faculty = "РНиГМ";
            if (idGroup == 0) {
                group = "РБ";
            }
            else {
                group = "РГ";
            }
            break;
        case 2:
            this->faculty = "ПСиЭСТТ";
            if (idGroup == 0) {
                group = "ТА";
            }
            else {
                group = "ТВ";
            }
            break;
        }
    }
};







MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
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
    ui->tableWidget->setColumnCount(10);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << ""<< "id" << "ФИО" << "Факультет" << "Курс" << "Группа" << "Матан" << "Экономика"<< "Физика"<< "Ин. яз");
    ui->tableWidget->setColumnWidth(0,40);
    ui->tableWidget->setColumnWidth(1,40);
    ui->tableWidget->setColumnWidth(2,400);
    ui->tableWidget->setColumnWidth(3,150);
    ui->tableWidget->setColumnWidth(4,80);
    ui->tableWidget->setColumnWidth(5,80);
    ui->tableWidget->setColumnWidth(6,150);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->hideColumn(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::receiveData(QString Name,QString Surn,QString Patr,int Course,int Fac,int Group){
    Student st(Name, Surn, Patr, Course, Fac, Group);
    programAddSt(st, facs);
}

int grades[4] = {-1,-1,-1,-1};
void MainWindow::recieveGrades(int m,int e,int f,int i){
    grades[0] = m;
    grades[1] = e;
    grades[2] = f;
    grades[3] = i;
    ui->label->setText("QString::number(m)");
}

void MainWindow::on_pushButton_clicked()
{
    newSt = new addingNewStudent();
    connect(newSt,SIGNAL(sendData(QString,QString,QString,int,int,int)),this,SLOT(receiveData(QString,QString,QString,int,int,int)));
    newSt->exec();
    changeTable();
}

void MainWindow::changeTable(){
    //int column=0;
    int row=0;
    for (it1 = allStudents.begin(); it1 != allStudents.end(); it1++) {
                    if (it1.value().stillStudent) {
                        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(it1.value().id)));
                        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(it1.value().surname +" "+it1.value().name+" "+it1.value().patr));
                        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(it1.value().faculty));
                        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(QString::number(it1.value().course+1)));
                        ui->tableWidget->setItem(row, 5, new QTableWidgetItem(it1.value().group));
                        if (it1.value().subs[0].grade != -1) {
                            if (it1.value().subs[0].grade == 0) {
                                ui->tableWidget->setItem(row, 6, new QTableWidgetItem("Н/А"));
                            }
                            else {
                                ui->tableWidget->setItem(row, 6, new QTableWidgetItem(QString::number(it1.value().subs[0].grade+1)));
                            }
                            }
                        if (it1.value().subs[1].grade != -1) {
                            if (it1.value().subs[1].grade == 0) {
                                ui->tableWidget->setItem(row, 7, new QTableWidgetItem("Н/А"));
                            }
                            else {
                                ui->tableWidget->setItem(row, 7, new QTableWidgetItem(QString::number(it1.value().subs[1].grade+1)));
                            }
                            }
                        if (it1.value().subs[2].grade != -1) {
                            if (it1.value().subs[2].grade == 0) {
                                ui->tableWidget->setItem(row, 8, new QTableWidgetItem("Н/А"));
                            }
                            else {
                                ui->tableWidget->setItem(row, 8, new QTableWidgetItem(QString::number(it1.value().subs[2].grade+1)));
                            }
                            }
                        if (it1.value().subs[3].grade != -1) {
                            if (it1.value().subs[3].grade == 0) {
                                ui->tableWidget->setItem(row, 9, new QTableWidgetItem("Н/А"));
                            }
                            else {
                                ui->tableWidget->setItem(row, 9, new QTableWidgetItem(QString::number(it1.value().subs[3].grade+1)));
                            }
                            }
                        row++;
                    }
                }
}

void programAddSt(Student st, QVector <Faculty>& f) {
    allStudents[st.id] = st;
    f[st.idFaculty].students.push_back(st);
    f[st.idFaculty].courses[st.course].students.push_back(st);
    f[st.idFaculty].courses[st.course].groups[st.idGroup].students.push_back(st);
}



void MainWindow::on_pushButton_6_clicked()
{
    //CHECKBOXES  VVV
    //if (ui->pushButton_2->text()=="Удаление учеников"&&ui->tableWidget->rowCount()!=0&&!flag){
    if (ui->pushButton_6->text() == "Отменить") {
        QItemSelectionModel *selectionModel = ui->tableWidget->selectionModel();
        QModelIndexList selectedRows = selectionModel->selectedRows();
        if (selectedRows.size() == 0) {
        ui->pushButton_6->setText("Изменить оценки");
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
        ui->pushButton_4->setEnabled(true);
        ui->pushButton_5->setEnabled(true);
        } else {
            ui->pushButton_6->setText("Изменить оценки");
            int i = ui->tableWidget->currentRow();
            QString currentId = ui->tableWidget->itemAt(i,1)->text();
            uiGrades = new addingGrades();
            connect(uiGrades,SIGNAL(sendGrades(int,int,int,int)),this,SLOT(receiveGrades(int,int,int,int)));
            //connect(uiGrades,SIGNAL(sendGrades(int,int,int,int)),this,SLOT(receiveGrades(int,int,int,int)));
            allStudents[currentId.toInt()].setGrades(grades);
            changeTable();
            ui->pushButton->setEnabled(true);
            ui->pushButton_2->setEnabled(true);
            ui->pushButton_3->setEnabled(true);
            ui->pushButton_4->setEnabled(true);
            ui->pushButton_5->setEnabled(true);
            uiGrades->exec();
        }
    }
    else {
    QMessageBox q1;
    q1.setWindowTitle("Изменение оценок");
    q1.setText("Выберите студента, которому хотите изменить оценки и нажмите на кнопку 'Добавить/изменить оценку' еще раз");
    q1.exec();
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->pushButton_6->setText("Отменить");
    }
    /*ui->tableWidget->showColumn(0);
    bool choseStudents;
    if (ui->pushButton_6->text()=="оценки") {
        ui->pushButton->setEnabled(false);
        for (int i = 0; i<ui->tableWidget->rowCount();i++)
        {
            QTableWidgetItem *check = new QTableWidgetItem();
            check->setData(Qt::CheckStateRole,Qt::Unchecked);
            check->setFlags(check->flags() & ~Qt::ItemIsEditable);
            ui->tableWidget->setItem(i,0,check);
            choseStudents = true;
        }
    }
    if (choseStudents) {

    }
    */

    //}
    //uiGrades = new addingGrades();
    //uiGrades->exec();
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->tableWidget->showColumn(0);
    //if (ui->pushButton_2->text()=="Удаление учеников"&&ui->tableWidget->rowCount()!=0&&!flag){
     //       ui->tableWidget->showColumn(0);
     //   ui->pushButton->setEnabled(false);
    if (ui->pushButton_3->text()== "del") {
        for (int i = 0; i<ui->tableWidget->rowCount();i++)
        {
            QTableWidgetItem *check = new QTableWidgetItem();
            check->setData(Qt::CheckStateRole,Qt::Unchecked);
            check->setFlags(check->flags() & ~Qt::ItemIsEditable);
            ui->tableWidget->setItem(i,0,check);
        }
        ui->pushButton_2->setText("Подтвердить/отменить");
        ui->pushButton->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
        ui->pushButton_4->setEnabled(false);
        ui->pushButton_5->setEnabled(false);
        ui->pushButton_6->setEnabled(false);
    }
    else {
        bool flag = true;
        int countDel=0;
        for (int i = 0;i<ui->tableWidget->rowCount();i++)
        {
            if (ui->tableWidget->item(i,0)->checkState()==Qt::Checked) {
                countDel++;
                allStudents[ui->tableWidget->item(i,1)->text().toInt()].stillStudent = false;
            }
            if (countDel > 0) {

            }

            if (ui->tableWidget->item(i,0)->checkState()==Qt::Checked)
            {
                if (!flag) once = createmsgSignal("Вы действительно хотите удалить выбранных учеников?");
                if (!flag && once  ==  QMessageBox::Ok) flag = true;
                if (flag){
                for (int j=i-deletesCount;j<ui->tableWidget->rowCount()-deletesCount;j++)
                {
                    if(j!=29)
                    groups[currentGroup].students[j]=groups[currentGroup].students[j+1];
                    else
                        groups[currentGroup].students[j]=Student("");
                }
                countDel=0;
                }
            }
        }
        flag = true;

    }


}

