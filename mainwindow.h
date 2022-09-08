#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <addingnewstudent.h>

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
    void setDefaultButts();

public slots:
    void receiveData(QString Name,QString Surn, QString Patr,int Course, int Fac, int Group);
signals:
    void sendData(QString Name,QString Surn, QString Patr,int Course, int Fac, int Group);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    addingNewStudent *newSt;

};
#endif // MAINWINDOW_H
