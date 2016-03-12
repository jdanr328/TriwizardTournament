/**@file dragon.cpp
 * @brief Contains the implementation for the Dragon class
  */
#include "dragon.h"
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "roundone.h"
#include "fireball.h"
#include <QGraphicsScene>
#include <ctime>

///external global variable RoundOne* one
extern RoundOne* one;

/**
 * This function determines the movement of the dragon based on a pseudorandom number
 * @brief Dragon::move The dragon will move right or left depending on the number generated
 * A pseudorandom number was chosen instead of a random number from teh c++11 library on purpose because it allowed for more fluid movement in the gui due to the less random nature of the movement.
 */
void Dragon::move()
{   ///generate a random number
    srand(time(NULL));
    int random_move= rand() % 4 + 1;

    ///if the number is less than or equal to 2, move the dragon on to the right
    if(random_move<=2){
        ///check if the player has lost before moving
        if(lose()){one->game_over();}
        else if(pos().x()<605){
            setPos(x()+60, y());
        }else {setPos(x()-100, y());}
    }
    ///else if the number is greater than 2, move left
    else if(random_move>2){
        ///check if the player has lost before moving
        if(lose()){one->game_over();}
        else if(pos().x()>5){
            setPos(x()-60, y());
        }else{setPos(x()+100, y());}
    }
}

/**
 * This is the constructor for the Dragon class. It creates the dragon and calls a move function.
 * @brief Dragon::Dragon is the constructor for the Dragon class
 * @param parent makes QGraphicsItem the parent of Dragon
 */
Dragon::Dragon(QGraphicsItem* parent):QObject(), QGraphicsPixmapItem(parent)
{   ///set the pixmap of the QGraphicsPixmapItem
    setPixmap(QPixmap(":/new/prefix1/horntail.png"));
    ///set the scale
    setScale(0.08);

    ///set the position of the dragon
    setPos(350, 60);

    ///start the timer that signals the move function for the dragon
    QTimer* timer= new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    ///set the timer speed based on the level chosen within the RoundOne class
    timer->start(one->speed);


}


/**
 * This function checks whether the dragon is hitting an object of class Harry to determine if the player has lost the game.
 * @brief Dragon::lose determines whether the player has run into the dragon and (died and) thus lost the game
 * @return true if the dragon is hitting an object of class Harry and false if it is not.
*/
bool Dragon::lose()
{
    QList<QGraphicsItem*> lose= collidingItems();
    for(size_t i=0, n=lose.size(); i<n; ++i){
        if(typeid(*(lose[i]))==typeid(Harry)){
                return true;
        }
    } return false;
}

/**
 * This function creates a fireball and shoots it from the position of the dragon's mouth.
 * @brief Dragon::breath A fireball of class Fireball is created, its position is set to the dragon's mouth and the fireball is added to the scene.
 */
void Dragon::breath(){
    ///breath fire aka create and shoot a fire ball
    Fireball* fire= new Fireball();
    fire->setPos(x()+70, y()+25);
    scene()->addItem(fire);
}
