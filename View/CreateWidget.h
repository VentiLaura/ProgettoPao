#ifndef CREATEWIDGET_H
#define CREATEWIDGET_H

#include <QVBoxLayout>
#include <QObject>
#include <QWidget>
#include <vector>
#include "../LogicModel/Products/IncludeAllProducts.h"
#include"../LogicModel/Catalog/Memory.h"
#include <QLabel>
#include <QLineEdit>
#include <QStringList>
#include <QComboBox>
#include <QMessageBox>

class CreateWidget: public QWidget {
    Q_OBJECT
    public:
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

    QLineEdit* nameEdit;
    QLineEdit* priceEdit;
    QLineEdit* idEdit;
    QLineEdit* imageEdit;
    QLineEdit* copiesEdit;

    QLineEdit* franchiseEdit;
    QLineEdit* categoryEdit;
    QLineEdit* memoryEdit;
    QLineEdit* heightEdit;
    QLineEdit* lengthEdit;
    QLineEdit* depthEdit;
    QLineEdit* weightEdit;
    QLineEdit* producerEdit;
    QLineEdit* CompatibilityEdit;
    QLineEdit* GenreEdit;
    QComboBox* serieComboBox;
    QComboBox* sizeComboBox;

    signals:
    void cancelClicked();
    void acceptClicked();
};
#endif