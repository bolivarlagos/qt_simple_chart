#include "mainwindow.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QBarSet>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtWidgets>

QT_CHARTS_USE_NAMESPACE

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QBarSet *firstSet = new QBarSet("Jack");
    firstSet->append(10);
    firstSet->append(20);
    firstSet->append(30);

    QBarSet *secondSet = new QBarSet("John");
    *secondSet << 40 << 50 << 60;

    QBarSeries *series = new QBarSeries;
    series->append(firstSet);
    series->append(secondSet);

    QChart *chart = new QChart;
    chart->setTitle("Total Sales in 2024");
    chart->addSeries(series);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QStringList categories = { "Jan", "Feb", "Mar" };

    QBarCategoryAxis *axisX = new QBarCategoryAxis;
    axisX->append(categories);
    
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(0, 100);

    chart->addAxis(axisY, Qt::AlignLeft);    
    series->attachAxis(axisY);

    QChartView *chartView = new QChartView;
    chartView->setChart(chart);

    setCentralWidget(chartView);

    setWindowTitle("Simple Bar Chart");

    setMinimumSize(640, 480);
}
