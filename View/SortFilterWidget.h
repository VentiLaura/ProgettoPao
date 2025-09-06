#ifndef SORTFILTERWIDGET_H
#define SORTFILTERWIDGET_H
#include "SortWidget.h"
#include "FilterWidget.h"

class SortFilterWidget: public QWidget {
    Q_OBJECT
    public:
        SortFilterWidget (QWidget *parent=nullptr);
    private:
        SortWidget *sort;
        FilterWidget *filter;
    signals:
        void filterModified(const QString& text);
    private slots:
        void onFilterModified(const QString &text);
};
#endif