#ifndef FILTERWIDGET_H
#define FILTERWIDGET_H
#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QFormLayout>

class FilterWidget: public QWidget {
    Q_OBJECT
    public:
    FilterWidget(QWidget *parent = nullptr);
    private:
    QLabel * filter;
    QComboBox* filterMenu;
    signals:
    void FilterChanged(const QString& filterChosen);
};
#endif