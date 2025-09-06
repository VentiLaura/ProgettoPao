#ifndef FILTERWIDGET_H
#define FILTERWIDGET_H
#include <QWidget>
#include <QLabel>
#include <QComboBox>

class FilterWidget: public QWidget {
    Q_OBJECT
    public:
        FilterWidget(QWidget *parent = nullptr);
    private:
        QLabel * filter;
        QComboBox* filterMenu;
    private slots:
        void onFilterChanged(const QString&);

    signals:
        void FilterChanged(const QString& filterChosen);
};
#endif