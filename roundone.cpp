/**@file roundone.cpp
 * @brief Contains the implementation for the RoundOne class
  */

#include "roundone.h"
#include "harry.h"
#include "egg.h"
#include <QBrush>
#include <QImage>
#include <QGraphicsTextItem>
#include <QWidget>
#include <QTimer>
#include <QPushButton>
#include <QFont>
#include <QGroupBox>
#include <QApplication>
#include <ctime>
#include <QGraphicsPixmapItem>


///external global object called one
extern RoundOne* one;

/**
 * This function creates a new scene for the game to take place in
 * @brief RoundOne::RoundOne constructor creates a new QGraphicsScene, sets its Pixmap and sets its size
 * @param parent of RoundOne is QGraphics View
 */
RoundOne::RoundOne(QWidget *parent):QGraphicsView(parent)
{

    ///create new QGraphicsScene
    scene_one= new QGraphicsScene();
    ///set the size of the scene
    scene_one-> setSceneRect(0,0,800,600);
    ///set the background
    setBackgroundBrush(QBrush(QImage(":/new/prefix1/DragonEnclosure.png").scaledToHeight(600)));

    ///set the scene
    setScene(scene_one);
    ///turn off vertical and horizontal scroll bars
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ///set size of the scene
    setFixedSize(800, 600);
}

/**
 * This is the destructor for the RoundOne class
 * @brief RoundOne::~RoundOne is the destructor
 */
RoundOne::~RoundOne(){

}

/**
 * This function add all of the necessary components for game play to the scene.
 * @brief RoundOne::start_game sets the speed of the dragon and fireballs and adds objects of classes Harry, Dragon, Egg, Score, and Health to the scene and then begins the game by starting the horntail breathing fire.
 */
void RoundOne::start_game(){
    ///Close the main menu
    main_widget->close();
    ///if retrying game again, clear away the game over window
    scene_one->clearFocus();
    scene_one->clear();


    int n=0;
    ///set the level depending on which QRadioButton was checked
    if(easy->isChecked()){
        speed= 100;
        n=650;
    }else if(medium->isChecked()){
        speed=70;
        n=500;
    }else if(hard->isChecked()){
        speed=40;
        n=300;
    }

    ///create new Egg
    egg= new Egg();

    ///create new Dragon
    horntail= new Dragon();

    ///create new Harry called player, scale player, set position of player
    player = new Harry();
    player->setScale(.20);
    player-> setPos(375, 540);

    ///make player focusable and then set focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();


    ///add player, horntail, and egg to the scene
    scene_one->addItem(player);
    scene_one->addItem(horntail);
    scene_one->addItem(egg);

    ///create and add score to the scene
    score= new Score();
    scene_one->addItem(score);

    ///create and add health to the scene and set its position
    health= new Health();
    health->setPos(700, 0);
    scene_one->addItem(health);

    ///add sound
    flying_music= new QMediaPlayer();
    flying_music->setMedia(QUrl("qrc:/new/prefix2/03 The Quidditch World Cup 2.mp3"));
    QTimer* flying_music_timer= new QTimer();
    //QObject::connect(flying_music_timer, SIGNAL(timeout()), flying_music, SLOT(play()));
    //flying_music_timer->start(1000);
    flying_music->play();


    ///create QTimer and then connect it to the horntail breathing fire at player
    QTimer* timer= new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), horntail, SLOT(breath()));
    timer->start(n);



    ///show the scene
    show();


}

/**
 * This is a public slot that creates the second round and displays the main menu for the second round
 * @brief RoundOne::display_menu_two closes the first round and opens a new round and then displays the main menu for the second task.
 */
void RoundOne::display_menu_two(){   
    close();
    one=new RoundOne();
    one->show();
    one->displayMainMenuTwo();
}

/**
 * This is a public slot that creates the third round and displays the main menu for the third round
 * @brief RoundOne::display_menu_three closes the second round and opens a new round and then displays the main menu for the third task.
 */
void RoundOne::display_menu_three(){
    close();
    one=new RoundOne();
    one->show();
    one->displayMainMenuThree();
}

/**
 * This is a public slot that starts the first task over again
 * @brief RoundOne::retry_round_one closes the current attempt at task one and opens another one, showing the main menu for the first task
 */
