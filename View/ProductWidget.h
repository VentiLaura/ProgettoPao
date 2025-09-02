#ifndef PRODUCTWIDGET_H
#define PRODUCTWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPixmap>
#include "../LogicModel/Products/Product.h"
#include "Visitor/visitor.h"

class ProductWidget: public QWidget
{
    public: 
        ProductWidget(product::Product*, std::string, QWidget *parent = nullptr);
    private:
        product::Product* Product;
        QLabel *image = new QLabel;
        QLabel *title = new QLabel;
        QLabel *price = new QLabel;

};
#endif