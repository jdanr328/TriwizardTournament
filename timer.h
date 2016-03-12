#ifndef TIMER_H
#define TIMER_H

#include <QLCDNumber>
#include <QTimer>
#include <QTime>

/**
 * @class Timer
 * This class creates a count down timer for the second task
 * @brief The Timer class creates a timer that decreases the time by one second every second and stops when it reaches zero minutes and zero seconds
 */
class Timer: public QLCDNumber{
    Q_OBJECT
public:
    QTimer* timer;
    QTime* timeValue;
    Timer(int m, int s){
        timer= new QTimer();
        setSegmentStyle(Flat);
        timeValue= new QTime(0, m, s);
        minutes= m;
        seconds=s;
        this->display(timeValue->toString());
        QObject::connect(timer, SIGNAL(timeout()), this, SLOT(set_up_display()));

    };
    ///get function for minutes
    int get_minutes(){return minutes;};

    ///get function for seconds
    int get_seconds(){return seconds;};

public slots:
    /**
     * This public slot sets up the display of the timer
     * @brief set_up_display converts the seconds and minutes to a string after decreasing them. Then it checks if the timer has reached 0.
     */
    void set_up_display(){
        this->timeValue->setHMS(0, this->timeValue->addSecs(-1).minute(), this->timeValue->addSecs(-1).second());
        this->display(this->timeValue->toString());
        if(seconds==0 && minutes!=0){
            --minutes;
            seconds=59;
        }else if(seconds==0 && minutes==0){
            timer->stop();
        }else{
            --seconds;
        }
    }
private:
   ///keeps track of minutes left in the timer
   int minutes;
   ///keeps track of seconds left in the timer
   int seconds;
};


#endif // TIMER_H
