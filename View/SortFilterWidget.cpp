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
}
void SortFilterWidget::filterModified(const QString& text){
        filter = new FilterWidget(this);
        connect(filter, &FilterWidget::FilterChanged,
        this, &SortFilterWidget::filterModified);
}
