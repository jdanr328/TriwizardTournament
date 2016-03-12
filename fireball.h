/**@file fireball.h
 * @brief declaration for the fireball class
 *
 * Contains the declarations of the member funcitons.
*/
#ifndef FIREBALL_H
#define FIREBALL_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include "dragon.h"
#include <QObject>


/**
 * @class Fireball
 * This class models the fireball that is shot at the player Harry from the Dragon's mouth
 * @brief The Fireball class constructs a fireball that moves downscreen and decreases Harry's health if it collides with him.
 */
class Fireball: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Fireball(QGraphicsItem* parent=0);
public slots:
    void fire();
};

#endif // FIREBALL_H