void RoundOne::retry_round_one(){
    close();
    one=new RoundOne();
    one->show();
    one->displayMainMenu();
}

/**
 * This function adds all of the necessary components for gameplay in the second task to the scene.
 * @brief RoundOne::start_second_round creates and adds objects of classes Ron, Harry2, Seaweed, and Timer to the scene and starts the timers necessary to begin the second round.
 */
void RoundOne::start_second_round(){
    ///clear the scene and close all other windows
    main_widget->close();
    scene_one->clearFocus();
    scene_one->clear();

    ///create new Ron and add it to the scene
    ron= new Ron();
    scene_one->addItem(ron);

    ///create and add 39 randomly placed seaweeds to the scene, and create and add one right in front of ron
    Seaweed* p1= new Seaweed();
    Seaweed* p2= new Seaweed();
    Seaweed* p3= new Seaweed();
    Seaweed* p4= new Seaweed();
    Seaweed* p5= new Seaweed();
    Seaweed* p6= new Seaweed();
    Seaweed* p7= new Seaweed();
    Seaweed* p8= new Seaweed();
    p9= new Seaweed();
    Seaweed* p10= new Seaweed();
    Seaweed* p11= new Seaweed();
    Seaweed* p12= new Seaweed();
    Seaweed* p13= new Seaweed();
    Seaweed* p14= new Seaweed();
    Seaweed* p15= new Seaweed();
    Seaweed* p16= new Seaweed();
    Seaweed* p17= new Seaweed();
    Seaweed* p18= new Seaweed();
    Seaweed* p19= new Seaweed();
    Seaweed* p20= new Seaweed();
    Seaweed* p21= new Seaweed();
    Seaweed* p22= new Seaweed();
    Seaweed* p23= new Seaweed();
    Seaweed* p24= new Seaweed();
    Seaweed* p25= new Seaweed();
    Seaweed* p26= new Seaweed();
    Seaweed* p27= new Seaweed();
    Seaweed* p28= new Seaweed();
    Seaweed* p29= new Seaweed();
    Seaweed* p30= new Seaweed();
    Seaweed* p31= new Seaweed();
    Seaweed* p32= new Seaweed();
    Seaweed* p33= new Seaweed();
    Seaweed* p34= new Seaweed();
    Seaweed* p35= new Seaweed();
    Seaweed* p36= new Seaweed();
    Seaweed* p37= new Seaweed();
    Seaweed* p38= new Seaweed();
    Seaweed* p39= new Seaweed();
    Seaweed* p40= new Seaweed();

    p9->setPos(ron->pos().x() -10, ron->pos().y()-40);

    ///draw a panel to create a water effect
    drawPanel(0, 0, 800, 600, Qt::darkBlue, 0.70);

    scene_one->addItem(p1);
    scene_one->addItem(p2);
    scene_one->addItem(p3);
    scene_one->addItem(p4);
    scene_one->addItem(p5);
    scene_one->addItem(p6);
    scene_one->addItem(p7);
    scene_one->addItem(p8);
    scene_one->addItem(p9);
    scene_one->addItem(p10);
    scene_one->addItem(p11);
    scene_one->addItem(p12);
    scene_one->addItem(p13);
    scene_one->addItem(p14);
    scene_one->addItem(p15);
    scene_one->addItem(p16);
    scene_one->addItem(p17);
    scene_one->addItem(p18);
    scene_one->addItem(p19);
    scene_one->addItem(p20);
    scene_one->addItem(p21);
    scene_one->addItem(p22);
    scene_one->addItem(p23);
    scene_one->addItem(p24);
    scene_one->addItem(p25);
    scene_one->addItem(p26);
    scene_one->addItem(p27);
    scene_one->addItem(p28);
    scene_one->addItem(p29);
    scene_one->addItem(p30);
    scene_one->addItem(p31);
    scene_one->addItem(p32);
    scene_one->addItem(p33);
    scene_one->addItem(p34);
    scene_one->addItem(p35);
    scene_one->addItem(p36);
    scene_one->addItem(p37);
    scene_one->addItem(p38);
    scene_one->addItem(p39);
    scene_one->addItem(p40);

    ///Give the player 1 minute on the timer to complete the task
    time= new Timer(1, 0);
    scene_one->addWidget(time);
    ///create new Harry2 to the scene
    player2=new Harry2();
    player2->setScale(.25);
    player2-> setPos(365, 300);
    ///make player2 focusable and then set focus
    player2->setFlag(QGraphicsItem::ItemIsFocusable);
    player2->setFocus();

    ///Check every second if the time has run out and the player has lost the game
    othertimer= new QTimer();
    QObject::connect(othertimer, SIGNAL(timeout()), ron, SLOT(lose()));
    othertimer->start(1000);

    ///add player2 to the scene
    scene_one->addItem(player2);

    swimming_music= new QMediaPlayer();
    swimming_music->setMedia(QUrl("qrc:/new/prefix2/UnderwaterSong.m4a"));
    swimming_music->play();

    show();
    ///start the count down timer
    time->timer->start(1000);

}

