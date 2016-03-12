/**@file roundone.h
 * @brief declaration for the round one main window
 *
 * Contains the declarations of the member funcitons. And creates the window for the game.
*/

#ifndef ROUNDONE_H
#define ROUNDONE_H

#include <QRadioButton>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include <QMediaPlayer>
#include "Harry.h"
#include "dragon.h"
#include "egg.h"
#include "score.h"
#include "health.h"
#include "seaweed.h"
#include "timer.h"



/**
 * @class RoundOne
 * This function sets up the game and contains all of the major functions used to display the game and move between levels/screens.
 * @brief The RoundOne class contains functions to start the first and second rounds of the Triwizard tournament, win each round, lose each round, and retry each round.
 */
class RoundOne : public QGraphicsView
{
    Q_OBJECT
public:
    RoundOne(QWidget *parent = 0);
    virtual ~RoundOne();

    ///Round one functions
    void displayMainMenu();
    void displayGameOverWindow(QString text);
    void displayWinnerWindow(QString text);


    ///Round two functions
    void displayMainMenuTwo();
    void displayGameOverWindowRoundTwo(QString text);
    void displayWinnerWindowRoundTwo(QString text);

    ///Round three functions
    void displayMainMenuThree();


    ///objects for all rounds
    QWidget* main_widget;
    QGraphicsScene* scene_one;

    ///Round one objects
    Harry* player;
    Dragon* horntail;
    Egg* egg;
    Score* score;
    Health* health;
    QRadioButton* easy;
    QRadioButton* medium;
    QRadioButton* hard;
    int speed;
    QMediaPlayer* flying_music;

    ///Round two objects
    Harry2* player2;
    Ron* ron;
    Timer* time;
    Seaweed* p9;
    QTimer* othertimer;
    QMediaPlayer* swimming_music;




public slots:
    ///Round one slots
    void game_over();
    void win_round_one();
    void start_game();
    void retry_round_one();

    ///Round two slots
    void game_over_round_two();
    void start_second_round();
    void win_round_two();
    void retry_round_two();
    void display_menu_two();

    ///Round three slots
    void display_menu_three();

private:
    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);


};

#endif // ROUNDONE_H
