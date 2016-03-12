/**@file dragon.h
 * @brief declaration for the dragon class
 *
 * Contains the declarations of the member funcitons.
*/
#ifndef DRAGON_H
#define DRAGON_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <random>
#include <chrono>


/**
 * @class Dragon
 * The Dragon class creates a dragon in the constructor that can move, breath fire and determines whether the game is lost.
 * @brief The Dragon class controls the movement of the dragon created in the RoundOne class, fire breathing function, and the lose function that determines before each dragon movement whether the player in the Harry class has lost the game.
 */
class Dragon: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Dragon(QGraphicsItem* parent=0);
    bool lose();
public slots:
    void move();
    void breath();
};

#endif // DRAGON_H
