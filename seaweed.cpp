#include "seaweed.h"
#include <chrono>
#include <random>

///generate seed for random number
unsigned seedtwo= std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine generatortwo(seedtwo);

/**
 * This constructor sets an object of the class at a random position and gives it the pixmap of seaweed
 * @brief Seaweed::Seaweed is the constructor for the Seaweed class and randomly places an object within the scene using random numbers
 * @param parent makes QGraphicsItem a parent of Seaweed
 */
Seaweed::Seaweed(QGraphicsItem *parent){
    ///generate random numbers
    std::uniform_int_distribution<int> x_pos(0,750);
    std::uniform_int_distribution<int> y_pos(0,520);
    ///set x and y equal to these random numbers
    int x= x_pos(generatortwo);
    int y= y_pos(generatortwo);
    ///then set the position of the seaweed to this random x and y
    setPos(x, y);
    ///set the pixmap
    setPixmap(QPixmap(":/new/prefix1/long_leafy_plant_png_by_alz_stock-d7n0a5u.png"));
    ///set the scale to make it smaller
    setScale(0.035);
}
