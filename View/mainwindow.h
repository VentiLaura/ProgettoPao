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
<<<<<<< HEAD
        SortFilterWidget *sortfilter = new SortFilterWidget;
        MainRightWidget *rightWidget = new MainRightWidget;

    private slots:
        void updateFilter(const QString& filter); 
    
=======
    SortFilterWidget *leftWidget = new SortFilterWidget;
    MainRightWidget *rightWidget = new MainRightWidget;
>>>>>>> 7bf26185ac194c13ee6d52153b10ebf9213ff26b
};
#endif