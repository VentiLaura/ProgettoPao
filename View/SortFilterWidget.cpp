#include "SortFilterWidget.h"
#include <QHBoxLayout> 
#include <QVBoxLayout> 
SortFilterWidget::SortFilterWidget(QWidget *parent): QWidget(parent){
        sortFilter = new QWidget(this);
        QVBoxLayout *leftLayout = new QVBoxLayout;        
        sort = new SortWidget(this);
        leftLayout->addWidget(sort);
        qDebug() << "SortWidget Costruito";
        filter = new FilterWidget(this); 
        leftLayout->addWidget(filter);
        sortFilter->setLayout(leftLayout);
        QHBoxLayout *layout = new QHBoxLayout;
        layout->addWidget(sortFilter);
        searchbar = new SearchBarWidget(this);
        layout->addWidget(searchbar);
        setLayout(layout);
        connect(filter, &FilterWidget::FilterChanged,
        this, &SortFilterWidget::filterModified);
        connect(sort, &SortWidget::SortChanged,
        this, &SortFilterWidget::sortModified);
}
void SortFilterWidget::onFilterModified(const QString& text){
        emit filterModified(text); 
}
void SortFilterWidget::onSortModified(const QString& text){
        emit sortModified(text); 
}
