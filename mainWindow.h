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

//taken from the push example
namespace Ui
{
    class MainWindow;
}

//taken from the push example
class MainWindow : public QMainWindow
{
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
    void musicBeatButton();
    void redB();
    void blueB();
    void greenB();
    void purpleB();
    void s1B();
    void s2B();
    void s3B();
    void saveB();
    void loadB();
    void adjustBrightness();
    void refreshCurrentSel();
    void useCurrentSel();

private:
    std::ofstream fout;
    int slFlag;

    //to create widgets
    QWidget *widget;

    //elements of gui
    QTextEdit *current;

    QPushButton *breathB;
    QPushButton *trafficB;
    QPushButton *flashB;
    QPushButton *musictrafficB;
    QPushButton *musicbeatB;
    QPushButton *red;
    QPushButton *blue;
    QPushButton *green;
    QPushButton *purple;
    QPushButton *s1;
    QPushButton *s2;
    QPushButton *s3;
    QPushButton *save;
    QPushButton *load;

    QHBoxLayout *colourButtons;
    QHBoxLayout *saveload;
    QHBoxLayout *bright;
    QHBoxLayout *states;
    QVBoxLayout *controller;
    QBoxLayout *patternButtons;

    QLabel *colourLabel;
    QLabel *brightLabel;
    QLabel *controllerLabel;

    QSlider *brightness;

    std::array<std::string, 3> currentSel; //[0] contains brightness, [1] contains colour, [2] contains mode
};

#endif // MAINWINDOW_H
