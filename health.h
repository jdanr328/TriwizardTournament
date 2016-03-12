#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>
#include <QLabel>
#include <QHBoxLayout>


/**
 * @class Health
 * This class creates and modifies the Health of the player in the game.
 * @brief The Health class creates a string with the current health, which starts at three, and has a function to decrease the health by one and update the string display of health.
 */
class Health: public QGraphicsTextItem{
public:
    Health (QGraphicsItem * parent=0);

    void decrease();

private:
    ///keeps track of the health of the player
    int health;

};

#endif // HEALTH_H
