/*
Name: Azmar Kashif
Section: B
Roll no: 22i-2716
*/
#include<iostream>
#include<cstring>
using namespace std;

class StudentAccount {
    char* name;
    float annualInterestRate;
    double savingBalance;
    char* accountNum;
    double *savors[100];
    int accountsOpen;
public:
    StudentAccount() {};
    StudentAccount(const char* name, float interest, double balance, const char* accountNum) {
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
        annualInterestRate = interest;
        savingBalance = balance;
        this->accountNum = new char[strlen(accountNum)+1];
        strcpy(this->accountNum, accountNum);
    }
    float calculateMonthlyInterest() {
        float cma;
        cma = savingBalance * annualInterestRate / 12;
        return cma;
    }
    void modifyInterestRate(float newValue) {
        annualInterestRate = newValue;
    }
    char* getAccountNum() {
        return accountNum;
    }
    double getSavingBalance() {
        return savingBalance;
    }
    void setSavingBalance(double currBalance) {
        savingBalance = currBalance;
    }
};
void OpenCustomerAccount(StudentAccount* savers[], int& accountsOpen, const char* NameVal, double balance) {
    if(accountsOpen >= 100){ //if number of accounts gets greater than or equal to 100 then we return
        cout << "The number of accounts has exceeded the limit" << endl;
        return;
    }
    char accountNum[5] = "SA00"; //storing account number in a char array of size 5
    /*
    this is how we will assign a different account number to new account
    */
    accountNum[2] = accountNum[2] + (accountsOpen / 10); 
    accountNum[3] = accountNum[3] + (accountsOpen % 10);
    savers[accountsOpen] = new StudentAccount(NameVal, 0, balance, accountNum); //dynamic array
    accountsOpen++; //increment accounts
    cout << "The account " << accountsOpen << " is opened with " << accountNum << " number" << endl; 
}

float calculateMonthlyInterest(StudentAccount* saver) { 
    return saver->calculateMonthlyInterest(); //return the calculated value
}

void modifyInterestRate(StudentAccount* saver, float newValue) { 
    saver->modifyInterestRate(newValue); //set the new value for interest rate in the class member function
}   

int SearchCustomer(StudentAccount* savers[], int accountsOpen, const char* accountNum) { //use const char* for the account number
    for (int i = 0; i < accountsOpen; i++) {
        int counterVar = 0;
        while (savers[i]->getAccountNum()[counterVar] != '\0' && accountNum[counterVar] != '\0') { //this loop continues until the terminating character for the account number
            if(savers[i]->getAccountNum()[counterVar] == accountNum[counterVar]) {
                counterVar++; //increment the counter to check the next character
            } else {
                break; //if account entered not equal to the account number we are searching for, we exit from the loop
            }
        }
        if(savers[i]->getAccountNum()[counterVar] == '\0' && accountNum[counterVar] == '\0') { //if both account numbers match until the end, we return the index
            return i;
        }
    }
    return -1; //if account not found we return -1
}

bool UpdateAccountBalance(StudentAccount* savers[], int accountsOpen, const char* accountNumVal, double balanceVal) {
    int index = SearchCustomer(savers, accountsOpen, accountNumVal);
    if(index != -1){ //if account is present
        savers[index]->setSavingBalance(balanceVal); //then we update the balance according to the savings
        return true;
    } else {
        return false;
    }
}
int main() {
    StudentAccount* savers[100]; // array of pointers to StudentAccount objects
    int accountsOpen = 0; // initialize number of accounts open
    OpenCustomerAccount(savers, accountsOpen, "Alice", 1000.0); // open account for Alice with initial balance of 1000.0
    OpenCustomerAccount(savers, accountsOpen, "Bob", 2000.0); // open account for Bob with initial balance of 2000.0
    int aliceIndex = SearchCustomer(savers, accountsOpen, "SA01"); // find index of Alice's account
    if (aliceIndex != -1) {
        float monthlyInterest = calculateMonthlyInterest(savers[aliceIndex]); // calculate monthly interest for Alice's account
        cout << "Monthly interest for Alice's account: " << monthlyInterest << endl;
        modifyInterestRate(savers[aliceIndex], 0.05); // modify interest rate for Alice's account
        UpdateAccountBalance(savers, accountsOpen, "SA01", 1500.0); // update balance for Alice's account
        cout << "Updated balance for Alice's account: " << savers[aliceIndex]->getSavingBalance() << endl;
    } else {
        cout << "Account not found" << endl;
    }
    return 0;
}