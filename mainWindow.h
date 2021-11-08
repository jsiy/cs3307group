#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <iostream>
#include <vector>
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QHBoxLayout>


using std::string;
using std::vector;


//taken from the push example 
namespace Ui {
    class MainWindow;
}

//taken from the push example 
class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

    //Deconstructor incase any pointers need to be deleted to clean up space in the heap.
    ~MainWindow();


//taken from the push example 
private slots:
    void breathButton();
    void trafficButton();
    void flashButton();
    void musicTrafficButton();
    void solidColourButton();
    void musicBeatButton();
    void adjustBrightness();


private:
    
    //to create widgets 
    QWidget *widget;

    //to create buttons, we will end up creating 6 of these in the cpp file. 
    QPushButton *createButton;
  
    //main box for the controller - i made this a vertical one but we can change this if you guys want
    QVBoxLayout *mainB;

    //we could have the colour bottons on this widet or something (we can use another widget style i just picked a random, thoughts?)
    QHBoxLayout *colour;

    //here we would also include information from the LED light file once we make it 
    
};

#endif // MAINWINDOW_H
