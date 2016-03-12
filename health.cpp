#include "health.h"
#include "roundone.h"
#include <QFont>
#include <QGraphicsTextItem>


///external global variable RoundOne* one
extern RoundOne* one;

/**
 * This is the Health class constructor.
 * @brief Health::Health sets health at three and creates a string to display the health.
 * @param parent makes QGraphicsTextItem a parent of the class Health
 */
Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    ///start health at 3
    health=3;
    ///create a string of "Health: " and then a number the represents the integer health.
    setPlainText(QString("Health: ") +QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 20));

}

/**
 * This function decreases the health by one until the health is zero, when it calls game_over() function from RoundOne class
 * @brief Health::decrease decreases the health by one and calls game_over() if the health is zero. It also updates the string displaying the health after it is decreased.
 */
void Health::decrease(){   
    ///decrease the health
    --health;
    ///update the appearance of the string of health in the scene
    setPlainText(QString("Health: ") +QString::number(health));
    ///check if health equals zero, if it does, call the RoundOne function game_over.
    if(health==0){
        one->game_over();
    }
}
