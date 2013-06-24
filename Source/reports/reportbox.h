#ifndef REPORTVIEW_H
#define REPORTVIEW_H

#include <QGroupBox>
#include <QList>

class QTextEdit;
class Employee;
class QVBoxLayout;

class ReportBox : public QGroupBox
{
    Q_OBJECT
public:
    explicit ReportBox(int index, int totalNum);
    explicit ReportBox();

    int getNumBoxes();
protected:
    int reportIndex, totalReportSize;
    QTextEdit* display;
    QString displayText;

    void makeBox(QString text);
    QVBoxLayout *boxLayout;

    int numBoxes;
signals:
    
public slots:
    
};

#endif // REPORTVIEW_H
