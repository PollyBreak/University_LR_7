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

public slots:
    void receiveData(QString Name,QString Surn);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    addingNewStudent *newSt;

};
#endif // MAINWINDOW_H
