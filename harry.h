/**@file harry.h
 * @brief declaration for the harry class
 *
 * Contains the declarations of the member funcitons.
*/

#ifndef HARRY_H
#define HARRY_H


#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QLabel>
#include <QObject>
#include <QPainter>
#include <QTransform>


/**
 * @class Harry
 * This class deals with the player Harry in the game.
 * @brief The Harry class constructs the player for the first task and moves an object of type Harry or shoots a spell when specific keys are pressed. It has a win() function to check if the game is won.
 */
class Harry: public QObject, public QGraphicsPixmapItem{
Q_OBJECT
public:
    Harry(QGraphicsItem* parent=0);
    void keyPressEvent(QKeyEvent* event);

    bool win();

private:

};


/**
 * @class Harry2
 * This class deals with the player Harry2 in the game during the second round.
 * @brief The Harry2 class constructs the player for the second task and moves an object of type Harry or looks for and object of type Ron when specific keys are pressed. It has win() and lose() functions to check if the game is won or lost.
 */
class Harry2: public QObject, public QGraphicsPixmapItem{
Q_OBJECT
public:
    Harry2(QGraphicsItem* parent=0);
    void keyPressEvent(QKeyEvent* event);
    bool win();
private:

};



#endif // HARRY_H
