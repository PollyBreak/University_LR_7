#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <addingnewstudent.h>
#include <addinggrades.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void changeTable();

public slots:
    void receiveData(QString Name,QString Surn, QString Patr,int Course, int Fac, int Group);
    void recieveGrades(int m,int e,int f,int i);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    addingNewStudent *newSt;
    addingGrades *uiGrades;

};
#endif // MAINWINDOW_H
