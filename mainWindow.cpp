
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
#include <QPalette>
#include <string>

using std::cout;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    currentSel = {"", "", ""};
    std::string s = "";
    for (int i = 0; i < 3; i++)
    {
        s += currentSel[i];
        if (i != 2)
        {
            s += ", ";
        }
    }
    current = new QTextEdit(this);
    current->setText(QString::fromStdString(s));
    //lable the qt box so that the user knows its a light controller
    controllerLabel = new QLabel("Light Controller", this);
    controllerLabel->setAlignment(Qt::AlignCenter);

    //create the slider
    brightness = new QSlider(Qt::Horizontal, this);
    brightness->setRange(1, 10);
    brightLabel = new QLabel("Brightness", this);
    bright = new QHBoxLayout;
    bright->addWidget(brightLabel);
    bright->addWidget(brightness);

    //creating the buttons:
    //the following will be on the same widet board
    breathB = new QPushButton("Breath Lights", this);
    trafficB = new QPushButton("Traffic Route Lights", this);
    flashB = new QPushButton("Flashing Lights", this);
    musictrafficB = new QPushButton("Music", this);
    musicbeatB = new QPushButton("Music To The Beat", this);
    //QPushButton *solidB = new QPushButton("Solid Colours");

    patternButtons = new QVBoxLayout;
    patternButtons->addWidget(breathB);
    patternButtons->addWidget(trafficB);
    patternButtons->addWidget(flashB);
    patternButtons->addWidget(musictrafficB);
    patternButtons->addWidget(musicbeatB);
    //patternButtons->addWidget(solidB);

    states = new QHBoxLayout;
    s1 = new QPushButton("State 1", this);
    s2 = new QPushButton("State 2", this);
    s3 = new QPushButton("State 3", this);
    states->addWidget(s1);
    states->addWidget(s2);
    states->addWidget(s3);

    //so how are we going to do this one? will we just have a section on our controller thats going to say pick a solid colour and then have a bunch of buttons for solid colours
    //maybe we could create a widget on the main widget that has a bunch of colour buttons
    //so instead of making one button called solidb like i have bellow:
    //QPushButton *solidB = new QPushButton("Solid Colour");
    //we could do this
    red = new QPushButton("Red", this);
    blue = new QPushButton("Blue", this);
    green = new QPushButton("Green", this);
    purple = new QPushButton("Purple", this);
    //then we create a lable for the colours
    colourLabel = new QLabel("Solid Colours: ", this);
    //for example
    //creating a horizontal widget to store all the possible colours
    //this actually might be better as a vertical layout idk tho
    colourButtons = new QHBoxLayout;
    colourButtons->addWidget(colourLabel);
    colourButtons->addWidget(red);
    colourButtons->addWidget(blue);
    colourButtons->addWidget(green);
    colourButtons->addWidget(purple);

    //creating the main widet box to add the above on the one widget as the controller
    controller = new QVBoxLayout;
    controller->addWidget(controllerLabel);
    controller->addWidget(current);
    controller->addLayout(states);
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
    connect(flashB, &QPushButton::released, this, &MainWindow::flashButton);
    connect(musictrafficB, &QPushButton::released, this, &MainWindow::musicTrafficButton);
    connect(musicbeatB, &QPushButton::released, this, &MainWindow::musicBeatButton);

    connect(red, &QPushButton::released, this, &MainWindow::redB);
    connect(blue, &QPushButton::released, this, &MainWindow::blueB);
    connect(green, &QPushButton::released, this, &MainWindow::greenB);
    connect(purple, &QPushButton::released, this, &MainWindow::purpleB);
    //we would have to add more for the solid colours.

    //connect(solidB, &QPushButton::released, this, &MainWindow::solidColourButton);

    connect(brightness, &QSlider::valueChanged, this, &MainWindow::adjustBrightness);
}

void MainWindow::breathButton()
{
    QString temp = breathB->text();
    std::string buttonText = temp.toStdString();
    currentSel[2] = buttonText;
    std::string s = "";
    for (int i = 0; i < 3; i++)
    {
        s += currentSel[i];
        s += ", ";
    }
    current->setText(QString::fromStdString(s));
}

void MainWindow::trafficButton()
{
    QString temp = trafficB->text();
    std::string buttonText = temp.toStdString();
    currentSel[2] = buttonText;
    std::string s = "";
    for (int i = 0; i < 3; i++)
    {
        s += currentSel[i];
        s += ", ";
    }
    current->setText(QString::fromStdString(s));
}

void MainWindow::flashButton()
{
    QString temp = flashB->text();
    std::string buttonText = temp.toStdString();
    currentSel[2] = buttonText;
    std::string s = "";
    for (int i = 0; i < 3; i++)
    {
        s += currentSel[i];
        s += ", ";
    }
    current->setText(QString::fromStdString(s));
}

void MainWindow::musicTrafficButton()
{
    QString temp = musictrafficB->text();
    std::string buttonText = temp.toStdString();
    currentSel[2] = buttonText;
    std::string s = "";
    for (int i = 0; i < 3; i++)
    {
        s += currentSel[i];
        s += ", ";
    }
    current->setText(QString::fromStdString(s));
}

void MainWindow::musicBeatButton()
{
    QString temp = musicbeatB->text();
    std::string buttonText = temp.toStdString();
    currentSel[2] = buttonText;
    std::string s = "";
    for (int i = 0; i < 3; i++)
    {
        s += currentSel[i];
        s += ", ";
    }
    current->setText(QString::fromStdString(s));
}

void MainWindow::redB()
{
    QString temp = red->text();
    std::string buttonText = temp.toStdString();
    currentSel[1] = buttonText;
    std::string s = "";
    for (int i = 0; i < 3; i++)
    {
        s += currentSel[i];
        s += ", ";
    }
    current->setText(QString::fromStdString(s));
}
void MainWindow::blueB()
{
    QString temp = blue->text();
    std::string buttonText = temp.toStdString();
    currentSel[1] = buttonText;
    std::string s = "";
    for (int i = 0; i < 3; i++)
    {
        s += currentSel[i];
        s += ", ";
    }
    current->setText(QString::fromStdString(s));
}
void MainWindow::greenB()
{
    QString temp = green->text();
    std::string buttonText = temp.toStdString();
    currentSel[1] = buttonText;
    std::string s = "";
    for (int i = 0; i < 3; i++)
    {
        s += currentSel[i];
        s += ", ";
    }
    current->setText(QString::fromStdString(s));
}
void MainWindow::purpleB()
{
    QString temp = purple->text();
    std::string buttonText = temp.toStdString();
    currentSel[1] = buttonText;
    std::string s = "";
    for (int i = 0; i < 3; i++)
    {
        s += currentSel[i];
        s += ", ";
    }
    current->setText(QString::fromStdString(s));
}
void MainWindow::s1B()
{
}
void MainWindow::s2B()
{
}
void MainWindow::s3B()
{
}
void MainWindow::adjustBrightness()
{
    int brightVal = brightness->value();
    std::string s = std::to_string(brightVal);
    currentSel[0] = s;
    for (int i = 0; i < 3; i++)
    {
        s += currentSel[i];
        s += ", ";
    }
    current->setText(QString::fromStdString(s));
}

/*
 *deconstructor used to clean up 
 */
MainWindow::~MainWindow()
{
}
