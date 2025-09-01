#ifndef PRODUCTWIDGET_H
#define PRODUCTWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPixmap>

//#include "Products/Product"
#include "Visitor/visitor.h"

class ProductWidget: public QWidget
{
    public: 
        ProductWidget(QWidget *parent = nullptr);
        virtual void accept(Visitor* visitor) = 0;

    private:
        QLabel *image = new QLabel;
};
#endif