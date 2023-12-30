// mainwindow.cpp

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QMessageBox>


using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Create UI elements
    statusLabel = new QLabel("Welcome to Room Management", this);
    roomNumberLineEdit = new QLineEdit(this);
    manageRoomsButton = new QPushButton("Manage Rooms", this);

    // Set up UI layout
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(statusLabel);
    layout->addWidget(roomNumberLineEdit);
    layout->addWidget(manageRoomsButton);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    // Connect UI elements to slots
    connect(manageRoomsButton, &QPushButton::clicked, this, &MainWindow::on_manageRoomsButton_clicked);



    ui->setupUi(this);
    count = 0;  // Initialize roomsCount

    // Connect the buttons to their respective slots
    connect(ui->manageRoomsButton, &QPushButton::clicked, this, &MainWindow::on_manageRoomsButton_clicked);
    connect(ui->checkInButton, &QPushButton::clicked, this, &MainWindow::on_checkInButton_clicked);
    connect(ui->getAvailRoomButton, &QPushButton::clicked, this, &MainWindow::on_getAvailRoomButton_clicked);
    connect(ui->searchCustomerButton, &QPushButton::clicked, this, &MainWindow::on_searchCustomerButton_clicked);
    connect(ui->checkOutButton, &QPushButton::clicked, this, &MainWindow::on_checkOutButton_clicked);
    connect(ui->guestSummaryReportButton, &QPushButton::clicked, this, &MainWindow::on_guestSummaryReportButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
    // Delete UI elements in destructor
    delete statusLabel;
    delete roomNumberLineEdit;
    delete manageRoomsButton;
}

//idk what the fuck is this
Room::Room() {
    // Initialize your member variables if needed
}

// Implementation of the searchRoom function
void Room::searchRoom(int roomNumber) {
    // Your implementation here
    // You might want to print information about the room based on the roomNumber
    // For example, you could iterate through your array of rooms and find the matching room
    // Then print its details.
}

// Implementation of the displayRoom function
void Room::displayRoom(const Room& tempRoom) {
    // Your implementation here
    // Print information about the room based on the tempRoom object
    std::cout << "Room Number: " << tempRoom.roomNumber << std::endl;
    std::cout << "Type: " << tempRoom.type << std::endl;
    std::cout << "Status: " << tempRoom.status << std::endl;
    // Add more information as needed...
}


//idk what the fuck is this




void MainWindow::on_manageRoomsButton_clicked()
{
     QMessageBox::information(this, "Button Clicked", "Manage Rooms Button Clicked!");
    int opt, rno, i, flag = 0;
    char ch;

    do
    {
        cout << "\n### Manage Rooms ###";
        cout << "\n1. Add Room";
        cout << "\n2. Search Room";
        cout << "\n3. Back to Main Menu";
        cout << "\n\nEnter Option: ";
        cin >> opt;

        switch (opt)
        {
        case 1:
            cout << "\nEnter Room Number: ";
            cin >> rno;
            // i = 0;
            for (i = 0; i < count; i++)
            {
                if (rooms[i].roomNumber == rno)
                {
                    flag = 1;
                }
            }
            if (flag == 1)
            {
                cout << "\nRoom Number is Present.\nPlease enter a unique Number";
                flag = 0;
            }
            else
            {
                // rooms[count] == rooms[count].addRoom(rno);
                // rooms[count] == addRoom(rno);

                count++;
            }
            break;
        case 2:
            cout << "\nEnter room number: ";
            cin >> rno;
            rooms[count].searchRoom(rno);
            break;
        case 3:
            // Do nothing, go back to the main menu
            break;
        default:
            cout << "\nPlease Enter the correct option";
            break;
        }
    } while (opt != 3);
}

