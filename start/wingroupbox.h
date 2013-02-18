#ifndef MAINWINBOX_H
#define MAINWINBOX_H

#include <QGroupBox>
#include <stdarg.h>

//Forward Declarations
class QVBoxLayout;
class QPushButton;
class QString;

class WinGroupBox : public QGroupBox
{
public:
    WinGroupBox(QString title, int numButtons, ...);

};

#endif // MAINWINBOX_H
