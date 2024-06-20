/********************************************************************************
** Form generated from reading UI file 'treewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TREEWINDOW_H
#define UI_TREEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TreeWindow
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TreeWindow)
    {
        if (TreeWindow->objectName().isEmpty())
            TreeWindow->setObjectName("TreeWindow");
        TreeWindow->resize(800, 600);
        centralwidget = new QWidget(TreeWindow);
        centralwidget->setObjectName("centralwidget");
        TreeWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TreeWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        TreeWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(TreeWindow);
        statusbar->setObjectName("statusbar");
        TreeWindow->setStatusBar(statusbar);

        retranslateUi(TreeWindow);

        QMetaObject::connectSlotsByName(TreeWindow);
    } // setupUi

    void retranslateUi(QMainWindow *TreeWindow)
    {
        TreeWindow->setWindowTitle(QCoreApplication::translate("TreeWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TreeWindow: public Ui_TreeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TREEWINDOW_H
