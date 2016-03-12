/**@mainpage game
 * @author Julia Regan
 * @purpose homework for PIC 10C class, Winter 2016
 * @date 03-11-2016
 *
 * This program creates a GUI modeling the first and second task of the triwizard tournament from Harry Potter.
 * @brief In the first task, the player must reach the golden egg without getting hit by three of the dragon's fireballs or hitting the dragon. The player can cast a spell to blast the fireballs out of the way. In the second task, the player has one minute to find the character of Ron hidden under one of the many randomly placed seaweeds.
  */

#include <QApplication>
#include "roundone.h"

///create a global variable RoundOne* one
RoundOne* one;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    one= new RoundOne();
    one->show();
    one->displayMainMenu();

    return a.exec();
}