/**
 * This is a public slot that calls the displayWinnerWindowRoundTwo function
 * @brief RoundOne::win_round_two passes a message into the displayWinnerWindowRoundTwo(message) function and calls it.
 */
void RoundOne::win_round_two(){
    othertimer->stop();
    time->timer->stop();
    swimming_music->stop();
    QString message="Winner! \nYou found Ron! \nYou are a true Triwizard champion!\nGet ready for the final round!";
    displayWinnerWindowRoundTwo(message);
}

/**
 * This public slot creates a new RoundOne and opens the menu for task two so the player can start task two over again.
 * @brief RoundOne::retry_round_two closes the current window, creates a new RoundOne, shows it, and displays the main menu for task two.
 */
void RoundOne::retry_round_two(){   
    close();
    one=new RoundOne();
    one->show();
    one->displayMainMenuTwo();
}

/**
 * This function displays the window after losing the first task.
 * @brief RoundOne::displayGameOverWindow creates a panel to obscure the background and places a message on the screen along with a retry button.
 * @param text is the message displayed in the window.
 */
void RoundOne::displayGameOverWindow(QString text){

    ///obscure game window with panel
    drawPanel(0,0,800,600, Qt::green, 0.6);
    ///make another panel with message
    drawPanel(200, 100, 400, 300, Qt::lightGray, 0.75);

    ///display message
    QGraphicsTextItem* message= new QGraphicsTextItem(text);
    message->setFont(QFont("lucida blackletter", 20));
    message->setPos(210, 225);

    scene_one->addItem(message);

    ///create a retry button and add it to the scene
    QPushButton* retry= new QPushButton("Replay");
    retry->setFont(QFont("lucida blackletter", 20));
    retry->setGeometry(270, 270, 100, 70);
    scene_one->addWidget(retry);

    ///create a retry button and add it to the scene
    QPushButton* give_up= new QPushButton("Give Up");
    give_up->setFont(QFont("lucida blackletter", 20));
    give_up->setGeometry(400, 270, 100, 70);
    scene_one->addWidget(give_up);

    QGraphicsPixmapItem* big_dragon= new QGraphicsPixmapItem;
    big_dragon->setPixmap(QPixmap(":/new/prefix1/horntail.png"));
    big_dragon->setPos(220, 0);
    big_dragon->setScale(0.28);
    scene_one->addItem(big_dragon);

    ///connect the retry button with the slot retry_round_one()
    connect(retry, SIGNAL(clicked(bool)), this, SLOT(retry_round_one()));
    ///connect the give_up button to close()
    connect(give_up, SIGNAL(clicked(bool)), this, SLOT(close()));
}

/**
 * This function displays the window after winning the first task.
 * @brief RoundOne::displayWinnerWindow creates a panel to obscure the background and places a message on the screen along with a round2 button.
 * @param text is the message displayed in the window.
 */
void RoundOne::displayWinnerWindow(QString text)
{

    ///obscure game window with panel
    drawPanel(0,0,800,600, Qt::darkYellow, 0.6);
    ///make another panel with message
    drawPanel(200, 100, 400, 300, Qt::darkMagenta, 0.75);

    ///display message
    QGraphicsTextItem* message= new QGraphicsTextItem(text);
    message->setFont(QFont("lucida blackletter", 20));
    message->setPos(210, 130);

    scene_one->addItem(message);

    QGraphicsPixmapItem* golden= new QGraphicsPixmapItem;
    golden->setPixmap(QPixmap(":/new/prefix1/goldegg.png"));
    golden->setScale(0.1);
    golden->setPos(370, 220);
    scene_one->addItem(golden);

    ///create a button and add it to the scene
    QPushButton* round2= new QPushButton("Start Round 2");
    round2->setFont(QFont("lucida blackletter", 20));
    round2->setGeometry(310, 310, 170, 90);
    scene_one->addWidget(round2);

    ///connect the round2 button with the slot display_menu_two()
    connect(round2, SIGNAL(clicked(bool)), this, SLOT(display_menu_two()));
}

