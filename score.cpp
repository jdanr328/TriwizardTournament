#include "score.h"
#include <QFont>

/**
 * This is the Score class constructor.
 * @brief Score::Score sets score at zero and creates a string to display the score.
 * @param parent makes QGraphicsTextItem a parent of the class Score
 */
Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    ///at beginning of game, score equals 0
    score=0;

    ///create a string of "Score: " and then a number the represents the integer score.
    setPlainText(QString("Score: ") +QString::number(score));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 20));//string then integer that represents font and size of font

}

/**
 * This function increases the score by one.
 * @brief Score::increase increases the score by one and updates the displayed score
 */
void Score::increase(){   
    ++score;

    setPlainText(QString("Score: ") +QString::number(score));///displays increased score
}

/**
 * This function decreases the score by one.
 * @brief Score::decrease decreases the score by one and updates the displayed score. It is possible to have a negative score.
 */
void Score::decrease(){  
    --score;
    setPlainText(QString("Score: ") +QString::number(score));///displays decreased score
}
