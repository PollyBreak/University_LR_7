#ifndef ADDINGGRADES_H
#define ADDINGGRADES_H

#include <QDialog>

namespace Ui {
class addingGrades;
}

class addingGrades : public QDialog
{
    Q_OBJECT

public:
    explicit addingGrades(QWidget *parent = nullptr);
    ~addingGrades();
public slots:
    void recieveGrades(int m,int e,int f,int i);
signals:
    void sendGrades(int m,int e,int f,int i);
private slots:
    void on_buttonBox_accepted();

private:
    Ui::addingGrades *ui;
};

#endif // ADDINGGRADES_H
