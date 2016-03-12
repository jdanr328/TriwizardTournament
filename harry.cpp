/**@file harry.cpp
 * @brief Contains the implementation for the Harry class
  */

#include "harry.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "spell.h"
#include "roundone.h"
#include <QList>
#include "egg.h"
#include "timer.h"

///external global varaible RoundOne* one
extern RoundOne* one;

/**This constructor sets the Pixmap for Harry
 * @brief Harry::Harry sets the Pixmap for a Harry object.
 * @param parent makes QGraphicsPixmapItem a parent of Harry
 */
Harry::Harry(QGraphicsItem* parent): QObject(), QGraphicsPixmapItem(parent){
   setPixmap(QPixmap(":/new/prefix1/harry on broom.png"));
}

/**This is the keyPressEvent function that responds to keys being pressed on the keyboard.
 * @brief Harry::keyPressEvent will move Harry or shoot depending on the key pressed.
 * @param event is the key that is pressed
 */
void Harry::keyPressEvent(QKeyEvent *event){
    ///if left arrow key is pressed, and Harry's x position is greater than 0, move left 10 pixels
    if(event->key()==Qt::Key_Left){
        if(pos().x() >0){
            setPos(x()-10, y());
        }
    }
    ///if right arrow key is pressed, and Harry's x position is less than 720, move right 10 pixels
    else if(event->key()==Qt::Key_Right){
        if(pos().x()<720){
            setPos(x()+10, y());
        }
    }
    ///if up arrow key is pressed, and Harry's y position is greater than 0, move up 10 pixels
    else if(event->key()==Qt::Key_Up){
        if(pos().y()>0){
            setPos(x(), y()-10);
        }
    }
    ///if down arrow key is pressed, and Harry's y position is less than 540, move down 10 pixels
    else if(event->key()==Qt::Key_Down){
        if(pos().y()<540){
            setPos(x(), y()+10);
        }
    }
    ///if space key is pressed, create a new spell
    else if(event->key()==Qt::Key_Space){
        Spell* cast= new Spell();
        ///set the position of the spell to the position of approxmiately Harry's wand hand
        cast->setPos(x()+30, y());
        ///set the scale of the spell
        cast->setScale(.10);
        ///add the spell to the scene
        scene()->addItem(cast);
    }
    ///check if Harry::win() is true and if it is, call funciton win_round_one() from class RoundOne.
    if(win()){
        one->win_round_one();
    }
}


/**This function will end the game when Harry reaches the location of the object of class Egg.
 * @brief Harry::win checks to see if Harry has reached the same position as the egg
 * @return true if player of class Harry is in the same position of the object of class Egg, false otherwise
 */
bool Harry::win()
{
    QList<QGraphicsItem*> winner= collidingItems();
    for(size_t i=0, n=winner.size(); i<n; ++i){
        if(typeid(*(winner[i]))==typeid(Egg)){

            return true;
        }
    }return false;
}


/* HARRY 2*/

/**This constructor sets the Pixmap for Harry2
 * @brief Harry2::Harry2 sets the Pixmap for a Harry2 object.
 * @param parent makes QGraphicsPixmapItem a parent of Harry2
 */
Harry2::Harry2(QGraphicsItem* parent): QObject(), QGraphicsPixmapItem(parent){
   setPixmap(QPixmap(":/new/prefix1/hpswim.jpg"));
   setScale(15.0);
}

/**This is the keyPressEvent function that responds to keys being pressed on the keyboard.
 * @brief Harry2::keyPressEvent will move Harry2 or shoot depending on the key pressed.
 * @param event is the key that is pressed
 */
void Harry2::keyPressEvent(QKeyEvent *event){   
    ///if left arrow key is pressed, and Harry's x position is greater than 0, move left 10 pixels
    if(event->key()==Qt::Key_Left){
        if(pos().x() >0){
            setPos(x()-10, y());
        }
    }
    ///if right arrow key is pressed, and Harry's x position is less than 720, move right 10 pixels
    else if(event->key()==Qt::Key_Right){
        if(pos().x()<770){
            setPos(x()+10, y());
        }
    }
    ///if up arrow key is pressed, and Harry's y position is greater than 0, move up 10 pixels
    else if(event->key()==Qt::Key_Up){
        if(pos().y()>0){
            setPos(x(), y()-10);
        }
    }
    ///if down arrow key is pressed, and Harry's y position is less than 540, move down 10 pixels
    else if(event->key()==Qt::Key_Down){
        if(pos().y()<580){
            setPos(x(), y()+10);
        }
    }
    ///if space key is pressed, check if Harry2::win() is true
    else if(event->key()==Qt::Key_Space){
        ///if win() is true, call RoundOne function win_round_two().
        if(win()){
            one->win_round_two();
        }
    }

}

/**This function will end the game when Harry2 reaches the location of the object of class Ron.
 * @brief Harry2::win checks to see if Harry2 has reached the same position as Ron
 * @return true if player of class Harry2 is in the same position of the object of class Egg, false otherwise
 */
bool Harry2::win()
{
    QList<QGraphicsItem*> winner= collidingItems();
    for(size_t i=0, n=winner.size(); i<n; ++i){
        if(typeid(*(winner[i]))==typeid(Ron)){
            one->time->timer->stop();
            return true;
        }
    }return false;
}
