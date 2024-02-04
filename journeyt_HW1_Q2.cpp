#include <iostream>
#include <string>

class Check {
public:
    // Default Constructor
    Check():checkNum(0),checkMemo(""),checkAmount(0){
        number++;
        checkNum = number;
    }

    // Setters
    void setCheckNum (int cn) {
        checkNum = cn;}
    void setCheckMemo (std::string cm) {
        checkMemo = cm;}
    void setCheckAmount (int ca) {
        checkAmount = ca;}

    // Getters
    int getCheckNum () {
        return checkNum;}
    std::string getCheckMemo () {
        return checkMemo;}
    float getCheckAmount () {
        return checkAmount;}

private:
    // Variable Dictionary
    static int number;
    int checkNum;
    std::string checkMemo;
    float checkAmount;
};

// Initialize number
int Check::number = 0;

class CheckBook {
public:
    // Default Constructor
    CheckBook():balance(0),numOfChecks(0),checkLimit(N) {}
    // Parameterized Constructor
    CheckBook(float initialBalance): balance(initialBalance), numOfChecks(0), checkLimit(N) {}

    // Creates a check and prompts the user for a memo while updating values
    bool writeCheck (float amount) {
        if (amount <= balance && numOfChecks < N && allChecks < 10) {
            std::string Memo;
            checks[numOfChecks].setCheckAmount(amount);
            std::cout << "Check Memo: ";
            std::cin >> Memo;
            checks[numOfChecks].setCheckMemo(Memo);

            balance -= amount;
            numOfChecks++;
            allChecks++;
            return true;
        }
        else return false;
    }

    // Generates list of checks
    void displayChecks() {
        std::cout << "List of Checks: " << std::endl;
        for (int i = numOfChecks - 1; i >= 0; --i) {
            std::cout << checks[i].getCheckAmount() << " " << checks[i].getCheckNum() << " " << checks[i].getCheckMemo() << std::endl;
        }
    }

    // Getter for allChecks
    float getallChecks () {
        return allChecks;}

    // Deposits money into account
    void deposit (float depositAmount) {
        balance += depositAmount;
    }

private:
    // Variable Dictionary
    static const int N = 5;
    static int allChecks;
    float balance;
    Check checks[N];
    int numOfChecks;
    const int checkLimit = N;
};

// Initialize Checkbook
int CheckBook::allChecks = 0;


int main() {

    CheckBook cb1(1000), cb2(500);
    for(int i=0; i<10;i++)
    {
        cb1.writeCheck(150);
        cb2.writeCheck(130);
    }
    std::cout<<"cb1 check details"<<std::endl;
    cb1.displayChecks();
    std::cout<<"cb2 check details"<<std::endl;
    cb2.displayChecks();
    std::cout<<cb1.getallChecks()<<std::endl;
    std::cout<<cb2.getallChecks()<<std::endl;


    return 0;
}
