#include "wingroupbox.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QString>

WinGroupBox::WinGroupBox(QString title, int numButtons, ...)
{
    this->setTitle(title);

    va_list args;
    va_start (args, numButtons);

    QVBoxLayout* boxLayout = new QVBoxLayout();

    for(int i = 0; i < numButtons; i++)
    {
        boxLayout->addWidget(va_arg(args, QPushButton*));
    }

    this->setLayout(boxLayout);
}
