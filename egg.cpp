/**@file egg.cpp
 * @brief Contains the implementation for the Egg class
  */
#include "egg.h"
#include <QGraphicsScene>
#include <ctime>
#include "roundone.h"

///external global variable RoundOne* one
extern RoundOne* one;

/**
 * This is the constructor for the Egg class. It sets the position, scale, and pixmap of the Egg
 * @brief Egg::Egg is the constructor for the egg class
 * @param parent makes QGraphicsItem a parent of Egg
 */
Egg::Egg(QGraphicsItem *parent):QGraphicsPixmapItem(parent){
    ///set position, pixmap and scale of egg
    setPos(370,0);
    setPixmap(QPixmap(":/new/prefix1/goldegg.png"));
    setScale(0.06);
}

///create an unsigned seed and use it to generate a random number
unsigned seedthree= std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine generatorthree(seedthree);
/**
 * This constructor sets an object of the class at a random position and gives it the pixmap of the character Ron Weasley
 * @brief Ron::Ron is the constructor for the Ron class and randomly places an object within the scene using random numbers
 * @param parent makes QGraphicsItem a parent of Ron
 */
Ron::Ron(QGraphicsItem *parent):QGraphicsPixmapItem(parent){  
    std::uniform_int_distribution<int> random_x(0,750);
    std::uniform_int_distribution<int> random_y(0, 550);
    setPos(random_x(generatorthree), random_y(generatorthree));
    setPixmap(QPixmap(":/new/prefix1/l_ron-young-standing.png"));
    setScale(0.05);
}

/**
 * This function checks if the timer has run out and then calls the game over function for round two
 * @brief Ron::lose calls the game_over_round_two function from class RoundOne if both the minutes and the seconds of the timer equal zero
 */
void Ron::lose(){
    if (one->time->get_seconds()==0 && one->time->get_minutes()==0){
        one->game_over_round_two();
    }
}