/**
 * This function displays the main menu at the beginning of the second task.
 * @brief RoundOne::displayMainMenuTwo clears the scene, shows a welcome message, shows the instructions, and has QRadioButtons that let the player choose the level of difficulty and a start game QPushButton that starts the game.
 */
void RoundOne::displayMainMenuTwo()
{
    scene_one->clearFocus();
    main_widget= new QWidget;
    main_widget->setFixedSize(500,400);

    QLabel* ready= new QLabel;
    ready->setText("Get Ready to Start Task 2!");
    ready->setAlignment(Qt::AlignCenter);
    ready->setFont(QFont("lucida blackletter", 23));

    QLabel* song= new QLabel;
    song->setText("Come seek us where our voices sound, \nWe cannot sing above the ground,\nAnd while you're searching ponder this \nWe've taken what you'll sorely miss, \nA minute long you'll have to look, \nAnd to recover what we took, \nBut past an hour, the prospect's black, \nToo late, it's gone, it won't come back.");
    song->setWordWrap(true);
    song->setAlignment(Qt::AlignCenter);
    QFont* ital= new QFont("lucida blackletter");
    ital->setItalic(true);
    ital->setPixelSize(18);
    song->setFont(*ital);

    QLabel* instructions= new QLabel;
    instructions->setText("Instructions: Find your friend within the time limit  -  you have 1 minute! \nHint: You may want to try looking under the seaweed...\nUse the up, down, left and right arrow keys to swim through the water\nIf you think you are above Ron, hit the space key to move aside the seaweed and find him.");
    instructions->setWordWrap(true);
    instructions->setAlignment(Qt::AlignCenter);
    instructions->setFont(QFont("lucida blackletter", 13));

    QVBoxLayout* words= new QVBoxLayout;
    words->addWidget(ready);
    words->addWidget(song);
    words->addWidget(instructions);

    QPushButton* start= new QPushButton;
    start->setText("Start Round 2");

    words->addWidget(start);

    main_widget->setLayout(words);

    main_widget->show();
    connect(start, SIGNAL(clicked(bool)), this, SLOT(start_second_round()));
}

/**
 * This function displays the window after losing the second task.
 * @brief RoundOne::displayGameOverWindowRoundTwo creates a panel to obscure the background and places a message on the screen along with a retry button.
 * @param text is the message displayed in the window.
 */
void RoundOne::displayGameOverWindowRoundTwo(QString text)
{
    drawPanel(0,0,800,600, Qt::green, 0.4);
    ///make another panel with message
    drawPanel(200, 100, 400, 300, Qt::lightGray, 0.55);

    ///display message
    QGraphicsTextItem* message= new QGraphicsTextItem(text);
    message->setFont(QFont("lucida blackletter", 20));
    message->setPos(210, 100);

    scene_one->addItem(message);


    QGraphicsPixmapItem* mermaid= new QGraphicsPixmapItem;
    mermaid->setPixmap(QPixmap(":/new/prefix1/mermaid.jpg"));
    mermaid->setPos(250, 185);
    scene_one->addItem(mermaid);

    ///create a retry button and add it to the scene
    QPushButton* retry= new QPushButton("Replay");
    retry->setFont(QFont("lucida blackletter", 14));
    retry->setGeometry(310, 360, 80, 40);
    scene_one->addWidget(retry);

    ///create a retry button and add it to the scene
    QPushButton* give_up= new QPushButton("Give Up");
    give_up->setFont(QFont("lucida blackletter", 14));
    give_up->setGeometry(410, 360, 80, 40);
    scene_one->addWidget(give_up);

    ///connect the retry button with the slot retry_round_two()
    connect(retry, SIGNAL(clicked(bool)), this, SLOT(retry_round_two()));
    ///connect the give_up button with the slot close()
    connect(give_up, SIGNAL(clicked(bool)), this, SLOT(close()));
}

