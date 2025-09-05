#ifndef MAINWINDOW_H
#define MAINWINDOW_H
 
#include "SortFilterWidget.h" 
#include "MainRightWidget.h"
#include "PageContainerWidget.h"
#include "../JSON/JSONReader.h"
#include "../LogicModel/Catalog/Filter.h"


#include <QMainWindow>
#include <QPushButton>

#include <QDebug>


class MainWindow: public QMainWindow {
    Q_OBJECT
    public:
        MainWindow(QWidget *parent = nullptr);

    private:
        SortFilterWidget *sortfilter = new SortFilterWidget;
        MainRightWidget *rightWidget = new MainRightWidget;

    private slots:
        void updateFilter(const QString& filter); 

    signals:
        void productsFiltered(const std::vector<product::Product*>&);
    
};
#endif