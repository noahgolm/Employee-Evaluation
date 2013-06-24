/**
 * @file CreateEmployerWin.cpp
 */

#include "createemployerwin.h"
#include <QVBoxLayout>
#include <QPushButton>
#include "employer.h"
#include "datainterface.h"
#include "labelfieldpair.h"
#include <QMessageBox>
#include <QGroupBox>
#include <QVBoxLayout>

/**
 * @brief Contructor to create all of our objects and place them on the window.
 * @param parent Parent widget.
 */
CreateEmployerWin::CreateEmployerWin(QWidget *parent) :
    QWidget(parent)
{
    //Set the window title.
    this->setWindowTitle("Create New Employer");

    //Put all of our new fields in the list of them.
    labelFieldPairs.push_back(new LabelFieldPair("Employer ID: "));
    labelFieldPairs.push_back(new LabelFieldPair("Company Name: "));
    labelFieldPairs.push_back(new LabelFieldPair("Street Address: "));
    labelFieldPairs.push_back(new LabelFieldPair("City: "));
    labelFieldPairs.push_back(new LabelFieldPair("State: "));
    labelFieldPairs.push_back(new LabelFieldPair("Zip Code: "));
    labelFieldPairs.push_back(new LabelFieldPair("Phone Number: "));
    labelFieldPairs.push_back(new LabelFieldPair("Email Address: "));
    labelFieldPairs.push_back(new LabelFieldPair("Contact Person: "));

    //Create our layout
    boxLayout = new QVBoxLayout();

    //=====
    // Each of these boxes contains our fields.
    // We use grid layout for multiple ones so our window isn't crowded
    //====


    //ID and name
    QGroupBox *nameBox = new QGroupBox();
    nameBox->setTitle("Name and ID");
    QGridLayout* nameBoxLayout = new QGridLayout();
    nameBox->setLayout(nameBoxLayout);
    nameBoxLayout->addWidget(labelFieldPairs.at(0), 0, 0);
    nameBoxLayout->addWidget(labelFieldPairs.at(1), 0, 1);
    boxLayout->addWidget(nameBox);

    //Location
    QGroupBox *locationBox = new QGroupBox();
    locationBox->setTitle("Location");
    QGridLayout* locationBoxLayout = new QGridLayout();
    locationBox->setLayout(locationBoxLayout);
    locationBoxLayout->addWidget(labelFieldPairs.at(2), 0, 0);
    locationBoxLayout->addWidget(labelFieldPairs.at(3), 0, 1);
    locationBoxLayout->addWidget(labelFieldPairs.at(4), 1, 0);
    locationBoxLayout->addWidget(labelFieldPairs.at(5), 1, 1);
    boxLayout->addWidget(locationBox);

    //Contact Info
    QGroupBox *contactBox = new QGroupBox();
    contactBox->setTitle("Contact");
    QGridLayout* contactBoxLayout = new QGridLayout();
    contactBox->setLayout(contactBoxLayout);
    contactBoxLayout->addWidget(labelFieldPairs.at(6), 0, 0);
    contactBoxLayout->addWidget(labelFieldPairs.at(7), 0, 1);
    contactBoxLayout->addWidget(labelFieldPairs.at(8), 1, 0);
    boxLayout->addWidget(contactBox);

    //Make the button
    saveButton = new QPushButton("Save Data");
    boxLayout->addWidget(saveButton);

    //Connect it being pressed to us saving all of the field data
    connect(saveButton, SIGNAL(released()), this, SLOT(saveData()));

    setLayout(boxLayout);
}

/**
 * @brief Saves our field data to the file as an employer object.
 */
void CreateEmployerWin::saveData()
{
    //Create the employer object out of all of our fields.
    Employer employer;
    employer.setID(labelFieldPairs.at(0)->getText().toInt());
    employer.setName(labelFieldPairs.at(1)->getText());
    employer.setLocation(labelFieldPairs.at(2)->getText(),
                         labelFieldPairs.at(3)->getText(),
                         labelFieldPairs.at(4)->getText(),
                         labelFieldPairs.at(5)->getText());
    employer.setPhoneNumber(labelFieldPairs.at(6)->getText());
    employer.setEmailAddress(labelFieldPairs.at(7)->getText());
    employer.setContact(labelFieldPairs.at(8)->getText());

    //Check if the ID is valid. If it is, write it to the file and alert the user that we're done. Then close.
    if(DataInterface::hasSameID(employer.getID(), DataInterface::employerFile))
    {
        QMessageBox::information(this, "Existing ID", "That ID number is already in use.\nPlease enter another number.");
    } else
    {
        DataInterface::writeEmployer(&employer);
        QMessageBox::information(this, "Employer Created", "The new employer was successfully saved.");
        this->close();
    }
}
