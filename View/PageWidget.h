#ifndef PAGEWIDGET_H
#define PAGEWIDGET_H

#include <QWidget>
#include <vector>
#include <QScrollArea>
#include <QGridLayout>
#include "ProductWidget.h"
#include "../LogicModel/Products/Product.h"  // o product/Product.h, dipende da dove hai messo la classe

class PageWidget : public QWidget {
    Q_OBJECT

public:
    explicit PageWidget(const std::vector<product::Product*>& products, QWidget* parent = nullptr);
     void updateProducts(const std::vector<product::Product*>& products);
     std::vector<ProductWidget*> Products;
private:
    QScrollArea* scrollArea;
    QWidget* scrollContent;
    QGridLayout* gridLayout;

    void populateGrid(const std::vector<product::Product*>& products);
};

#endif // PAGEWIDGET_H