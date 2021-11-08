QT       += core widgets
TARGET = Controller
TEMPLATE = app 
SOURCES += Main.cpp mainWindow.cpp
HEADERS += mainWindow.h 
LIBS += -lboost_thread -lpthread 