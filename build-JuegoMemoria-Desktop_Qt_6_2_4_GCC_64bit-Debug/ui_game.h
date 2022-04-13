/********************************************************************************
** Form generated from reading UI file 'game.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_H
#define UI_GAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Game
{
public:
    QWidget *centralwidget;
    QStackedWidget *pantallas;
    QWidget *pantalla_1;
    QPushButton *buttonComenzar;
    QLabel *tituloInicial;
    QLineEdit *textJugador2;
    QLineEdit *textJugador1;
    QLabel *tituloJugador1;
    QLabel *tituloJugador2;
    QLabel *AvisoCaracteres;
    QWidget *pantalla_2;
    QWidget *tablero;
    QGridLayout *gridLayout;
    QPushButton *button33;
    QPushButton *button16;
    QPushButton *button30;
    QPushButton *button25;
    QPushButton *button24;
    QPushButton *button20;
    QPushButton *button22;
    QPushButton *button4;
    QPushButton *button15;
    QPushButton *button31;
    QPushButton *button32;
    QPushButton *button17;
    QPushButton *button1;
    QPushButton *button5;
    QPushButton *button12;
    QPushButton *button18;
    QPushButton *button27;
    QPushButton *button9;
    QPushButton *button35;
    QPushButton *button23;
    QPushButton *button10;
    QPushButton *button34;
    QPushButton *button6;
    QPushButton *button7;
    QPushButton *button14;
    QPushButton *button2;
    QPushButton *button36;
    QPushButton *button11;
    QPushButton *button13;
    QPushButton *button3;
    QPushButton *button21;
    QPushButton *button26;
    QPushButton *button29;
    QPushButton *button8;
    QPushButton *button19;
    QPushButton *button28;
    QLabel *puntajePJugador1;
    QLabel *namePJugador1;
    QLabel *namePJugador2;
    QLabel *puntajePJugador2;
    QLabel *AvisosPjuego;

    void setupUi(QMainWindow *Game)
    {
        if (Game->objectName().isEmpty())
            Game->setObjectName(QString::fromUtf8("Game"));
        Game->resize(800, 500);
        Game->setMinimumSize(QSize(800, 500));
        Game->setMaximumSize(QSize(800, 500));
        centralwidget = new QWidget(Game);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMinimumSize(QSize(800, 500));
        centralwidget->setMaximumSize(QSize(800, 500));
        pantallas = new QStackedWidget(centralwidget);
        pantallas->setObjectName(QString::fromUtf8("pantallas"));
        pantallas->setGeometry(QRect(0, 0, 800, 500));
        pantalla_1 = new QWidget();
        pantalla_1->setObjectName(QString::fromUtf8("pantalla_1"));
        pantalla_1->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 54);"));
        buttonComenzar = new QPushButton(pantalla_1);
        buttonComenzar->setObjectName(QString::fromUtf8("buttonComenzar"));
        buttonComenzar->setGeometry(QRect(330, 320, 171, 51));
        buttonComenzar->setStyleSheet(QString::fromUtf8("background-color: rgb(193, 125, 17);"));
        tituloInicial = new QLabel(pantalla_1);
        tituloInicial->setObjectName(QString::fromUtf8("tituloInicial"));
        tituloInicial->setGeometry(QRect(300, 70, 231, 31));
        tituloInicial->setStyleSheet(QString::fromUtf8("font: 700 italic 14pt \"Ubuntu\";\n"
"color: rgb(211, 215, 207);"));
        textJugador2 = new QLineEdit(pantalla_1);
        textJugador2->setObjectName(QString::fromUtf8("textJugador2"));
        textJugador2->setGeometry(QRect(280, 150, 271, 25));
        textJugador1 = new QLineEdit(pantalla_1);
        textJugador1->setObjectName(QString::fromUtf8("textJugador1"));
        textJugador1->setGeometry(QRect(280, 240, 271, 25));
        tituloJugador1 = new QLabel(pantalla_1);
        tituloJugador1->setObjectName(QString::fromUtf8("tituloJugador1"));
        tituloJugador1->setGeometry(QRect(340, 120, 161, 17));
        tituloJugador2 = new QLabel(pantalla_1);
        tituloJugador2->setObjectName(QString::fromUtf8("tituloJugador2"));
        tituloJugador2->setGeometry(QRect(340, 210, 161, 17));
        AvisoCaracteres = new QLabel(pantalla_1);
        AvisoCaracteres->setObjectName(QString::fromUtf8("AvisoCaracteres"));
        AvisoCaracteres->setGeometry(QRect(310, 280, 201, 21));
        AvisoCaracteres->setAlignment(Qt::AlignCenter);
        pantallas->addWidget(pantalla_1);
        pantalla_2 = new QWidget();
        pantalla_2->setObjectName(QString::fromUtf8("pantalla_2"));
        pantalla_2->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 54);"));
        tablero = new QWidget(pantalla_2);
        tablero->setObjectName(QString::fromUtf8("tablero"));
        tablero->setGeometry(QRect(80, 80, 661, 411));
        gridLayout = new QGridLayout(tablero);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        button33 = new QPushButton(tablero);
        button33->setObjectName(QString::fromUtf8("button33"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(button33->sizePolicy().hasHeightForWidth());
        button33->setSizePolicy(sizePolicy);
        button33->setStyleSheet(QString::fromUtf8("image: url(:/Img_espalda.png);\n"
"border: 4px solid gray;\n"
"border-radius: 8px;"));

        gridLayout->addWidget(button33, 5, 2, 1, 1);

        button16 = new QPushButton(tablero);
        button16->setObjectName(QString::fromUtf8("button16"));
        sizePolicy.setHeightForWidth(button16->sizePolicy().hasHeightForWidth());
        button16->setSizePolicy(sizePolicy);
        button16->setStyleSheet(QString::fromUtf8("image: url(:/Img_espalda.png);\n"
"border: 4px solid gray;\n"
"border-radius: 8px;"));

        gridLayout->addWidget(button16, 2, 3, 1, 1);

        button30 = new QPushButton(tablero);
        button30->setObjectName(QString::fromUtf8("button30"));
        sizePolicy.setHeightForWidth(button30->sizePolicy().hasHeightForWidth());
        button30->setSizePolicy(sizePolicy);
        button30->setStyleSheet(QString::fromUtf8("image: url(:/Img_espalda.png);\n"
"border: 4px solid gray;\n"
"border-radius: 8px;"));

        gridLayout->addWidget(button30, 4, 5, 1, 1);

        button25 = new QPushButton(tablero);
        button25->setObjectName(QString::fromUtf8("button25"));
        sizePolicy.setHeightForWidth(button25->sizePolicy().hasHeightForWidth());
        button25->setSizePolicy(sizePolicy);
        button25->setStyleSheet(QString::fromUtf8("image: url(:/Img_espalda.png);\n"
"border: 4px solid gray;\n"
"border-radius: 8px;"));

        gridLayout->addWidget(button25, 4, 0, 1, 1);

        button24 = new QPushButton(tablero);
        button24->setObjectName(QString::fromUtf8("button24"));
        sizePolicy.setHeightForWidth(button24->sizePolicy().hasHeightForWidth());
        button24->setSizePolicy(sizePolicy);
        button24->setStyleSheet(QString::fromUtf8("image: url(:/Img_espalda.png);\n"
"border: 4px solid gray;\n"
"border-radius: 8px;"));

        gridLayout->addWidget(button24, 3, 5, 1, 1);

        button20 = new QPushButton(tablero);
        button20->setObjectName(QString::fromUtf8("button20"));
        sizePolicy.setHeightForWidth(button20->sizePolicy().hasHeightForWidth());
        button20->setSizePolicy(sizePolicy);
        button20->setStyleSheet(QString::fromUtf8("image: url(:/Img_espalda.png);\n"
"border: 4px solid gray;\n"
"border-radius: 8px;"));

        gridLayout->addWidget(button20, 3, 1, 1, 1);

        button22 = new QPushButton(tablero);
        button22->setObjectName(QString::fromUtf8("button22"));
        sizePolicy.setHeightForWidth(button22->sizePolicy().hasHeightForWidth());
        button22->setSizePolicy(sizePolicy);
        button22->setStyleSheet(QString::fromUtf8("image: url(:/Img_espalda.png);\n"
"border: 4px solid gray;\n"
"border-radius: 8px;"));

        gridLayout->addWidget(button22, 3, 3, 1, 1);

        button4 = new QPushButton(tablero);
        button4->setObjectName(QString::fromUtf8("button4"));
        sizePolicy.setHeightForWidth(button4->sizePolicy().hasHeightForWidth());
        button4->setSizePolicy(sizePolicy);
        button4->setStyleSheet(QString::fromUtf8("image: url(:/Img_espalda.png);\n"
"border: 4px solid gray;\n"
"border-radius: 8px;"));

        gridLayout->addWidget(button4, 0, 3, 1, 1);

        button15 = new QPushButton(tablero);
        button15->setObjectName(QString::fromUtf8("button15"));
        sizePolicy.setHeightForWidth(button15->sizePolicy().hasHeightForWidth());
        button15->setSizePolicy(sizePolicy);
        button15->setStyleSheet(QString::fromUtf8("image: url(:/Img_espalda.png);\n"
"border: 4px solid gray;\n"
"border-radius: 8px;"));

        gridLayout->addWidget(button15, 2, 2, 1, 1);

        button31 = new QPushButton(tablero);
        button31->setObjectName(QString::fromUtf8("button31"));
        sizePolicy.setHeightForWidth(button31->sizePolicy().hasHeightForWidth());
        button31->setSizePolicy(sizePolicy);
        button31->setStyleSheet(QString::fromUtf8("image: url(:/Img_espalda.png);\n"
"border: 4px solid gray;\n"
"border-radius: 8px;"));

        gridLayout->addWidget(button31, 5, 0, 1, 1);

        button32 = new QPushButton(tablero);
        button32->setObjectName(QString::fromUtf8("button32"));
        sizePolicy.setHeightForWidth(button32->sizePolicy().hasHeightForWidth());
        button32->setSizePolicy(sizePolicy);
        button32->setStyleSheet(QString::fromUtf8("image: url(:/Img_espalda.png);\n"
"border: 4px solid gray;\n"
"border-radius: 8px;"));

        gridLayout->addWidget(button32, 5, 1, 1, 1);

        button17 = new QPushButton(tablero);
        button17->setObjectName(QString::fromUtf8("button17"));
        sizePolicy.setHeightForWidth(button17->sizePolicy().hasHeightForWidth());
        button17->setSizePolicy(sizePolicy);
        button17->setStyleSheet(QString::fromUtf8("image: url(:/Img_espalda.png);\n"
"border: 4px solid gray;\n"
"border-radius: 8px;"));

        gridLayout->addWidget(button17, 2, 4, 1, 1);

        button1 = new QPushButton(tablero);
        button1->setObjectName(QString::fromUtf8("button1"));
        sizePolicy.setHeightForWidth(button1->sizePolicy().hasHeightForWidth());
        button1->setSizePolicy(sizePolicy);
        button1->setStyleSheet(QString::fromUtf8("image: url(:/Img_espalda.png);\n"
"border: 4px solid gray;\n"
"border-radius: 8px;"));

        gridLayout->addWidget(button1, 0, 0, 1, 1);

        button5 = new QPushButton(tablero);
        button5->setObjectName(QString::fromUtf8("button5"));
        sizePolicy.setHeightForWidth(button5->sizePolicy().hasHeightForWidth());
        button5->setSizePolicy(sizePolicy);
        button5->setStyleSheet(QString::fromUtf8("image: url(:/Img_espalda.png);\n"
"border: 4px solid gray;\n"
"border-radius: 8px;"));

        gridLayout->addWidget(button5, 0, 4, 1, 1);

        button12 = new QPushButton(tablero);
        button12->setObjectName(QString::fromUtf8("button12"));
        sizePolicy.setHeightForWidth(button12->sizePolicy().hasHeightForWidth());
        button12->setSizePolicy(sizePolicy);
        button12->setStyleSheet(QString::fromUtf8("image: url(:/Img_espalda.png);\n"
"border: 4px solid gray;\n"
"border-radius: 8px;"));

        gridLayout->addWidget(button12, 1, 5, 1, 1);

        button18 = new QPushButton(tablero);
        button18->setObjectName(QString::fromUtf8("button18"));
        sizePolicy.setHeightForWidth(button18->sizePolicy().hasHeightForWidth());
        button18->setSizePolicy(sizePolicy);
        button18->setStyleSheet(QString::fromUtf8("image: url(:/Img_espalda.png);\n"
"border: 4px solid gray;\n"
"border-radius: 8px;"));

        gridLayout->addWidget(button18, 2, 5, 1, 1);

        button27 = new QPushButton(tablero);
        button27->setObjectName(QString::fromUtf8("button27"));
        sizePolicy.setHeightForWidth(button27->sizePolicy().hasHeightForWidth());
        button27->setSizePolicy(sizePolicy);
        button27->setStyleSheet(QString::fromUtf8("image: url(:/Img_espalda.png);\n"
"border: 4px solid gray;\n"
"border-radius: 8px;"));

        gridLayout->addWidget(button27, 4, 2, 1, 1);

        button9 = new QPushButton(tablero);
        button9->setObjectName(QString::fromUtf8("button9"));
        sizePolicy.setHeightForWidth(button9->sizePolicy().hasHeightForWidth());
        button9->setSizePolicy(sizePolicy);
        button9->setStyleSheet(QString::fromUtf8("image: url(:/Img_espalda.png);\n"
"border: 4px solid gray;\n"
"border-radius: 8px;"));

        gridLayout->addWidget(button9, 1, 2, 1, 1);

        button35 = new QPushButton(tablero);
        button35->setObjectName(QString::fromUtf8("button35"));
        sizePolicy.setHeightForWidth(button35->sizePolicy().hasHeightForWidth());
        button35->setSizePolicy(sizePolicy);
        button35->setStyleSheet(QString::fromUtf8("image: url(:/Img_espalda.png);\n"
"border: 4px solid gray;\n"
"border-radius: 8px;"));

        gridLayout->addWidget(button35, 5, 4, 1, 1);

        button23 = new QPushButton(tablero);
        button23->setObjectName(QString::fromUtf8("button23"));
        sizePolicy.setHeightForWidth(button23->sizePolicy().hasHeightForWidth());
        button23->setSizePolicy(sizePolicy);
        button23->setStyleSheet(QString::fromUtf8("image: url(:/Img_espalda.png);\n"
"border: 4px solid gray;\n"
"border-radius: 8px;"));

        gridLayout->addWidget(button23, 3, 4, 1, 1);

        button10 = new QPushButton(tablero);
        button10->setObjectName(QString::fromUtf8("button10"));
        sizePolicy.setHeightForWidth(button10->sizePolicy().hasHeightForWidth());
        button10->setSizePolicy(sizePolicy);
        button10->setStyleSheet(QString::fromUtf8("image: url(:/Img_espalda.png);\n"
"border: 4px solid gray;\n"
"border-radius: 8px;"));

        gridLayout->addWidget(button10, 1, 3, 1, 1);

        button34 = new QPushButton(tablero);
        button34->setObjectName(QString::fromUtf8("button34"));
        sizePolicy.setHeightForWidth(button34->sizePolicy().hasHeightForWidth());
        button34->setSizePolicy(sizePolicy);
        button34->setStyleSheet(QString::fromUtf8("image: url(:/Img_espalda.png);\n"
"border: 4px solid gray;\n"
"border-radius: 8px;"));

        gridLayout->addWidget(button34, 5, 3, 1, 1);

        button6 = new QPushButton(tablero);
        button6->setObjectName(QString::fromUtf8("button6"));
        sizePolicy.setHeightForWidth(button6->sizePolicy().hasHeightForWidth());
        button6->setSizePolicy(sizePolicy);
        button6->setStyleSheet(QString::fromUtf8("image: url(:/Img_espalda.png);\n"
"border: 4px solid gray;\n"
"border-radius: 8px;"));

        gridLayout->addWidget(button6, 0, 5, 1, 1);

        button7 = new QPushButton(tablero);
        button7->setObjectName(QString::fromUtf8("button7"));
        sizePolicy.setHeightForWidth(button7->sizePolicy().hasHeightForWidth());
        button7->setSizePolicy(sizePolicy);
        button7->setStyleSheet(QString::fromUtf8("image: url(:/Img_espalda.png);\n"
"border: 4px solid gray;\n"
"border-radius: 8px;"));

        gridLayout->addWidget(button7, 1, 0, 1, 1);

        button14 = new QPushButton(tablero);
        button14->setObjectName(QString::fromUtf8("button14"));
        sizePolicy.setHeightForWidth(button14->sizePolicy().hasHeightForWidth());
        button14->setSizePolicy(sizePolicy);
        button14->setStyleSheet(QString::fromUtf8("image: url(:/Img_espalda.png);\n"
"border: 4px solid gray;\n"
"border-radius: 8px;"));

        gridLayout->addWidget(button14, 2, 1, 1, 1);

        button2 = new QPushButton(tablero);
        button2->setObjectName(QString::fromUtf8("button2"));
        sizePolicy.setHeightForWidth(button2->sizePolicy().hasHeightForWidth());
        button2->setSizePolicy(sizePolicy);
        button2->setStyleSheet(QString::fromUtf8("image: url(:/Img_espalda.png);\n"
"border: 4px solid gray;\n"
"border-radius: 8px;"));

        gridLayout->addWidget(button2, 0, 1, 1, 1);

        button36 = new QPushButton(tablero);
        button36->setObjectName(QString::fromUtf8("button36"));
        sizePolicy.setHeightForWidth(button36->sizePolicy().hasHeightForWidth());
        button36->setSizePolicy(sizePolicy);
        button36->setAutoFillBackground(false);
        button36->setStyleSheet(QString::fromUtf8("image: url(:/Img_espalda.png);\n"
"border: 4px solid gray;\n"
"border-radius: 8px;"));

        gridLayout->addWidget(button36, 5, 5, 1, 1);

        button11 = new QPushButton(tablero);
        button11->setObjectName(QString::fromUtf8("button11"));
        sizePolicy.setHeightForWidth(button11->sizePolicy().hasHeightForWidth());
        button11->setSizePolicy(sizePolicy);
        button11->setStyleSheet(QString::fromUtf8("image: url(:/Img_espalda.png);\n"
"border: 4px solid gray;\n"
"border-radius: 8px;"));

        gridLayout->addWidget(button11, 1, 4, 1, 1);

        button13 = new QPushButton(tablero);
        button13->setObjectName(QString::fromUtf8("button13"));
        sizePolicy.setHeightForWidth(button13->sizePolicy().hasHeightForWidth());
        button13->setSizePolicy(sizePolicy);
        button13->setStyleSheet(QString::fromUtf8("image: url(:/Img_espalda.png);\n"
"border: 4px solid gray;\n"
"border-radius: 8px;"));

        gridLayout->addWidget(button13, 2, 0, 1, 1);

        button3 = new QPushButton(tablero);
        button3->setObjectName(QString::fromUtf8("button3"));
        sizePolicy.setHeightForWidth(button3->sizePolicy().hasHeightForWidth());
        button3->setSizePolicy(sizePolicy);
        button3->setStyleSheet(QString::fromUtf8("image: url(:/Img_espalda.png);\n"
"border: 4px solid gray;\n"
"border-radius: 8px;"));

        gridLayout->addWidget(button3, 0, 2, 1, 1);

        button21 = new QPushButton(tablero);
        button21->setObjectName(QString::fromUtf8("button21"));
        sizePolicy.setHeightForWidth(button21->sizePolicy().hasHeightForWidth());
        button21->setSizePolicy(sizePolicy);
        button21->setStyleSheet(QString::fromUtf8("image: url(:/Img_espalda.png);\n"
"border: 4px solid gray;\n"
"border-radius: 8px;"));

        gridLayout->addWidget(button21, 3, 2, 1, 1);

        button26 = new QPushButton(tablero);
        button26->setObjectName(QString::fromUtf8("button26"));
        sizePolicy.setHeightForWidth(button26->sizePolicy().hasHeightForWidth());
        button26->setSizePolicy(sizePolicy);
        button26->setStyleSheet(QString::fromUtf8("image: url(:/Img_espalda.png);\n"
"border: 4px solid gray;\n"
"border-radius: 8px;"));

        gridLayout->addWidget(button26, 4, 1, 1, 1);

        button29 = new QPushButton(tablero);
        button29->setObjectName(QString::fromUtf8("button29"));
        sizePolicy.setHeightForWidth(button29->sizePolicy().hasHeightForWidth());
        button29->setSizePolicy(sizePolicy);
        button29->setStyleSheet(QString::fromUtf8("image: url(:/Img_espalda.png);\n"
"border: 4px solid gray;\n"
"border-radius: 8px;"));

        gridLayout->addWidget(button29, 4, 4, 1, 1);

        button8 = new QPushButton(tablero);
        button8->setObjectName(QString::fromUtf8("button8"));
        sizePolicy.setHeightForWidth(button8->sizePolicy().hasHeightForWidth());
        button8->setSizePolicy(sizePolicy);
        button8->setStyleSheet(QString::fromUtf8("image: url(:/Img_espalda.png);\n"
"border: 4px solid gray;\n"
"border-radius: 8px;"));

        gridLayout->addWidget(button8, 1, 1, 1, 1);

        button19 = new QPushButton(tablero);
        button19->setObjectName(QString::fromUtf8("button19"));
        sizePolicy.setHeightForWidth(button19->sizePolicy().hasHeightForWidth());
        button19->setSizePolicy(sizePolicy);
        button19->setStyleSheet(QString::fromUtf8("image: url(:/Img_espalda.png);\n"
"border: 4px solid gray;\n"
"border-radius: 8px;"));

        gridLayout->addWidget(button19, 3, 0, 1, 1);

        button28 = new QPushButton(tablero);
        button28->setObjectName(QString::fromUtf8("button28"));
        sizePolicy.setHeightForWidth(button28->sizePolicy().hasHeightForWidth());
        button28->setSizePolicy(sizePolicy);
        button28->setStyleSheet(QString::fromUtf8("image: url(:/Img_espalda.png);\n"
"border: 4px solid gray;\n"
"border-radius: 8px;"));

        gridLayout->addWidget(button28, 4, 3, 1, 1);

        puntajePJugador1 = new QLabel(pantalla_2);
        puntajePJugador1->setObjectName(QString::fromUtf8("puntajePJugador1"));
        puntajePJugador1->setGeometry(QRect(190, 50, 101, 31));
        puntajePJugador1->setStyleSheet(QString::fromUtf8("background: teal;\n"
"border: 3px solid white; \n"
"border-radius: 7px;"));
        namePJugador1 = new QLabel(pantalla_2);
        namePJugador1->setObjectName(QString::fromUtf8("namePJugador1"));
        namePJugador1->setGeometry(QRect(190, 20, 101, 17));
        namePJugador1->setStyleSheet(QString::fromUtf8("font: 700 italic 12pt \"Ubuntu\";"));
        namePJugador2 = new QLabel(pantalla_2);
        namePJugador2->setObjectName(QString::fromUtf8("namePJugador2"));
        namePJugador2->setGeometry(QRect(540, 20, 91, 17));
        puntajePJugador2 = new QLabel(pantalla_2);
        puntajePJugador2->setObjectName(QString::fromUtf8("puntajePJugador2"));
        puntajePJugador2->setGeometry(QRect(540, 50, 91, 31));
        puntajePJugador2->setStyleSheet(QString::fromUtf8("background: teal;\n"
"border: 3px solid white; \n"
"border-radius: 7px;"));
        AvisosPjuego = new QLabel(pantalla_2);
        AvisosPjuego->setObjectName(QString::fromUtf8("AvisosPjuego"));
        AvisosPjuego->setGeometry(QRect(380, 50, 67, 17));
        pantallas->addWidget(pantalla_2);
        Game->setCentralWidget(centralwidget);

        retranslateUi(Game);

        QMetaObject::connectSlotsByName(Game);
    } // setupUi

    void retranslateUi(QMainWindow *Game)
    {
        Game->setWindowTitle(QCoreApplication::translate("Game", "Game", nullptr));
        buttonComenzar->setText(QCoreApplication::translate("Game", "COMENZAR", nullptr));
        tituloInicial->setText(QCoreApplication::translate("Game", "Nombre de los Jugadores", nullptr));
        tituloJugador1->setText(QCoreApplication::translate("Game", "Nombre del Jugador 1", nullptr));
        tituloJugador2->setText(QCoreApplication::translate("Game", "Nombre del Jugador 2", nullptr));
        AvisoCaracteres->setText(QCoreApplication::translate("Game", "Aviso: m\303\241ximo 10 caracteres", nullptr));
        button33->setText(QString());
        button16->setText(QString());
        button30->setText(QString());
        button25->setText(QString());
        button24->setText(QString());
        button20->setText(QString());
        button22->setText(QString());
        button4->setText(QString());
        button15->setText(QString());
        button31->setText(QString());
        button32->setText(QString());
        button17->setText(QString());
        button1->setText(QString());
        button5->setText(QString());
        button12->setText(QString());
        button18->setText(QString());
        button27->setText(QString());
        button9->setText(QString());
        button35->setText(QString());
        button23->setText(QString());
        button10->setText(QString());
        button34->setText(QString());
        button6->setText(QString());
        button7->setText(QString());
        button14->setText(QString());
        button2->setText(QString());
        button36->setText(QString());
        button11->setText(QString());
        button13->setText(QString());
        button3->setText(QString());
        button21->setText(QString());
        button26->setText(QString());
        button29->setText(QString());
        button8->setText(QString());
        button19->setText(QString());
        button28->setText(QString());
        puntajePJugador1->setText(QCoreApplication::translate("Game", "Puntaje:", nullptr));
        namePJugador1->setText(QString());
        namePJugador2->setText(QString());
        puntajePJugador2->setText(QCoreApplication::translate("Game", "Puntaje:", nullptr));
        AvisosPjuego->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Game: public Ui_Game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
