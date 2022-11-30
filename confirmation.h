#ifndef CONFIRMATION_H
#define CONFIRMATION_H

#include <QMainWindow>
#include "Output.h"

namespace Ui {
class Confirmation;
}

class Confirmation : public QMainWindow
{
    Q_OBJECT

public:
    explicit Confirmation(QWidget *parent = nullptr);
    ~Confirmation();

    void ShowInfo();//展示文件
    void Confirm(int choice);//开始确认
private:
    Ui::Confirmation *ui;
    unsigned int point=0;

};
QStringList filein(QString filepath);//读入文件
#endif // CONFIRMATION_H