/**
 * This function displays the window after winning the second task.
 * @brief RoundOne::displayWinnerWindowRoundTwo creates a panel to obscure the background and places a message on the screen along with a round3 button.
 * @param text is the message displayed in the window.
 */
void RoundOne::displayWinnerWindowRoundTwo(QString text)
{
    //get rid of all scene items
    scene_one->clearFocus();
    //get ride of seaweed in front of Ron
    delete p9;
    //obscure game window with panel
    drawPanel(0,0,800,600, Qt::darkYellow, 0.4);
    //make another panel with message
    drawPanel(200, 100, 400, 300, Qt::darkMagenta, 0.6);

    //display message
    QGraphicsTextItem* message= new QGraphicsTextItem(text);
    message->setFont(QFont("lucida blackletter", 20));
    message->setPos(210, 140);
    scene_one->addItem(message);

    QGraphicsPixmapItem* found_friend= new QGraphicsPixmapItem;
    found_friend->setPixmap(QPixmap(":/new/prefix1/l_ron-young-standing.png"));
    found_friend->setPos(480, 220);
    scene_one->addItem(found_friend);

    ///create a button and add it to the scene
    QPushButton* round3= new QPushButton("Start Round 3");
    round3->setFont(QFont("lucida blackletter", 20));
    round3->setGeometry(310, 280, 170, 90);
    scene_one->addWidget(round3);

    ///connect the round3 button with the slot display_menu_three()
    connect(round3, SIGNAL(clicked(bool)), this, SLOT(display_menu_three()));
}

/**
 * This function displays message saying there will be no third task
 * @brief RoundOne::displayMainMenu clears the scene, shows a welcome message, shows the instructions, and has QRadioButtons that let the player choose the level of difficulty and a start game QPushButton that starts the game.
 */
void RoundOne::displayMainMenuThree(){

    ///obscure game window with panel
    drawPanel(0,0,800,600, Qt::darkMagenta, 0.6);


    ///display a message
    QGraphicsTextItem* congrats= new QGraphicsTextItem("You are a true Triwizard Champion!!!");
    congrats->setFont(QFont("lucida blackletter", 45));
    congrats->setPos(30,10);


    QGraphicsTextItem* message= new QGraphicsTextItem("As you may know, Cedric Diggory died \nlast year during this task. \n\nSo this task has a 25% mortality rate, \nwhich is really not good when all of the \nparticipants are children. \nSo, this year we have decided to cancel the \nthird task for your safety. \nCongratulations on finishing the Triwizard \nTournament (or at least the safer parts of it)!");
    message->setFont(QFont("lucida blackletter", 20));
    message->setPos(210, 130);

    scene_one->addItem(congrats);
    scene_one->addItem(message);

    QGraphicsPixmapItem* cup= new QGraphicsPixmapItem;
    cup->setPixmap(QPixmap(":/new/prefix1/cup.png"));
    cup->setScale(0.1);
    cup->setPos(370, 500);
    scene_one->addItem(cup);

    ///create a button and add it to the scene
    QPushButton* end= new QPushButton("Finish Game");
    end->setFont(QFont("lucida blackletter", 20));
    end->setGeometry(310, 400, 170, 90);
    scene_one->addWidget(end);

    QMediaPlayer* winning_music= new QMediaPlayer();
    winning_music->setMedia(QUrl("qrc:/new/prefix2/01 Fireworks.mp3"));
    winning_music->play();

    ///connect the end button with the slot close() to close the game
    connect(end, SIGNAL(clicked(bool)), this, SLOT(close()));
}

/**
 * This function displays the main menu at the beginning of the first task.
 * @brief RoundOne::displayMainMenu clears the scene, shows a welcome message, shows the instructions, and has QRadioButtons that let the player choose the level of difficulty and a start game QPushButton that starts the game.
 */
