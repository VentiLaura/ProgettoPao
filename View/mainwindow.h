#ifndef MAINWINDOW_H
#define MAINWINDOW_H
 
#include "SortFilterWidget.h" 
#include "MainRightWidget.h"
#include "PageContainerWidget.h"
#include "../JSON/JSONReader.h"

#include <QMainWindow>
#include <QPushButton>

#include <QDebug>


class MainWindow: public QMainWindow {
    Q_OBJECT
    public:
        MainWindow(QWidget *parent = nullptr);

    private:
    SortFilterWidget *leftWidget = new SortFilterWidget;
    MainRightWidget *rightWidget = new MainRightWidget;
};
#endif