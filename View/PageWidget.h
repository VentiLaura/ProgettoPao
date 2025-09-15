#ifndef PAGEWIDGET_H
#define PAGEWIDGET_H

#include <QWidget>
#include <vector>
#include <QScrollArea>
#include <QGridLayout>
#include "ProductWidget.h"
#include "../LogicModel/Products/IncludeAllProducts.h"
#include "PageWidget.h"
#include "DetailsPageWidget.h"
#include "CreateWidget.h"
#include "ModifyPageWidget.h"



class PageWidget : public QWidget {
    Q_OBJECT
    public:
    explicit PageWidget(const std::vector<product::Product*>&, QWidget* = nullptr);
    void updateProducts(const std::vector<product::Product*>&);
    void CloseAllWindows();
    //void showGrid();
    //void clearLayout(QLayout*); 
    void eraseGrid();
    void DeleteProduct();
    void callAddWindow(const QString&);
    void resetGrid();
     
    private:
    memory::Memory& mem=memory::Memory::getCentralMemoryInstance();
    std::vector<ProductWidget*> Products;
    std::vector<product::Product*> currentProducts;
    product::Product* selected=nullptr;
    ModifyPageWidget* AddWindow;
    DetailsPageWidget* detailsPage;
    QVBoxLayout* mainLayout;
    QScrollArea* scrollArea;
    QWidget* scrollContent;
    QGridLayout* gridLayout;
    void populateGrid(const std::vector<product::Product*>& products);
    public slots:
    void showProductDetails(product::Product* product);
    void showGrid();
    signals:
    void ReloadFilters();
    void Callsortfilter();
};

#endif