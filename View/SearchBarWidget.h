#ifndef SEARCHBARWIDGET_H
#define SEARCHBARWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include "../LogicModel/Products/Product.h"
#include "../LogicModel/Catalog/Memory.h"

class SearchBarWidget : public QWidget {
    Q_OBJECT

private:
    QHBoxLayout* searchLayout;
    QLineEdit* searchBar;
    QPushButton* searchButton;

public:
    SearchBarWidget(QWidget* parent = nullptr);
    //std::vector<product::Product*> SearchProduct(const QString&);
    void search();

signals:
    void searchRequested(const QString& text);
};

#endif
