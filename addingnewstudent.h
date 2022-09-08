#ifndef ADDINGNEWSTUDENT_H
#define ADDINGNEWSTUDENT_H

#include <QDialog>


namespace Ui {
class addingNewStudent;
}

class addingNewStudent : public QDialog
{
    Q_OBJECT

public:
    explicit addingNewStudent(QWidget *parent = nullptr);
    ~addingNewStudent();
public slots:
    void recieveData(QString name,QString surn, QString patr,int fac, int group, int course);
signals:
    void sendData(QString name,QString surn, QString patr,int course, int fac, int group);

private slots:

    void on_comboBox_activated(int index);

    void on_buttonBox_accepted();

private:
    Ui::addingNewStudent *ui;
};

#endif // ADDINGNEWSTUDENT_H
