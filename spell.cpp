/**@file spell.cpp
 * @brief Contains the implementation for the Spell class
  */

#include "spell.h"
#include <QTimer>
#include "fireball.h"
#include <QList>
#include "roundone.h"
#include "score.h"

///external global object called one
extern RoundOne* one;


/**
 * This constructor sets the pixmap, sets the scale and starts a timer that connects with the slot move().
 * @brief Spell::Spell is the constructor for the Spell class
 * @param parent makes QGraphicsPixmapItem the parent of Spell
 */
Spell::Spell(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    ///create spell
    setPixmap(QPixmap(":/new/prefix1/spell.jpg"));
    setScale(0.01);


    QTimer* timer= new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(30);
}


/**
 * This is the move function
 * @brief Spell::move fires a spell from the hand of the player. It travels upscreen towards the dragon and his/her fireballs.
 */
void Spell::move()
{
    QList<QGraphicsItem*> collisions= collidingItems();
    ///Check if a spell is colliding with an object of type Fireball or type Dragon, that is if a spell is colliding with a fireball or a dragon
    for(size_t i=0, n= collisions.size(); i<n; ++i){
            ///if spell and fireball collide, remove both then delete both.
            if(typeid(*(collisions[i])) == typeid(Fireball)){
                ///increase score
                one->score->increase();
                scene()->removeItem(collisions[i]);
                scene()->removeItem(this);
                delete collisions[i];
                delete this;

                return;

            }
            ///if spell collides with dragon, remove and delete fireball and decrease the score
            else if(typeid(*(collisions[i])) ==typeid(Dragon)){
                one->score->decrease();
                scene()->removeItem(this);
                delete this;
                return;
            }
    }

    ///if spell does not collide with anything, continue its movement up screen until it goes out of the scene, then remove and delete it
    setPos(x(), y()-10);
    if(pos().y()<0){
        scene()->removeItem(this);
        delete this;
    }
}