void MainWindow::on_checkInButton_clicked()
{
    if (count = 0)
    {
        cout << "\nRooms data is not available.\nPlease add the rooms first.";
    }
    else
    {
        int i, found = 0, rno;
        cout << "\nEnter Room number : ";
        cin >> rno;
        for (i = 0; i < count; i++)
        {
            if (rooms[i].roomNumber == rno)
            {
                found = 1;
                break;
            }
        }
        if (found == 1)
        {
            if (rooms[i].status == 1)
            {
                cout << "\nRoom is already Booked";
                return;
            }

            cout << "\nEnter booking id: ";
            cin >> rooms[i].cust.booking_id;

            cout << "\nEnter Customer Name (First Name): ";
            cin >> rooms[i].cust.name;

            cout << "\nEnter Address (only city): ";
            cin >> rooms[i].cust.address;

            cout << "\nEnter Phone: ";
            cin >> rooms[i].cust.phone;

            cout << "\nEnter From Date: ";
            cin >> rooms[i].cust.from_date;

            cout << "\nEnter to Date: ";
            cin >> rooms[i].cust.to_date;

            cout << "\nEnter Advance Payment: ";
            cin >> rooms[i].cust.payment_advance;

            rooms[i].status = 1;

            cout << "\n Customer Checked-in Successfully..";
        }
    }
}

void MainWindow::on_getAvailRoomButton_clicked()
{
    int i, found = 0;
    for (i = 0; i < count; i++)
    {
        if (rooms[i].status == 0)
        {
            rooms[count].displayRoom(rooms[i]);
            cout << "\n\nPress enter for next room";
            found = 1;
        }
    }
    if (found == 0)
    {
        cout << "\nAll rooms are reserved";
    }
}

void MainWindow::on_searchCustomerButton_clicked()
{
    if (count == 0)
    {
        cout << "\nRooms are not available.\nPlease add the rooms first.";
    }
    else
    {
        char pname[100];
        cout << "Enter Customer Name: ";
        cin >> pname;
        int i, found = 0;
        for (i = 0; i < count; i++)
        {
            if (rooms[i].status == 1 && strcmp(rooms[i].cust.name, pname) == 0)
            {
                cout << "\nCustomer Name: " << rooms[i].cust.name;
                cout << "\nRoom Number: " << rooms[i].roomNumber;

                cout << "\n\nPress enter for next record\n";
                found = 1;
            }
        }
        if (found == 0)
        {
            cout << "\nPerson not found.\n";
        }
    }
}

void MainWindow::on_checkOutButton_clicked()
{
    if (count == 0)
    {
        cout << "\nRooms are not available.\nPlease add the rooms first.";
    }
    else
    {
        int roomNum;
        cout << "Enter Room Number : ";
        cin >> roomNum;
        int i, found = 0, days;
        float billAmount = 0;
        for (i = 0; i < count; i++)
        {
            if (rooms[i].status == 1 && rooms[i].roomNumber == roomNum)
            {
                found = 1;
                break;
            }
        }
        if (found == 1)
        {
            cout << "\nEnter Number of Days:\t";
            cin >> days;
            billAmount = days * rooms[i].rent;

            cout << "\n\t######## CheckOut Details ########\n";
            cout << "\nCustomer Name : " << rooms[i].cust.name;
            cout << "\nRoom Number : " << rooms[i].roomNumber;
            cout << "\nAddress : " << rooms[i].cust.address;
            cout << "\nPhone : " << rooms[i].cust.phone;
            cout << "\nTotal Amount Due : " << billAmount << " /";
            cout << "\nAdvance Paid: " << rooms[i].cust.payment_advance << " /";
            cout << "\n*** Total Payable: " << billAmount - rooms[i].cust.payment_advance << "/ only";

            rooms[i].status = 0;
        }
    }
}

void MainWindow::on_guestSummaryReportButton_clicked()
{
    if (count == 0)
    {
        cout << "\n No Guest in Hotel !!";
    }
    for (int i = 0; i < count; i++)
    {
        if (rooms[i].status == 1)
        {
            cout << "\n Customer First Name : " << rooms[i].cust.name;
            cout << "\n Room Number : " << rooms[i].roomNumber;
            cout << "\n Address (only city) : " << rooms[i].cust.address;
            cout << "\n Phone : " << rooms[i].cust.phone;
            cout << "\n---------------------------------------";
        }
    }
}
