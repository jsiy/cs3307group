
#include "mainWindow.h"
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QSlider>
#include <QStateMachine>
#include <QEventTransition>
#include <QPropertyAnimation>

using std::cout;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //lable the qt box so that the user knows its a light controller 
    QLabel *controllerLabel = new QLabel("Light Controller");
    controllerLabel->setAlignment(Qt::AlignCenter);


    //create the slider 
    QSlider *brightness = new QSlider(Qt::Horizontal);
    brightness->setRange(1,5);
    QLabel *brightLabel = new QLabel("Brightness");
    QHBoxLayout *bright = new QHBoxLayout;
    bright->addWidget(brightLabel);
    bright->addWidget(brightness);


    //creating the buttons:
    //the following will be on the same widet board
    QPushButton *breathB = new QPushButton("Breath Lights");
    QPushButton *trafficB = new QPushButton("Traffic Route Lights");
    QPushButton *flahsB = new QPushButton("Flashing Lights");
    QPushButton *musictrafficB = new QPushButton("Music");
    QPushButton *musicbeatB = new QPushButton("Music To The Beat");
    //QPushButton *solidB = new QPushButton("Solid Colours");


    QVBoxLayout *patternButtons = new QVBoxLayout;
    patternButtons->addWidget(breathB);
    patternButtons->addWidget(trafficB);
    patternButtons->addWidget(flahsB);
    patternButtons->addWidget(musictrafficB);
    patternButtons->addWidget(musicbeatB);
    //patternButtons->addWidget(solidB);



    //creating state machine
    QStateMachine *machine = new QStateMachine(this); 

    QState *s1 = new QState();
    QState *s2 = new QState(); 
    QState *s3 = new QState(); 

    QPropertyAnimation *animation;

     QLabel *label = new QLabel("Current state");
     QPushButton *stateButton = new QPushButton("Change State");

    s1->assignProperty(label, "text", "Current State : 1");
    s1->assignProperty(stateButton, "geometry", QRect(50,200,10,50));

    s2->assignProperty(label, "text", "Current State : 2");
    s2->assignProperty(stateButton, "geometry", QRect(50,200,10,50));

    s3->assignProperty(label, "text", "Current State : 3");
    s3->assignProperty(stateButton, "geometry", QRect(50,200,10,50));


    //creating the animation 
    animation = new QPropertyAnimation(stateButton, "geometry");
    animation->setEasingCurve(QEasingCurve::OutBounce);


    //adding events 
    QEventTransition *t1 = new QEventTransition(stateButton, QEvent::MouseButtonPress);
    t1->setTargetState(s2);
    t1->addAnimation(animation);
    s1->addTransition(t1);

    QEventTransition *t2 = new QEventTransition(stateButton, QEvent::MouseButtonPress);
    t2->setTargetState(s3);
    t2->addAnimation(animation);
    s2->addTransition(t1);

    QEventTransition *t3 = new QEventTransition(stateButton, QEvent::MouseButtonPress);
    t3->setTargetState(s1);
    t3->addAnimation(animation);
    s3->addTransition(t1);

    machine->addState(s1);
    machine->addState(s2);
    machine->addState(s3);
    machine->setInitialState(s1);
    machine->start();


































    //so how are we going to do this one? will we just have a section on our controller thats going to say pick a solid colour and then have a bunch of buttons for solid colours 
    //maybe we could create a widget on the main widget that has a bunch of colour buttons 
    //so instead of making one button called solidb like i have bellow: 
     //QPushButton *solidB = new QPushButton("Solid Colour");
    //we could do this 
    QPushButton *red = new QPushButton("Red");
    QPushButton *blue = new QPushButton("blue");
    QPushButton *green = new QPushButton("Green");
    QPushButton *purple = new QPushButton("Purple");
   //then we create a lable for the colours 
    QLabel *colourLabel = new QLabel("Solid Colours: ");
    //for example 
    //creating a horizontal widget to store all the possible colours 
    //this actually might be better as a vertical layout idk tho
    QHBoxLayout *colourButtons = new QHBoxLayout;
    colourButtons->addWidget(colourLabel);
    colourButtons->addWidget(red);
    colourButtons->addWidget(blue);
    colourButtons->addWidget(green);
    colourButtons->addWidget(purple);

    //creating the main widet box to add the above on the one widget as the controller 
    QVBoxLayout *controller = new QVBoxLayout;
    controller->addWidget(controllerLabel);
    controller->addLayout(bright);
    controller->addLayout(patternButtons);
    controller->addLayout(colourButtons);

    //this is going to make the controller the main widget
    QWidget *theWholeController = new QWidget;
    //set the controller to be the main 
    theWholeController->setLayout(controller); 
    //the central widget is going to be the widget in which contains the controller layout 
    setCentralWidget(theWholeController);
 
 
    //again, this could change depending on how we want to do the solid colour 
    connect(breathB, &QPushButton::released, this, &MainWindow::breathButton);
    connect(trafficB, &QPushButton::released, this, &MainWindow::trafficButton);
    connect(flahsB, &QPushButton::released, this, &MainWindow::flashButton);
    connect(musictrafficB, &QPushButton::released, this, &MainWindow::musicTrafficButton);
    connect(musicbeatB, &QPushButton::released, this, &MainWindow::musicBeatButton);
    //we would have to add more for the solid colours. 

    //connect(solidB, &QPushButton::released, this, &MainWindow::solidColourButton);

    connect(brightness, &QSlider::valueChanged, this, &MainWindow::adjustBrightness);

}

void MainWindow::breathButton()
{
    
}

void MainWindow::trafficButton()
{
    
}

void MainWindow::flashButton()
{
    
}

void MainWindow::musicTrafficButton()
{
    
}

void MainWindow::solidColourButton()
{
    //if we ended up making different buttons for each colour, we would get rid of this and add more buttons in the header file for the colours :) just depends on how we do stuff with the led class.
}


void MainWindow::musicBeatButton()
{
    
}

void MainWindow::adjustBrightness(){

}


/*
 *deconstructor used to clean up 
 */
MainWindow::~MainWindow(){

   
 
}
