#ifndef CREATEWIDGET_H
#define CREATEWIDGET_H

#include "Visitor/visitor.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QObject>
#include <QWidget>
#include <vector>
#include "../LogicModel/Products/IncludeAllProducts.h"
#include"../LogicModel/Catalog/Memory.h"
#include <QLabel>
#include <QLineEdit>
#include <QStringList>
#include <QDebug>
#include <QComboBox>

class CreateWidget: public QWidget {
    Q_OBJECT
    public:
    //WritableWidget(QWidget* =nullptr);
    CreateWidget(const QString&);
    product::Product* CreateProduct(const QString&);
    private:
    memory::Memory& mem=memory::Memory::getCentralMemoryInstance();
    void DeleteDetails();
    void VideogameWindow();
    void ConsoleWindow();
    void TshirtWindow();
    void CollectibleWindow();
    void AccessoryWindow();
    QWidget* Page;
    void createProduct(product::Product* product);
    product::Product* newProduct;
    product::Product* selected;
    QVBoxLayout* pageLayout;
    QWidget* bar;
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
    QComboBox* serieComboBox;
    QComboBox* sizeComboBox;

    QLineEdit* categoryEdit;
    QLineEdit* memoryEdit;
    QLineEdit* heightEdit;
    QLineEdit* lengthEdit;
    
    QLineEdit* producerEdit;
    QLineEdit* depthEdit;
    QLineEdit* weightEdit;
    QLineEdit* CompatibilityEdit;
    QLineEdit* GenreEdit;

    signals:
    void cancelClicked();
    void acceptClicked();
    
};
#endif