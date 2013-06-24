/**
 * @file CreateEmployerWin.h
 */

#ifndef CREATEEMPLOYERWIN_H
#define CREATEEMPLOYERWIN_H

#include <QWidget>
#include <QList>

//Forward Declarations
class QPushButton;
class QVBoxLayout;
class LabelFieldPair;

/**
 * @class CreateEmployerWin
 * @brief A window to create an employer and save it.
 */
class CreateEmployerWin : public QWidget
{
    Q_OBJECT
public:
    explicit CreateEmployerWin(QWidget* parent = 0);
    
private:
    QVBoxLayout* boxLayout;
    QList<LabelFieldPair*> labelFieldPairs; //Holds the fields that info goes into
    QPushButton *saveButton;
signals:
    
public slots:
    void saveData(); //Button pressed goes to this; saves the data to a file
    
};

#endif // CREATEEMPLOYERWIN_H
