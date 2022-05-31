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
    void recieveData(QString Name,QString Surn);
signals:
    void sendData(QString name,QString surn);

private:
    Ui::addingNewStudent *ui;
};

#endif // ADDINGNEWSTUDENT_H
