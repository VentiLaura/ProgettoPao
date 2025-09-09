#ifndef CREATEWRITABLEOBJECTWIDGET_H
#define CREATEWRITABLEOBJECTWIDGET_H
#include "Visitor/visitor.h"
#include "ProductModifier.h"
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
#include <QDebug>
class CreateWritableObjectWidget: public Visitor, public QWidget {
    public:
    //CreateWritableObjectWidget(QWidget* =nullptr);
    void visitVideogame(product::Videogame*);
    void visitConsole(product::Console*);
    void visitTshirt(product::T_shirt*);
    void visitCollectible(product::Collectible*);
    void visitAccessory(product::Accessory*);
    void Updateproduct();
    private:
    product::Product* newProduct;
    //ProductModifier* modifier;
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

    QLineEdit* nameEdit;
    QLineEdit* priceEdit;
    QLineEdit* idEdit;
    QLineEdit* imageEdit;
    QLineEdit* copiesEdit;
    QStringList genresList;

    QLineEdit* franchiseEdit;
    QLineEdit* sizeEdit;
    QLineEdit* categoryEdit;
    QLineEdit* serieEdit;
    QLineEdit* memoryEdit;
    QLineEdit* heightEdit;
    QLineEdit* lengthEdit;
    
    QLineEdit* producerEdit;
    QLineEdit* depthEdit;
    QLineEdit* weightEdit;
    QLineEdit* CompatibilityEdit;
    QLineEdit* GenreEdit;
    
};
#endif