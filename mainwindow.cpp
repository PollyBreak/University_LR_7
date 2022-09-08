#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVector>
#include <QString>
#include <QMap>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

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
        subs[0].grade = 1;
        subs[1].grade = 1;
        subs[2].grade = 1;
        subs[3].grade = 1;
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
        //ui->comboBox->setEnabled(false);
       // ui->comboBox_2->setEnabled(false);
       // ui->comboBox_3->setEnabled(false);
       // ui->comboBox_4->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->lineEdit->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setDefaultButts() {
    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_2->setText("Изменить информацию о студенте");
    ui->pushButton_3->setEnabled(true);
    ui->pushButton_3->setText("Удалить студента");
    ui->pushButton_4->setEnabled(true);
    ui->pushButton_7->setEnabled(true);
    ui->pushButton_7->setText("Отчислить студента");
    ui->pushButton_6->setEnabled(true);
    ui->pushButton_6->setText("Изменение/добавление оценок");
    ui->pushButton_5->setEnabled(false);

    ui->lineEdit->setText("");
    ui->lineEdit->setEnabled(false);
}

void MainWindow::receiveData(QString Name,QString Surn,QString Patr,int Course,int Fac,int Group){
    Student st(Name, Surn, Patr, Course, Fac, Group);
    programAddSt(st, facs);
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
                        if (it1.value().subs[0].grade != 1) {
                                ui->tableWidget->setItem(row, 6, new QTableWidgetItem(QString::number(it1.value().subs[0].grade)));
                            }
                        if (it1.value().subs[1].grade != 1) {
                                ui->tableWidget->setItem(row, 7, new QTableWidgetItem(QString::number(it1.value().subs[1].grade)));
                            }
                        if (it1.value().subs[2].grade != 1) {
                                ui->tableWidget->setItem(row, 8, new QTableWidgetItem(QString::number(it1.value().subs[2].grade)));
                            }
                        if (it1.value().subs[3].grade != 1) {
                                ui->tableWidget->setItem(row, 9, new QTableWidgetItem(QString::number(it1.value().subs[3].grade)));
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
    if (ui->pushButton_6->text() != "Подтвердить") {
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_7->setEnabled(false);
    QMessageBox q1;
    q1.setWindowTitle("Добавление оценок");
    q1.setText("Для добавления оценок введите ID студента в строку внизу, справа выберите оценки и затем нажмите на кнопку подтвердить, в противном случае нажмите отменить");
    q1.exec();
    ui->lineEdit->setEnabled(true);
    ui->pushButton_5->setEnabled(true);
    ui->pushButton_6->setText("Подтвердить");
    }
    else {
        QString line = ui->lineEdit->text().trimmed();
        bool ok;
        int curId = line.toInt(&ok);
        if (!ok) {
            QMessageBox q2;
            q2.setWindowTitle("Ошибка");
            q2.setText("В ID не может быть букв или символов!");
            q2.exec();
            setDefaultButts();
        } else {
            bool find;
            for (it1 = allStudents.begin(); it1 != allStudents.end(); it1++) {
                if (it1.key() == curId) {
                    if (allStudents[curId].stillStudent) {
                        allStudents[curId].setGrades(ui->comboBox->currentIndex()+2,ui->comboBox_2->currentIndex()+2,ui->comboBox_3->currentIndex()+2,ui->comboBox_4->currentIndex()+2);
                        find = true;
                    }
                }
            }
            if (!find) {
                QMessageBox q2;
                q2.setWindowTitle("Ошибка");
                q2.setText("Студента с таким ID не существует");
                q2.exec();
                setDefaultButts();
            } else {
                ui->tableWidget->clearContents();
                changeTable();
                setDefaultButts();
                ui->comboBox->setCurrentIndex(-1);
                ui->comboBox_2->setCurrentIndex(-1);
                ui->comboBox_3->setCurrentIndex(-1);
                ui->comboBox_4->setCurrentIndex(-1);
                }
        }
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    if (ui->pushButton_3->text() != "Подтвердить") {
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_7->setEnabled(false);
    QMessageBox q1;
    q1.setWindowTitle("Удаление");
    q1.setText("Для удаления студента введите его ID в строку внизу и нажмите на кнопку подтвердить, в противном случае нажмите отменить");
    q1.exec();
    ui->lineEdit->setEnabled(true);
    ui->pushButton_5->setEnabled(true);
    ui->pushButton_3->setText("Подтвердить");
    }
    else {
        QString line = ui->lineEdit->text().trimmed();
        bool ok;
        int curId = line.toInt(&ok);
        if (!ok) {
            QMessageBox q2;
            q2.setWindowTitle("Ошибка");
            q2.setText("В ID не может быть букв или символов!");
            q2.exec();
            setDefaultButts();
        } else {
            bool find;
            for (it1 = allStudents.begin(); it1 != allStudents.end(); it1++) {
                if (it1.key() == curId) {
                    if (allStudents[curId].stillStudent) {
                        allStudents[curId].stillStudent = false;
                        find = true;
                    }
                }
            }
            if (!find) {
                QMessageBox q2;
                q2.setWindowTitle("Ошибка");
                q2.setText("Студента с таким ID не существует");
                q2.exec();
                setDefaultButts();
            } else {
                ui->tableWidget->clearContents();
                changeTable();
                setDefaultButts();
                }
        }
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    if (ui->pushButton_2->text() != "Перейти к окну изменения студента") {
    ui->pushButton->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_7->setEnabled(false);
    QMessageBox q1;
    q1.setWindowTitle("Изменение данных");
    q1.setText("Для изменения студента введите его ID в строку внизу и нажмите на кнопку подтвердить, в противном случае нажмите отменить");
    q1.exec();
    ui->lineEdit->setEnabled(true);
    ui->pushButton_5->setEnabled(true);
    ui->pushButton_2->setText("Перейти к окну изменения студента");
    }
    else {
        QString line = ui->lineEdit->text().trimmed();
        bool ok;
        int curId = line.toInt(&ok);
        if (!ok) {
            QMessageBox q2;
            q2.setWindowTitle("Ошибка");
            q2.setText("В ID не может быть букв или символов!");
            q2.exec();
            setDefaultButts();
        } else {
            bool find;
            for (it1 = allStudents.begin(); it1 != allStudents.end(); it1++) {
                if (it1.key() == curId) {
                    if (allStudents[curId].stillStudent) {
                        newSt = new addingNewStudent();
                        connect(newSt,SIGNAL(sendData(QString,QString,QString,int,int,int)),this,SLOT(receiveData(QString,QString,QString,int,int,int)));
                        connect(this,SIGNAL(sendData(QString,QString,QString,int,int,int)),newSt,SLOT(receiveData(QQString,QString,QString,int,int,int)));
                        emit sendData(allStudents[curId].name,allStudents[curId].surname,allStudents[curId].patr,allStudents[curId].idFaculty,allStudents[curId].course,allStudents[curId].idGroup);
                        newSt->exec();
                        allStudents[curId] = allStudents[allStudents.lastKey()];
                        allStudents[curId].id = curId;
                        allStudents[curId].stillStudent = false;
                        find = true;
                    }
                }
            }
            if (!find) {
                QMessageBox q2;
                q2.setWindowTitle("Ошибка");
                q2.setText("Студента с таким ID не существует");
                q2.exec();
                setDefaultButts();
            } else {
                ui->tableWidget->clearContents();
                changeTable();
                setDefaultButts();
                }
        }
    }
}


void MainWindow::on_pushButton_5_clicked()
{
    setDefaultButts();
}


void MainWindow::on_pushButton_7_clicked()
{
    if (ui->pushButton_7->text() != "Подтвердить") {
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    QMessageBox q1;
    q1.setWindowTitle("Отчисление");
    q1.setText("Для отчисления студента введите его ID в строку внизу и нажмите на кнопку подтвердить, в противном случае нажмите отменить");
    q1.exec();
    ui->lineEdit->setEnabled(true);
    ui->pushButton_5->setEnabled(true);
    ui->pushButton_7->setText("Подтвердить");
    }
    else {
        QString line = ui->lineEdit->text().trimmed();
        bool ok;
        int curId = line.toInt(&ok);
        if (!ok) {
            QMessageBox q2;
            q2.setWindowTitle("Ошибка");
            q2.setText("В ID не может быть букв или символов!");
            q2.exec();
            setDefaultButts();
        } else {
            bool find;
            for (it1 = allStudents.begin(); it1 != allStudents.end(); it1++) {
                if (it1.key() == curId) {
                    if (allStudents[curId].stillStudent) {
                        allStudents[curId].stillStudent = false;
                        facs[it1.value().idFaculty].deadStudents.push_back(it1.value());
                        facs[it1.value().idFaculty].courses[it1.value().course].deadStudents.push_back(it1.value());
                        facs[it1.value().idFaculty].courses[it1.value().course].groups[it1.value().idGroup].students.push_back(it1.value());
                        find = true;
                    }
                }
            }
            if (!find) {
                QMessageBox q2;
                q2.setWindowTitle("Ошибка");
                q2.setText("Студента с таким ID не существует");
                q2.exec();
                setDefaultButts();
            } else {
                ui->tableWidget->clearContents();
                changeTable();
                setDefaultButts();
                }
        }
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    QFile file("CourseMostDismissedStudents.txt");
    file.open(QIODevice::WriteOnly |  QIODevice::Text);
    QTextStream in(&file);
    int max = 0;
        int dismis[4] = { 0,0,0,0 };
        int k = 0;
        std::string numbers;

        for (int i = 0; i < 4; i++) {
            for (it2 = facs.begin(); it2 != facs.end(); it2++) {
                dismis[i] += it2->courses[i].deadStudents.size();
            }
        }
        for (int i = 0; i < 4; i++) {
            if (dismis[i] > max) {
                max = dismis[i];
            }
        }
        if (max == 0) {
                in << "Otchislennyh studentov net";
            }
            else {
                for (int i = 0; i < 4; i++) {
                    if (dismis[i] == max) {
                        k++;
                        if (k == 1) {
                            numbers = std::to_string(i+1);
                            }
                        else {
                            numbers += ", ";
                            numbers += std::to_string(i+1);
                        }
                    }
                }
            numbers += ".";
            QString amount = QString::fromStdString(numbers);
                if (k == 1) {
                    in << "Kurs, na kotorom otchisleno bolshee kolichestvo studentov: "<< amount  ;
                }
                else {
                    in << "Kursy, na kotoryh otchisleno bolshee kolichestvo studentov: " << amount;
                }
            }
            file.close();
}

