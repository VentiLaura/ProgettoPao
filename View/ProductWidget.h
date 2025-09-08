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
    Q_OBJECT
    public: 
        ProductWidget(product::Product*, QWidget *parent = nullptr);
        signals:
        void clicked(product::Product* p);
    protected:
    void mousePressEvent(QMouseEvent* event) override;
    //void resizeEvent(QResizeEvent* event) override;
    private:
        QPixmap originalPixmap;
        product::Product* p;
        QLabel *image;
        QLabel *title;
        QLabel *price;

};
#endif