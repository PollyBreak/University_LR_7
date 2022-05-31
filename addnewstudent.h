#ifndef ADDNEWSTUDENT_H
#define ADDNEWSTUDENT_H

#include <QDialog>

namespace Ui {
class addNewStudent;
}

class addNewStudent : public QDialog
{
    Q_OBJECT

public:
    explicit addNewStudent(QWidget *parent = nullptr);
    ~addNewStudent();

private:
    Ui::addNewStudent *ui;
};

#endif // ADDNEWSTUDENT_H
