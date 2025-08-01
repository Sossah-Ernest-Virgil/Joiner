#include <iostream>
#include <string>
#include <thread>   // for sleep_for
#include <chrono>   // for chrono::seconds
using namespace std;

struct User {
    string username;
    string id;
    string password;
    double balance;
};

void showMenu() {
    cout << "\n====================================\n";
    cout << "WELCOME TO SOSSAH INTERNATIONAL BANK\n";
    cout << "WE GIVE YOU SPECIAL SERVICES 24/7.\n";
    cout << "====================================\n";
    cout << "OPTIONS:\n1 - DEPOSIT\n2 - WITHDRAW\n3 - CHECK BALANCE\n4 - BACK TO OPTIONS\n5 - EXIT\n";
    cout << "====================================\n";
}

void endMessage() {
    cout << "\n=============================\n";
    cout << "THANKS FOR BANKING WITH US ????????\n";
    cout << "YOUR WEALTH OUR SUCCESS ???????\n";
    cout << "=============================\n";
}

int main() {
    User users[4] = {
        {"Ernest",   "0976", "Woods",   1000000000000.0},
        {"Richmond", "6789", "Richy_1", 10000000000.0},
        {"Gustave",  "1245", "Lamya",   10000000.0},
        {"Lordina",  "5431", "1234",    10000.0}
    };

    while (true) {
        showMenu();
        string inputUsername;
        cout << "Enter your Username: ";
        cin >> inputUsername;

        int userIndex = -1;
        for (int i = 0; i < 4; i++) {
            if (users[i].username == inputUsername) {
                userIndex = i;
                break;
            }
        }

        if (userIndex == -1) {
            cout << "? Wrong username! Try again.\n";
            continue;
        }

        string inputID;
        cout << "Enter your bank Identification number: ";
        cin >> inputID;
        if (inputID != users[userIndex].id) {
            cout << "? Invalid ID! Try again.\n";
            continue;
        }

        // ? Password check with increasing wait time
        int wait_time = 10;
        string inputPassword;

        while (true) {
            cout << "Enter password: ";
            cin >> inputPassword;

            if (inputPassword == users[userIndex].password) {
                cout << "? Hello " << users[userIndex].username << ", Welcome ?\n";
                break;
            } else {
                cout << "? Wrong password! Try again in " << wait_time << " seconds.\n";
                for (int i = wait_time; i > 0; i--) {
                    cout << "? Waiting... " << i << "s\r";
                    cout.flush();
                    this_thread::sleep_for(chrono::seconds(1));
                }
                cout << "\n";
                wait_time += 5; // increase waiting time for next attempt
            }
        }

        // ? Banking operations
        while (true) {
            int option;
            cout << "\nEnter option: ";
            cin >> option;

            if (option == 1) { // Deposit
                double amount;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                users[userIndex].balance += amount;
                cout << "Current Balance = $" << users[userIndex].balance << endl;
                endMessage();
                break;

            } else if (option == 2) { // Withdraw
                double amount;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                if (amount > users[userIndex].balance) {
                    cout << "? Insufficient funds!\n";
                } else {
                    users[userIndex].balance -= amount;
                }
                cout << "Current Balance = $" << users[userIndex].balance << endl;
                endMessage();
                break;

            } else if (option == 3) { // Check balance
                cout << "Current Balance = $" << users[userIndex].balance << endl;
                endMessage();
                break;

            } else if (option == 4) { // Back to menu
                break;

            } else if (option == 5) { // Exit
                cout << "Exiting...\n";
                return 0;

            } else {
                cout << "? Invalid option! Try again.\n";
            }
        }
    }
    return 0;
}
