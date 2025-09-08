#ifndef CREATEWRITABLEOBJECTWIDGET_H
#define CREATEWRITABLEOBJECTWIDGET_H
#include "Visitor/visitor.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QObject>
#include <QWidget>
#include <vector>
#include <QScrollArea>
#include <QGridLayout>
#include "ProductWidget.h"
#include "../LogicModel/Products/IncludeAllProducts.h"
#include "../LogicModel/Products/T-shirt.h"
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QStringList>
class CreateWritableObjectWidget: public Visitor, public QWidget {
    public:
    CreateWritableObjectWidget(QWidget* =nullptr);
    void visitVideogame(product::Videogame*);
    void visitConsole(product::Console*);
    void visitTshirt(product::T_shirt*);
    void visitCollectible(product::Collectible*);
    void visitAccessory(product::Accessory*);
    private:
    QVBoxLayout* layout;
    void createProduct(product::Product* product);
    product::Product* selected;
    QWidget* details;
    QWidget* bar;
    QVBoxLayout* pageLayout;
    QHBoxLayout* topBarLayout;
    QPushButton* cancelButton;
    QHBoxLayout* detailsLayout;
    QVBoxLayout* infoLayout;
    QPushButton* acceptButton;
};
#endif