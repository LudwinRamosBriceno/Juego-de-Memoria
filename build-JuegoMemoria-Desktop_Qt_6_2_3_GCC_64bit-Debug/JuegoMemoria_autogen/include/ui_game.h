/********************************************************************************
** Form generated from reading UI file 'game.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_H
#define UI_GAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Game
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *buttonInicio;
    QLabel *textInicio;
    QWidget *page_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Game)
    {
        if (Game->objectName().isEmpty())
            Game->setObjectName(QString::fromUtf8("Game"));
        Game->resize(700, 500);
        Game->setMinimumSize(QSize(700, 500));
        Game->setMaximumSize(QSize(700, 522));
        centralwidget = new QWidget(Game);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMinimumSize(QSize(700, 500));
        centralwidget->setMaximumSize(QSize(700, 500));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setEnabled(true);
        stackedWidget->setGeometry(QRect(0, 0, 700, 500));
        QPalette palette;
        stackedWidget->setPalette(palette);
        stackedWidget->setAutoFillBackground(true);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 54);\n"
"background-color: rgb(46, 52, 54);"));
        buttonInicio = new QPushButton(page);
        buttonInicio->setObjectName(QString::fromUtf8("buttonInicio"));
        buttonInicio->setGeometry(QRect(260, 210, 221, 51));
        buttonInicio->setStyleSheet(QString::fromUtf8("color: rgb(186, 189, 182);"));
        textInicio = new QLabel(page);
        textInicio->setObjectName(QString::fromUtf8("textInicio"));
        textInicio->setGeometry(QRect(240, 160, 261, 20));
        textInicio->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);
        Game->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Game);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Game->setStatusBar(statusbar);

        retranslateUi(Game);

        QMetaObject::connectSlotsByName(Game);
    } // setupUi

    void retranslateUi(QMainWindow *Game)
    {
        Game->setWindowTitle(QCoreApplication::translate("Game", "Game", nullptr));
        buttonInicio->setText(QCoreApplication::translate("Game", "COMENZAR", nullptr));
        textInicio->setText(QCoreApplication::translate("Game", "Presiona el bot\303\263n para iniciar el juego", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Game: public Ui_Game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
