#include <iostream>
#include <vector>
#include <string>

class Account {
private:
    std::string accountNumber;
    std::string accountHolder;
    double balance;

public:
    Account(const std::string &accNum, const std::string &accHolder, double initialBalance)
        : accountNumber(accNum), accountHolder(accHolder), balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited: $" << amount << std::endl;
        } else {
            std::cout << "Invalid amount. Deposit failed." << std::endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Withdrawn: $" << amount << std::endl;
        } else {
            std::cout << "Invalid amount or insufficient balance. Withdrawal failed." << std::endl;
        }
    }

    void checkBalance() const {
        std::cout << "Account Balance: $" << balance << std::endl;
    }

    std::string getAccountNumber() const {
        return accountNumber;
    }

    std::string getAccountHolder() const {
        return accountHolder;
    }
};

class BankSystem {
private:
    std::vector<Account> accounts;

    Account* findAccount(const std::string &accNum) {
        for (auto &account : accounts) {
            if (account.getAccountNumber() == accNum) {
                return &account;
            }
        }
        return nullptr;
    }

public:
    void createAccount(const std::string &accNum, const std::string &accHolder, double initialBalance) {
        if (findAccount(accNum) != nullptr) {
            std::cout << "Account with number " << accNum << " already exists." << std::endl;
            return;
        }

        if (initialBalance < 0) {
            std::cout << "Initial balance cannot be negative." << std::endl;
            return;
        }

        accounts.emplace_back(accNum, accHolder, initialBalance);
        std::cout << "Account created successfully." << std::endl;
    }

    void deposit(const std::string &accNum, double amount) {
        Account* account = findAccount(accNum);
        if (account) {
            account->deposit(amount);
        } else {
            std::cout << "Account not found." << std::endl;
        }
    }

    void withdraw(const std::string &accNum, double amount) {
        Account* account = findAccount(accNum);
        if (account) {
            account->withdraw(amount);
        } else {
            std::cout << "Account not found." << std::endl;
        }
    }

    void checkBalance(const std::string &accNum) {
        Account* account = findAccount(accNum);
        if (account) {
            account->checkBalance();
        } else {
            std::cout << "Account not found." << std::endl;
        }
    }
};

int main() {
    BankSystem bank;
    
    // Create a sample account
    bank.createAccount("1234567890", "John Doe", 1000.0);
    std::cout << "Sample account created: Account number 1234567890 for John Doe with $1000.0 balance.\n";

    int choice;
    std::string accNum, accHolder;
    double amount;

    while (true) {
        std::cout << "\nBank System Menu:\n";
        std::cout << "1. Create Account\n";
        std::cout << "2. Deposit\n";
        std::cout << "3. Withdraw\n";
        std::cout << "4. Check Balance\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter account number: ";
            std::cin >> accNum;
            std::cin.ignore(); // Ignore the newline character left in the buffer
            std::cout << "Enter account holder name: ";
            std::getline(std::cin, accHolder);
            std::cout << "Enter initial balance: ";
            std::cin >> amount;
            bank.createAccount(accNum, accHolder, amount);
            break;
        case 2:
            std::cout << "Enter account number: ";
            std::cin >> accNum;
            std::cout << "Enter amount to deposit: ";
            std::cin >> amount;
            bank.deposit(accNum, amount);
            break;
        case 3:
            std::cout << "Enter account number: ";
            std::cin >> accNum;
            std::cout << "Enter amount to withdraw: ";
            std::cin >> amount;
            bank.withdraw(accNum, amount);
            break;
        case 4:
            std::cout << "Enter account number: ";
            std::cin >> accNum;
            bank.checkBalance(accNum);
            break;
        case 5:
            std::cout << "Exiting...\n";
            return 0;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
    }
}