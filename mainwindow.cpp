#include "mainwindow.h"
#include <QVBoxLayout>
#include "evaluation.h"

MainWindow::MainWindow() :
    QWidget()
{
    setWindowTitle("Employee Evaluator");
    resize(450, 500);

    layout = new QVBoxLayout();

    layout->addWidget(new Evaluation("Quality of Work"));
    layout->addWidget(new Evaluation("Work Habits"));

    this->setLayout(layout);
}
