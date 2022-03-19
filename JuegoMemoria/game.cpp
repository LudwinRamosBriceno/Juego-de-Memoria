#include "game.h"
#include "./ui_game.h"

#include <iostream>
using namespace std;

Game::Game(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Game)
{
    ui->setupUi(this);
}

Game::~Game()
{
    delete ui;
}

