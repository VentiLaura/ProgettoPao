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
        void Callsort();
        void Callfilter();
        void CallSearch();
        std::vector<product::Product*> SearchProduct(const QString&, const std::vector<product::Product*>& );
    private:
    memory::Memory& mem = memory::Memory::getCentralMemoryInstance();
        SortFilterWidget *sortfilter = new SortFilterWidget;
        QString activeFilter;
        PageWidget* page;
        QString activeSort;
        QString activeSearch;

    private slots:
        void updateSort(const QString&); 
        void updateFilter(const QString&); 
        void UpdateSearch(const QString&);


    signals:
        void productsFiltered(const std::vector<product::Product*>&);
        void productsSorted(const std::vector<product::Product*>&);
        void productsSearched(const std::vector<product::Product*>&);
        void ReloadFilters();
};
#endif