#ifndef PAGEWIDGET_H
#define PAGEWIDGET_H

#include <QWidget>
#include <vector>
#include <QScrollArea>
#include <QGridLayout>
#include "ProductWidget.h"
#include "../LogicModel/Products/IncludeAllProducts.h"
#include "DetailsPageWidget.h"
class DetailsPageWidget;


class PageWidget : public QWidget {
    Q_OBJECT

public:
    explicit PageWidget(const std::vector<product::Product*>&, QWidget* = nullptr);
     void updateProducts(const std::vector<product::Product*>&);
     //void showGrid();
     //void clearLayout(QLayout*); 
     
private:
    DetailsPageWidget* detailsPage;
    QVBoxLayout* mainLayout;
    QScrollArea* scrollArea;
    QWidget* scrollContent;
    QGridLayout* gridLayout;
    std::vector<product::Product*> currentProducts;
    std::vector<ProductWidget*> Products;
    void populateGrid(const std::vector<product::Product*>& products);
    public slots:
    void showProductDetails(product::Product* product);
    void showGrid();
};

#endif // PAGEWIDGET_H