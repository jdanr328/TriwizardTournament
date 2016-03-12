/**@file egg.h
 * @brief declaration for the egg class
 *
 * Contains the declarations of the class object.
*/
#ifndef EGG_H
#define EGG_H

#include <QGraphicsPixmapItem>
#include <chrono>
#include <random>
#include <QObject>


/**
 * @class Egg
 * @brief The Egg class creates a golden egg that an object of the Harry class must be at the same position as to win the game, but this is checked in a function in the Harry class.
 */
class Egg: public QGraphicsPixmapItem{
public:
    Egg(QGraphicsItem* parent=0);


};


/**
 * @class Ron
 * @brief The Ron class creates a QGraphicsPixmapItem with the appearance of Ron Weasley
 */
class Ron: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Ron(QGraphicsItem* parent=0);
public slots:
    void lose();
};


#endif // EGG_H
