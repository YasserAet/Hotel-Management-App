// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
// #define max 100


#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

namespace Ui {
class MainWindow;
}



class Room {
public:
    char type;
    char stype;
    char ac;
    int roomNumber;
    int rent;
    int status;

    Room();  // Default constructor
    Room(int roomNumber, char type, char stype, char ac, int rent, int status);  // Parameterized constructor
    // Default constructor definition
    // Room()
    // {
    //     // Initialize member variables if needed
    //     type = 'A';
    //     stype = 'S';
    //     ac = 'N';
    //     roomNumber = 0;
    //     rent = 0;
    //     status = 0;
    // }


    void addRoom(int roomNumber);
    void searchRoom(int roomNumber);
    void displayRoom(const Room& tempRoom);  // Use const reference for efficiency

    class Customer
    {
    public:
        char name[100];
        char address[100];
        char phone[12];
        char from_date[20];
        char to_date[20];
        float payment_advance;
        int booking_id;
    };

    Customer cust; // Member 'cust' inside 'Room'

};



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_manageRoomsButton_clicked();
    void on_checkInButton_clicked();
    void on_getAvailRoomButton_clicked();
    void on_searchCustomerButton_clicked();
    void on_checkOutButton_clicked();
    void on_guestSummaryReportButton_clicked();
private:
    Ui::MainWindow *ui;
    QLabel *statusLabel;
    QLineEdit *roomNumberLineEdit;
    QPushButton *manageRoomsButton;
    Room rooms[100];
    int count;
};

#endif // MAINWINDOW_H