void RoundOne::displayMainMenu()
{   scene_one->clearFocus();
    scene_one->clear();

    main_widget= new QWidget;

    main_widget->setFixedSize(500,400);


    QLabel* welcome= new QLabel;
    welcome->setText("Welcome to the Triwizard Tournament");
    welcome->setFont(QFont("lucida blackletter", 24));
    welcome->setAlignment(Qt::AlignCenter);

    QLabel* ready= new QLabel;
    ready->setText("Get Ready to Start Task 1!");
    ready->setAlignment(Qt::AlignCenter);
    ready->setFont(QFont("lucida blackletter", 13));


    QLabel* instructions= new QLabel;
    instructions->setText("Instructions: Retrieve the Golden Egg without running into the dragon or getting hit by one of its fire balls! You can move left, right, up and down using the arrows on your keyboard. When you hit the space bar, you cast a spell that can blast the fireball out of your way. If you run into the dragon you die immediately and if you are hit with three fireballs, you die. Every time you blast a fireball out of the way, the judges give you a point. But every time you hit the dragon with your spell, he gets angry and the judges take a point away from your score. Try to earn as many points as possible to prove you are a real Triwizard Champion!");
    instructions->setWordWrap(true);
    instructions->setFont(QFont("lucida blackletter", 13));

    ///Add all QLabels to a layout
    QVBoxLayout* words= new QVBoxLayout;
    words->addWidget(welcome);
    words->addWidget(ready);
    words->addWidget(instructions);


    easy= new QRadioButton;
    easy->setText("Easy");
    medium= new QRadioButton;
    medium->setText("Medium");
    hard= new QRadioButton;
    hard->setText("Hard");

    ///add all QRadiobuttons to a layout
    QVBoxLayout* buttons= new QVBoxLayout;
    buttons->addWidget(easy);
    buttons->addWidget(medium);
    buttons->addWidget(hard);

    ///create the start QPushButton
    QPushButton* start= new QPushButton;
    start->setText("Start game");

    ///connect the start QPushButton with the slot start_game()
    connect(start, SIGNAL(clicked()), this, SLOT(start_game()));
    QHBoxLayout* layout= new QHBoxLayout;
    layout->addLayout(buttons);
    layout->addWidget(start);

    ///create the final layout
    QVBoxLayout* final_layout= new QVBoxLayout;
    final_layout->addLayout(words);
    final_layout->addLayout(layout);

    ///set the layout of the main widget
    main_widget->setLayout(final_layout);

    main_widget->show();

}

/**
 * This function is a public slot called when the player loses the first task.
 * @brief RoundOne::game_over clears the scene and calls the displayGameOverWindow function.
 */
void RoundOne::game_over(){
    scene_one->clear();
    flying_music->stop();
    QString message="You lose! You must be a Slytherin at heart!";
    displayGameOverWindow(message);

}

/**
 * This function is a public slot called when the player loses the second task
 * @brief RoundOne::game_over_round_two removes the seaweed in front of ron, to show him to the player. It stops the timer and calls displayGameOverWindowRoundTwo with the message.
 */
void RoundOne::game_over_round_two(){
    ///Remove the seaweed in front of Ron to reveal him
    scene_one->removeItem(p9);
    othertimer->stop();
    QString message="You lose! \nThe mermaids got you before you got Ron! \nYou must be a Slytherin at heart!";
    displayGameOverWindowRoundTwo(message);
}

/**
 * This function is a public slot called when the player wins the game, i.e. when player is at the same position as egg.
 * @brief RoundOne::win_round_one clears the scene and calls displayWinnerWindow with the message.
 */
void RoundOne::win_round_one(){
    scene_one->clear();
    flying_music->stop();
    QString message="You win! \n You are a true Triwizard champion!\n Get ready for the next round!";
    displayWinnerWindow(message);
}

/**
 * This function draws a panel depending on the inputs
 * @brief RoundOne::drawPanel draws a panel at the position (x, y) with width of width, height of height, color of color, and opacity of opacity.
 * @param x is the x() position of the top left corner of the panel
 * @param y is the y() position of the top left corner of the panel
 * @param width is the integer width of the panel
 * @param height is the integer height of the panel
 * @param color is the color of the panel
 * @param opacity is the percent opaque the panel is, between 0 and 1.
 */
void RoundOne::drawPanel(int x, int y, int width, int height, QColor color, double opacity)
{
    QGraphicsRectItem*panel= new QGraphicsRectItem(x, y, width, height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity);
    scene_one->addItem(panel);
}


