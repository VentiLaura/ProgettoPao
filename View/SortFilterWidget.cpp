#include "SortFilterWidget.h"
SortFilterWidget::SortFilterWidget(QWidget *parent): QWidget(parent){
        setStyleSheet("background-color: lightblue;");
        sortFilter=new QWidget(this);
        QVBoxLayout *leftLayout = new QVBoxLayout;        
        sort=new SortWidget(this);
        leftLayout->addWidget(sort);
        filter=new FilterWidget(this); 
        leftLayout->addWidget(filter);
        sortFilter->setLayout(leftLayout);
        QHBoxLayout *layout=new QHBoxLayout;
        layout->addWidget(sortFilter, 2);
        searchbar=new SearchBarWidget(this);
        layout->addWidget(searchbar, 7);
        addComboBox=new QComboBox(this);
        addComboBox->addItem("Aggiungi prodotto...");
        QStringList productTypes={"Accessory", "Collectible", "Console", "T-shirt", "Videogame"};
        for (const QString& type : productTypes) {
                addComboBox->addItem(type);
        }
        layout->addWidget(addComboBox, 1);
        setLayout(layout);
        connect(addComboBox, &QComboBox::currentIndexChanged, this, &SortFilterWidget::onAddComboBoxChanged);
        connect(filter, &FilterWidget::FilterChanged, this, &SortFilterWidget::onFilterModified);
        connect(sort, &SortWidget::SortChanged, this, &SortFilterWidget::onSortModified);
        connect(searchbar, &SearchBarWidget::searchRequested, this, &SortFilterWidget::searchModified);        
}
void SortFilterWidget::onFilterModified(const QString& text){
        emit filterModified(text); 
}
void SortFilterWidget::onSortModified(const QString& text){
        emit sortModified(text); 
}

void SortFilterWidget::onAddComboBoxChanged(int index) {
    if (index == 0) return;
    QString selectedType = addComboBox->itemText(index);
    emit AddClicked(selectedType);
    addComboBox->setCurrentIndex(0);
}

