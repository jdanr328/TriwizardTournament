/**@file fireball.cpp
 * @brief Contains the implementation for the FireBall class
  */
#include "fireball.h"
#include "dragon.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "harry.h"
#include "roundone.h"
#include "health.h"

///external global variable RoundOne* one
extern RoundOne* one;

/**
 * This constructor sets the pixmap, sets the scale and starts a timer that connects with the slot fire().
 * @brief Fireball::Fireball is the constructor for the Fireball class
 * @param parent makes QGraphicsItem the parent of Fireball
 */
Fireball::Fireball(QGraphicsItem* parent): QObject(), QGraphicsPixmapItem(parent)
{

   setPixmap(QPixmap(":/new/prefix1/Fireball-powerup.png"));
   setScale(0.23);
   setRotation(180);

   QTimer* timer= new QTimer(this);
   connect(timer, SIGNAL(timeout()), this, SLOT(fire()));
   timer->start(50);

}

/**
 * This is the fire function
 * @brief Fireball::fire fires a fireball from the mouth of the dragon. It travels downscreen towards Harry.
 */
void Fireball::fire(){
    QList<QGraphicsItem*> burn= collidingItems();
    ///Check if a fireball is colliding with an object of type Harry, that is if a fireball is colliding with the player
    for(size_t i=0, n=burn.size(); i<n; ++i){
        ///if a fireball is colliding with the player, remove and delete the fireball and decrease the health of the player by one
        if(typeid(*(burn[i]))==typeid(Harry)){

            scene()->removeItem(this);
            delete this;
            one->health->decrease();
            return;
         }

     }
    ///if a fireball is not colliding with the player, continue its movement downscreen
    setPos(x(), y()+10);

    ///if the fireball goes out of the view of the scene, delete it
    if(pos().y()>600){
        scene()->removeItem(this);
        delete this;
    }


}
