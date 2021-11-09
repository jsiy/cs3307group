
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
#include <fstream>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    onOffFlag = 1; //1 indicates on
    slFlag = 0;    //0 indicates save/write
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

    onOffL = new QHBoxLayout;
    onoff = new QPushButton("On/Off", this);
    onOffL->addWidget(onoff);

    saveload = new QHBoxLayout;
    save = new QPushButton("Save", this);
    load = new QPushButton("Load", this);
    saveload->addWidget(save);
    saveload->addWidget(load);

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
    controller->addLayout(onOffL);
    controller->addLayout(saveload);
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

    connect(s1, &QPushButton::released, this, &MainWindow::s1B);
    connect(s2, &QPushButton::released, this, &MainWindow::s2B);
    connect(s3, &QPushButton::released, this, &MainWindow::s3B);

    connect(save, &QPushButton::released, this, &MainWindow::saveB);
    connect(load, &QPushButton::released, this, &MainWindow::loadB);

    connect(brightness, &QSlider::valueChanged, this, &MainWindow::adjustBrightness);
}

void MainWindow::refreshCurrentSel()
{
    std::string s = "";
    for (int i = 0; i < 3; i++)
    {
        s += currentSel[i];
        if (i != 2)
        {
            s += ", ";
        }
    }
    current->setText(QString::fromStdString(s));
}

void MainWindow::useCurrentSel()
{
    //brightness
    int val = std::stoi(currentSel[0]);
    brightness->setValue(val);
    //colour
    if (currentSel[1] == "Red")
    {
        redB();
    }
    else if (currentSel[1] == "Blue")
    {
        blueB();
    }
    else if (currentSel[1] == "Green")
    {
        greenB();
    }
    else if (currentSel[1] == "Purple")
    {
        purpleB();
    }
    //mode
    if (currentSel[2] == "Breath Lights")
    {
        breathButton();
    }
    else if (currentSel[2] == "Traffic Route Lights")
    {
        trafficButton();
    }
    else if (currentSel[2] == "Flashing Lights")
    {
        flashButton();
    }
    else if (currentSel[2] == "Music")
    {
        musicTrafficButton();
    }
    else if (currentSel[2] == "Music To The Beat")
    {
        musicBeatButton();
    }
}
void MainWindow::saveB()
{
    slFlag = 0;
}
void MainWindow::loadB()
{
    slFlag = 1;
}
void MainWindow::breathButton()
{
    QString temp = breathB->text();
    std::string buttonText = temp.toStdString();
    currentSel[2] = buttonText;
    refreshCurrentSel();
}

void MainWindow::trafficButton()
{
    QString temp = trafficB->text();
    std::string buttonText = temp.toStdString();
    currentSel[2] = buttonText;
    refreshCurrentSel();
}

void MainWindow::flashButton()
{
    QString temp = flashB->text();
    std::string buttonText = temp.toStdString();
    currentSel[2] = buttonText;
    refreshCurrentSel();
}

void MainWindow::musicTrafficButton()
{
    QString temp = musictrafficB->text();
    std::string buttonText = temp.toStdString();
    currentSel[2] = buttonText;
    refreshCurrentSel();
}

void MainWindow::musicBeatButton()
{
    QString temp = musicbeatB->text();
    std::string buttonText = temp.toStdString();
    currentSel[2] = buttonText;
    refreshCurrentSel();
}

void MainWindow::redB()
{
    QString temp = red->text();
    std::string buttonText = temp.toStdString();
    currentSel[1] = buttonText;
    refreshCurrentSel();
}
void MainWindow::blueB()
{
    QString temp = blue->text();
    std::string buttonText = temp.toStdString();
    currentSel[1] = buttonText;
    refreshCurrentSel();
}
void MainWindow::greenB()
{
    QString temp = green->text();
    std::string buttonText = temp.toStdString();
    currentSel[1] = buttonText;
    refreshCurrentSel();
}
void MainWindow::purpleB()
{
    QString temp = purple->text();
    std::string buttonText = temp.toStdString();
    currentSel[1] = buttonText;
    refreshCurrentSel();
}
//for load: getline and store in array/vector and then access the data structure
void MainWindow::s1B()
{
    if (slFlag == 0)
    {
        std::ofstream fout("state1.txt");
        for (int i = 0; i < 3; i++)
        {
            fout << currentSel[i];
            if (i != 2)
            {
                fout << ",";
            }
        }
        fout.close();
    }
    else if (slFlag == 1)
    {
        std::string line;
        std::ifstream fin("state1.txt");
        getline(fin, line);
        for (int i = 0; i < 3; i++)
        {
            int split = line.find(",");
            currentSel[i] = line.substr(0, split);
            line = line.substr(split + 1);
        }
        refreshCurrentSel();
        useCurrentSel();
    }
}
void MainWindow::s2B()
{
    if (slFlag == 0)
    {
        std::ofstream fout("state2.txt");
        for (int i = 0; i < 3; i++)
        {
            fout << currentSel[i];
            if (i != 2)
            {
                fout << ",";
            }
        }
        fout.close();
    }
    else if (slFlag == 1)
    {
        std::string line;
        std::ifstream fin("state2.txt");
        getline(fin, line);
        for (int i = 0; i < 3; i++)
        {
            int split = line.find(",");
            currentSel[i] = line.substr(0, split);
            line = line.substr(split + 1);
        }
        refreshCurrentSel();
        useCurrentSel();
    }
}
void MainWindow::s3B()
{
    if (slFlag == 0)
    {
        std::ofstream fout("state3.txt");
        for (int i = 0; i < 3; i++)
        {
            fout << currentSel[i];
            if (i != 2)
            {
                fout << ",";
            }
        }
        fout.close();
    }
    else if (slFlag == 1)
    {
        std::string line;
        std::ifstream fin("state3.txt");
        getline(fin, line);
        for (int i = 0; i < 3; i++)
        {
            int split = line.find(",");
            currentSel[i] = line.substr(0, split);
            line = line.substr(split + 1);
        }
        refreshCurrentSel();
        useCurrentSel();
    }
}
void MainWindow::adjustBrightness()
{
    int brightVal = brightness->value();
    std::string s = std::to_string(brightVal);
    currentSel[0] = s;
    refreshCurrentSel();
}

void MainWindow::onOffB()
{
    if (onOffFlag == 1)
    {
        onOffFlag = 0;
        currentSel = {"", "", ""};
    }
    else
    {
        onOffFlag = 1;
    }
}

/*
 *deconstructor used to clean up 
 */
MainWindow::~MainWindow()
{
}
