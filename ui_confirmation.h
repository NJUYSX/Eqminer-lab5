/********************************************************************************
** Form generated from reading UI file 'confirmation.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIRMATION_H
#define UI_CONFIRMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Confirmation
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLineEdit *Filename1;
    QListWidget *FileContent1;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *Filename2;
    QListWidget *FileContent2;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *EqualBtn;
    QPushButton *DoubtBtn;
    QPushButton *InequalBtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Confirmation)
    {
        if (Confirmation->objectName().isEmpty())
            Confirmation->setObjectName(QStringLiteral("Confirmation"));
        Confirmation->resize(800, 600);
        centralwidget = new QWidget(Confirmation);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 381, 421));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Filename1 = new QLineEdit(widget);
        Filename1->setObjectName(QStringLiteral("Filename1"));

        verticalLayout->addWidget(Filename1);

        FileContent1 = new QListWidget(widget);
        FileContent1->setObjectName(QStringLiteral("FileContent1"));

        verticalLayout->addWidget(FileContent1);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(390, 0, 411, 421));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        Filename2 = new QLineEdit(widget_2);
        Filename2->setObjectName(QStringLiteral("Filename2"));

        verticalLayout_2->addWidget(Filename2);

        FileContent2 = new QListWidget(widget_2);
        FileContent2->setObjectName(QStringLiteral("FileContent2"));

        verticalLayout_2->addWidget(FileContent2);

        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(230, 440, 309, 46));
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        EqualBtn = new QPushButton(widget_3);
        EqualBtn->setObjectName(QStringLiteral("EqualBtn"));

        horizontalLayout->addWidget(EqualBtn);

        DoubtBtn = new QPushButton(widget_3);
        DoubtBtn->setObjectName(QStringLiteral("DoubtBtn"));

        horizontalLayout->addWidget(DoubtBtn);

        InequalBtn = new QPushButton(widget_3);
        InequalBtn->setObjectName(QStringLiteral("InequalBtn"));

        horizontalLayout->addWidget(InequalBtn);

        Confirmation->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Confirmation);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        Confirmation->setMenuBar(menubar);
        statusbar = new QStatusBar(Confirmation);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Confirmation->setStatusBar(statusbar);

        retranslateUi(Confirmation);

        QMetaObject::connectSlotsByName(Confirmation);
    } // setupUi

    void retranslateUi(QMainWindow *Confirmation)
    {
        Confirmation->setWindowTitle(QApplication::translate("Confirmation", "MainWindow", Q_NULLPTR));
        EqualBtn->setText(QApplication::translate("Confirmation", "\347\255\211\344\273\267", Q_NULLPTR));
        DoubtBtn->setText(QApplication::translate("Confirmation", "\345\255\230\347\226\221", Q_NULLPTR));
        InequalBtn->setText(QApplication::translate("Confirmation", "\344\270\215\347\255\211\344\273\267", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Confirmation: public Ui_Confirmation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIRMATION_H
