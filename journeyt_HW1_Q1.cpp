#include <iostream>
#include <string>

// Creates check struct
struct Check{
    int CheckNum;
    std::string CheckMemo;
    float CheckAmount;
};

class CheckBook {
public:
    // Default Constructor
    CheckBook():balance(0),numOfChecks(0){}
    // Parameterized Constructor
    CheckBook(float initialBalance): balance(initialBalance), numOfChecks(0) {}

    // Deposits money into account
    void deposit (float depositAmount) {
        balance += depositAmount;
        lastDeposit = depositAmount;
    }

    // Generates list of checks
    void displayChecks() {
        std::cout << "List of Checks: " << std::endl;
        for (int i = numOfChecks -1; i >= 0; --i) {
            std::cout << "Check " << checks[i].CheckNum << ": $" << checks[i].CheckAmount << std::endl;
            std::cout << "Memo: " << checks[i].CheckMemo << std::endl << "---------------------" << std::endl;
        }
    }


    // Creates a check and prompts the user for a memo while updating values
    bool writeCheck (float amount) {
        if (amount <= balance && numOfChecks <= checkLimit) {
            checks[numOfChecks].CheckNum = numOfChecks + 1;
            std::cout << "Check Memo: ";
            std::cin >> checks[numOfChecks].CheckMemo;
            checks[numOfChecks].CheckAmount = amount;

            balance -= amount;
            numOfChecks++;
            return true;
        }
        else return false;
    }

private:
    // Variable Dictionary
    static const int N = 5;
    float balance;
    Check checks[N];
    float lastDeposit;
    int numOfChecks;
    const int checkLimit = N;
};

int main() {

    // Test the CheckBook class
    CheckBook myCheckBook;

    // Deposit money
    myCheckBook.deposit(1000);

    // Write checks
    myCheckBook.writeCheck(200);
    myCheckBook.writeCheck(150);

    // Display checks
    myCheckBook.displayChecks();

    // Write more checks
    myCheckBook.writeCheck(300);
    myCheckBook.writeCheck(50);
    myCheckBook.writeCheck(500);

    // Display all checks
    myCheckBook.displayChecks();

    return 0;
}
