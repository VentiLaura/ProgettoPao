#ifndef PRODUCTWIDGET_H
#define PRODUCTWIDGET_H

#include <QWidget>
#include <QVBoxLayout>

//#include "Products/Product"
#include "Visitor/visitor.h"

class ProductWidget: public QWidget 
{
    public: 
        ProductWidget(QWidget *parent = nullptr);
    virtual void accept(Visitor* visitor) override
};
#endif