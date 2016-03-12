#ifndef SCORE_H
#define SCORE_H


#include <QGraphicsTextItem>


/**
 * @class Score
 * This class creates and modifies the Score of the player in the game.
 * @brief The Score class creates a string with the current score, which starts at zero, and has functions to both increase and decrease the score by one and update the string display of the score.
 */
class Score: public QGraphicsTextItem{
public:
    Score(QGraphicsItem* parent=0);
    void increase();
    void decrease();

private:
   ///keeps track of the score
   int score;
};

#endif // SCORE_H
