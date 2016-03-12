/**@file spell.h
 * @brief declaration for the spell class
 *
 * Contains the declarations of the member funcitons.
*/

#ifndef SPELL_H
#define SPELL_H

#include<QGraphicsPixmapItem>
#include<QGraphicsItem>
#include <QObject>
#include "score.h"

/**
 * @class Spell
 * This class constructs a spell that a player of type Harry can cast at the fireballs of type Fireball to delete them before they hit the player.
 * @brief The Spell class creates a spell that moves up screen until going off screen or hitting an object of type Fireball.
 */
class Spell: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Spell(QGraphicsItem* parent=0);

public slots:
    void move();


};

#endif // SPELL_H

