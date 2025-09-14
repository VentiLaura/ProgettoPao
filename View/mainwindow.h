#ifndef MAINWINDOW_H
#define MAINWINDOW_H
 
#include "SortFilterWidget.h" 
#include "PageWidget.h"
#include "../JSON/JSONReader.h"
#include "../LogicModel/Catalog/Filter.h"
#include <QVBoxLayout>
#include <QWidget>
#include "../Utility/FilterFunctions.h"
#include "../Utility/SortFunctions.h"
#include "../XML/XMLReader.h"

#include <QMainWindow>
#include <QPushButton>

#include <QDebug>


class MainWindow: public QMainWindow {
    Q_OBJECT
    public:
        MainWindow(QWidget *parent = nullptr);
        void CallAddWindow(const QString&);
        //handleAddProduct(QString);

    private:
        SortFilterWidget *sortfilter = new SortFilterWidget;
        QString activeFilter;
        PageWidget* page;
        QString activeSort;

    private slots:
        void updateSort(const QString& sort); 
        void updateFilter(const QString& filter); 


    signals:
        void productsFiltered(const std::vector<product::Product*>&);
        void productsSorted(const std::vector<product::Product*>&);
        void ReloadFilters();
};
#endif