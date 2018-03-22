/********************************************************************************
** Form generated from reading UI file 'Butterfly.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUTTERFLY_H
#define UI_BUTTERFLY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ButterflyClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ButterflyClass)
    {
        if (ButterflyClass->objectName().isEmpty())
            ButterflyClass->setObjectName(QStringLiteral("ButterflyClass"));
        ButterflyClass->resize(600, 400);
        menuBar = new QMenuBar(ButterflyClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        ButterflyClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ButterflyClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ButterflyClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(ButterflyClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ButterflyClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ButterflyClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ButterflyClass->setStatusBar(statusBar);

        retranslateUi(ButterflyClass);

        QMetaObject::connectSlotsByName(ButterflyClass);
    } // setupUi

    void retranslateUi(QMainWindow *ButterflyClass)
    {
        ButterflyClass->setWindowTitle(QApplication::translate("ButterflyClass", "Butterfly", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ButterflyClass: public Ui_ButterflyClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUTTERFLY_H
