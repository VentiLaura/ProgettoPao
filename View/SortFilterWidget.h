#ifndef SORTFILTERWIDGET_H
#define SORTFILTERWIDGET_H
#include "SortWidget.h"
#include "FilterWidget.h"
#include "SearchBarWidget.h"

class SortFilterWidget: public QWidget {
    Q_OBJECT
    public:
        SortFilterWidget (QWidget *parent=nullptr);
    private:
        SortWidget *sort;
        FilterWidget *filter;
        QWidget *sortFilter;
        SearchBarWidget *searchbar;
    signals:
        void filterModified(const QString& text);
        void sortModified(const QString& text);

    private slots:
        void onFilterModified(const QString &text);
        void onSortModified(const QString &text);

};
#endif