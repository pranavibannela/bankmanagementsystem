#include <iostream>
#include <vector>

using namespace std;

// BankAccount class to represent a single bank account

class BankAccount {
private:
    string name;
    int accountNum;
    double balance;

public:
    // Constructor to initialize the BankAccount object

    BankAccount(string n, int ac, double bal) {
        name = n;
        accountNum = ac;
        balance = bal;
    }

    // Getter methods to access private member variables
    string getName() {
        return name;
    }

    int getAccountNum() {
        return accountNum;
    }

    double getBalance() {
        return balance;
    }

    // Method to deposit money into the account
    void deposit(double amount) {
        balance += amount;
    }

    // Method to withdraw money from the account
    void withdraw(double amount) {
        if (balance >= amount) {
            cout << "\t\t\t Successfully Withdrawn" << endl;
            balance -= amount;
        } else {
            cout << "\t\t\tInsufficient balance" << endl;
        }
    }
};

// BankManagement class to manage multiple bank accounts
class BankManagement {
private:
    vector<BankAccount> accounts;

public:
    // Method to add a new account to the list
    void addAccount(string name, int accountNum, double balance) {
        // Create a new BankAccount object and add it to the vector
        accounts.push_back(BankAccount(name, accountNum, balance));
    }

    // Method to display information about all accounts
    void showAllAccounts() {
        cout << "\t\t\t All account holders" << endl;
        for (int i = 0; i < accounts.size(); i++) {
            cout << "Name: " << accounts[i].getName() << ", Account number: " << accounts[i].getAccountNum()
                 << ", Balance: " << accounts[i].getBalance() << endl;
        }
    }

    // Method to search for an account based on the account number
    void searchAccount(int accountNum) {
        cout << "\t\t\t Account holder" << endl;
        for (int i = 0; i < accounts.size(); i++) {
            if (accounts[i].getAccountNum() == accountNum) {
                cout << "Name: " << accounts[i].getName() << ", Account number: " << accounts[i].getAccountNum()
                     << ", Balance: " << accounts[i].getBalance() << endl;
            }
        }
    }

    // Method to find an account based on the account number and return a pointer to it
    BankAccount* findAccount(int accountNum) {
        for (int i = 0; i < accounts.size(); i++) {
            if (accounts[i].getAccountNum() == accountNum) {
                // Return a pointer to the BankAccount object if found
                return &accounts[i];
            }
        }
        // Return NULL if account number not found
        return NULL;
    }
};

int main() {
    BankManagement bank;
    int choice;
    char opt;
    do {
        system("clear"); // Clears the console screen
        cout << "\t\t\t Bank Management System" << endl;
        cout << "\t\t\t\t Main Menu" << endl;
        // Displaying menu options
        cout << "\t\t\t 1. Create New Account" << endl;
        cout << "\t\t\t 2. Show all accounts" << endl;
        cout << "\t\t\t 3. Search Account" << endl;
        cout << "\t\t\t 4. Deposit Money" << endl;
        cout << "\t\t\t 5. Withdraw Money" << endl;
        cout << "\t\t\t 6. EXIT" << endl;
        cout << "\t\t\t----------------------------------" << endl;
        cout << "\t\t\t Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                // Adding a new account
                string name;
                int accountNum;
                double balance;

                cout << "\t\t\t Enter Name: ";
                cin >> name;
                cout << "\t\t\t Enter account number: ";
                cin >> accountNum;
                cout << "\t\t\t Enter Initial Balance: ";
                cin >> balance;
                bank.addAccount(name, accountNum, balance);
                cout << "\t\t\t Account created successfully" << endl;

                break;
            }
            case 2: {
                // Displaying all accounts
                bank.showAllAccounts();
                break;
            }
            case 3: {
                // Searching for an account
                int accountNum;
                cout << "Enter account number: ";
                cin >> accountNum;
                bank.searchAccount(accountNum);
                break;
            }
            case 4: {
                // Depositing money into an account
                int accountNum;
                double amount;
                cout << "\t\t\t Enter account number to deposit money: ";
                cin >> accountNum;
                BankAccount* account = bank.findAccount(accountNum);
                if (account != NULL) {
                    cout << "\t\t\t Enter amount to deposit: ";
                    cin >> amount;
                    account->deposit(amount);
                    cout << "\t\t\t" << amount << " deposited successfully" << endl;
                } else {
                    cout << "\t\t\t Account not found" << endl;
                }
                break;
            }
            case 5: {
                // Withdrawing money from an account
                int accountNum;
                double amount;
                cout << "\t\t\t Enter account number to withdraw money: ";
                cin >> accountNum;
                BankAccount* account = bank.findAccount(accountNum);
                if (account != NULL) {
                    cout << "\t\t\t Enter amount to withdraw: ";
                    cin >> amount;
                    account->withdraw(amount);
                    cout << "\t\t\t" <<  amount << " Withdrawn successfully" << endl;
                } else {
                    cout << "\t\t\t Account not found" << endl;
                }
                break;
            }
            case 6: {
                exit(0); // Use exit(0) for a clean exit without any errors
                break;
            }
        }
        cout << "\t\t\t Do you want to continue? [Y/N] ";
        cin >> opt;

    } while (opt == 'Y' || opt == 'y');
    return 0;
}
