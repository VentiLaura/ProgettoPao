#ifndef FILTERWIDGET_H
#define FILTERWIDGET_H
#include <QWidget>
#include <QLabel>
class FilterWidget: public QWidget {
    public:
        FilterWidget(QWidget *parent = nullptr);
    private:
        QLabel * filter;
    signals:
        void FilterChanged();
};
#endif