// CS3307A
// Group 14
// Deliverable 2
// Nov 9, 2021
// Joseph Siy
// Nada Elkelani
// Patrick Mihalcea
// Brian Cheng
// Usman Khan
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QLabel>
#include <QSlider>
#include <QHBoxLayout>
#include <QTextEdit>
#include <fstream>
#include <iostream>

using std::string;
using std::vector;

namespace Ui
{
    class MainWindow;
}

/*!
Class MainWindow contains the controller and all relevant UI elements, interacting with this interface will invoke methods that interact with the hardware.
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

    //Empty deconstructor for good form.
    ~MainWindow();

private slots:
    void breathButton();       /*! event listener for breathing lights button */
    void trafficButton();      /*! event listener for traffic lights button */
    void flashButton();        /*! event listener for flashing lights button */
    void musicTrafficButton(); /*! event listener for music traffic button */
    void musicBeatButton();    /*! event listener for music beat button */
    void redB();               /*! event listener for red button */
    void blueB();              /*! event listener for blue button */
    void greenB();             /*! event listener for green button */
    void purpleB();            /*! event listener for purple button */
    void s1B();                /*! event listener for state 1 button */
    void s2B();                /*! event listener for state 2 button */
    void s3B();                /*! event listener for state 3 button */
    void saveB();              /*! event listener for save button, sets save flag */
    void loadB();              /*! event listener for load button, sets load flag */
    void adjustBrightness();   /*! event listener for brightness slider */
    void refreshCurrentSel();  /*! refreshes the current selection */
    void useCurrentSel();      /*! simulates the pressing of all buttons in currentSel */
    void onOffB();             /*! event listener for on/off button */

private:
    std::ofstream fout; /*! file pointer to write to text files */
    int slFlag;         /*! flag save or load state */
    int onOffFlag;      /*! flag for on or off state */

    //elements of gui
    QTextEdit *current; /*! textedit box that displays current selection */

    QPushButton *breathB;       /*! breathing button */
    QPushButton *trafficB;      /*! traffic button */
    QPushButton *flashB;        /*! flash button */
    QPushButton *musictrafficB; /*! music traffic button */
    QPushButton *musicbeatB;    /*! music beat button */
    QPushButton *red;           /*! red button */
    QPushButton *blue;          /*! blue button */
    QPushButton *green;         /*! green button */
    QPushButton *purple;        /*! pruple button */
    QPushButton *s1;            /*! state 1 button */
    QPushButton *s2;            /*! state 2 button */
    QPushButton *s3;            /*! state 3 button */
    QPushButton *save;          /*! save button */
    QPushButton *load;          /*! load button */
    QPushButton *onoff;         /*! on and off button */

    QHBoxLayout *colourButtons; /*! layout container for the colour options */
    QHBoxLayout *saveload;      /*! layout container for the save and load buttons */
    QHBoxLayout *bright;        /*! layout container for the brightness slider */
    QHBoxLayout *states;        /*! layout container for the state buttons */
    QHBoxLayout *onOffL;        /*! layout container for the on and off buttons */
    QVBoxLayout *controller;    /*! layout container for entire controller */
    QBoxLayout *patternButtons; /*! layout container for the pattern buttons */

    QLabel *colourLabel;     /*! label for colour options */
    QLabel *brightLabel;     /*! label for brightness slider */
    QLabel *controllerLabel; /*! label for whole controller */

    QSlider *brightness; /*! brightness slider */

    std::array<std::string, 3> currentSel; /*! array containing the currently selected options, for use with the saving and loading feature. [0] contains brightness, [1] contains colour, [2] contains mode */
};

#endif // MAINWINDOW_H
