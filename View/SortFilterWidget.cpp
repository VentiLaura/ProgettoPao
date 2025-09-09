#include "SortFilterWidget.h"
#include <QVBoxLayout> 
SortFilterWidget::SortFilterWidget(QWidget *parent): QWidget(parent){
        QVBoxLayout *leftLayout = new QVBoxLayout;
        sort = new SortWidget(this);
        leftLayout->addWidget(sort);
        qDebug() << "SortWidget Costruito";
        filter = new FilterWidget(this); 
        leftLayout->addWidget(filter);
        setLayout(leftLayout);
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
