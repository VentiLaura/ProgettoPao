#ifndef CREATEWRITABLEOBJECTWIDGET_H
#define CREATEWRITABLEOBJECTWIDGET_H
#include "Visitor/visitor.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QObject>
#include <QWidget>
#include <vector>
#include "../LogicModel/Products/IncludeAllProducts.h"
#include <QLabel>
#include <QLineEdit>
#include <QStringList>
#include <QDebug>
class WritableWidget: public Visitor, public QWidget {
    public:
    //WritableWidget(QWidget* =nullptr);
    void visitVideogame(product::Videogame*);
    void visitConsole(product::Console*);
    void visitTshirt(product::T_shirt*);
    void visitCollectible(product::Collectible*);
    void visitAccessory(product::Accessory*);
    void Updateproduct();
    private:
    void createProduct(product::Product* product);
    product::Product* newProduct;
    product::Product* selected;
    QVBoxLayout* layout;
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