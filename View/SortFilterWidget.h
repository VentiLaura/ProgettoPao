#ifndef SORTFILTERWIDGET_H
#define SORTFILTERWIDGET_H
#include "SortWidget.h"
#include "FilterWidget.h"

class SortFilterWidget: public QWidget {
    public:
        SortFilterWidget (QWidget *parent=nullptr);
    private:
        SortWidget *sort;
        FilterWidget *filter;
};
#endif