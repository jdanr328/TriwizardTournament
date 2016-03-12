#ifndef SEAWEED_H
#define SEAWEED_H

#include <QGraphicsPixmapItem>
#include <chrono>
#include <random>


/**
 * @class Seaweed
 * This class constructs the seaweed in the second task
 * @brief The Seaweed class randomly places a seaweed around the scene using random numbers to make the coordinates of the position in which the seaweed is placed.
 */
class Seaweed: public QGraphicsPixmapItem{
public:
    Seaweed(QGraphicsItem* parent=0);
};


#endif // SEAWEED_H
