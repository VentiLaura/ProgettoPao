#ifndef MAINWINDOW_H
#define MAINWINDOW_H
 
#include "SortFilterWidget.h" 
#include "MainRightWidget.h"

#include <QMainWindow>
#include <QPushButton>

class MainWindow: public QMainWindow {
    Q_OBJECT
    public:
        MainWindow(QWidget *parent = nullptr);

    private:
    SortFilterWidget *sortfilter = new SortFilterWidget;
    MainRightWidget *rightWidget = new MainRightWidget;
};
#endif