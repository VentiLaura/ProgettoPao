#include "SortFilterWidget.h"
#include <QHBoxLayout> 
#include <QVBoxLayout>
#include <QMenu> 
SortFilterWidget::SortFilterWidget(QWidget *parent): QWidget(parent){
        setStyleSheet("background-color: lightblue;");
        sortFilter = new QWidget(this);
        QVBoxLayout *leftLayout = new QVBoxLayout;        
        sort = new SortWidget(this);
        leftLayout->addWidget(sort);
        qDebug() << "SortWidget Costruito";
        filter = new FilterWidget(this); 
        leftLayout->addWidget(filter);
        sortFilter->setLayout(leftLayout);
        QHBoxLayout *layout = new QHBoxLayout;
        layout->addWidget(sortFilter, 2);
        searchbar = new SearchBarWidget(this);
        layout->addWidget(searchbar, 7);


        addComboBox = new QComboBox(this);
        addComboBox->addItem("Aggiungi prodotto..."); // Placeholder

        QStringList productTypes = { "Accessory", "Collectible", "Console", "T-shirt", "Videogame" };
        for (const QString& type : productTypes) {
        addComboBox->addItem(type);
        }

        connect(addComboBox, &QComboBox::currentIndexChanged, this, &SortFilterWidget::onAddComboBoxChanged);
        layout->addWidget(addComboBox, 1);


        setLayout(layout);
        connect(filter, &FilterWidget::FilterChanged, this, &SortFilterWidget::filterModified);
        connect(sort, &SortWidget::SortChanged, this, &SortFilterWidget::sortModified);
        //connect(this, &SortFilterWidget::Reload, filter, &FilterWidget::Reload);
        //connect(this, &SortFilterWidget::Reload, sort, &SortWidget::Reload);
}
void SortFilterWidget::onFilterModified(const QString& text){
        emit filterModified(text); 
}
void SortFilterWidget::onSortModified(const QString& text){
        emit sortModified(text); 
}


void SortFilterWidget::onAddComboBoxChanged(int index) {
    if (index == 0) return; // Ignora la voce "Aggiungi prodotto..."

    QString selectedType = addComboBox->itemText(index);

    emit AddClicked(selectedType);

    // Reset dopo la selezione per permettere aggiunte multiple
    addComboBox->setCurrentIndex(0);
}

