#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QWidget>
#include "SortFilterWidget.h" 
#include "PageWidget.h"
#include "../LogicModel/Catalog/Filter.h"
#include "../Utility/FilterFunctions.h"
#include "../Utility/SortFunctions.h"
#include "../XML/XMLReader.h"
#include "../JSON/JSONReader.h"

class MainWindow: public QMainWindow {
    Q_OBJECT
    public:
    MainWindow(QWidget *parent = nullptr);
    void CallAddWindow(const QString&);
    void Callfilter();
    std::vector<product::Product*> SearchProduct(const QString&, const std::vector<product::Product*>& );
    private:
    memory::Memory& mem = memory::Memory::getCentralMemoryInstance();
    SortFilterWidget *sortfilter;
    PageWidget* page;
    QVBoxLayout* MainLayout;
    QString activeFilter;
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
