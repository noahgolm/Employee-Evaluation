#include "evaluation.h"
#include <QSlider>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QLabel>

Evaluation::Evaluation(QString name)
{
    this->setTitle(name);

    QSlider *slide = new QSlider();
    slide->setRange(1, 5);
    slide->setOrientation(Qt::Horizontal);

    QTextEdit *edit = new QTextEdit("test");
    QLabel *editLabel = new QLabel();
    editLabel->setText("Comments:");

    QVBoxLayout* layout = new QVBoxLayout;

    layout->addWidget(slide);
    layout->addWidget(editLabel);
    layout->addWidget(edit);

    this->setLayout(layout);
}
