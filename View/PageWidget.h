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
    std::vector<product::Product*> currentProducts;
     
private:
    memory::Memory& mem=memory::Memory::getCentralMemoryInstance();
    product::Product* selected;
    DetailsPageWidget* detailsPage;
    QVBoxLayout* mainLayout;
    QScrollArea* scrollArea;
    QWidget* scrollContent;
    QGridLayout* gridLayout;
    CreateWidget* AddWidget=nullptr;
    std::vector<ProductWidget*> Products;
    ModifyPageWidget* mpw;
    void populateGrid(const std::vector<product::Product*>& products);
    //void AddProduct();
    public slots:
    void showProductDetails(product::Product* product);
    void showGrid();
    signals:
    void ReloadFilters();
    void Callsortfilter();
};

#endif