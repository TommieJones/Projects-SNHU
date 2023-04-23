#include <iostream>
#include <iomanip>
using namespace std;

class bankAccount {
    public:
        void setInterest(double interest);
        double getInterest();
        void setYears(int yearNumber);
        int getYears();
        void setDepositAmount(double depositAmount);
        double getDepositAmount();
        void setStartingFund(double startingFund);
        double getStartingFund();
        void printTitlesWithDep();
        void printTitlesInterest();

        void printWithDeposit();
        void printInterest();

    private:
        double interest;
        int years;
        double deposit;
        double fund;
        int i;
};
    void bankAccount::setInterest(double userInterest) {
        interest = userInterest;
    }
    double bankAccount::getInterest(){
        return interest;
    }

    void bankAccount::setYears(int userYears) {
        years = userYears;
    }
    int bankAccount::getYears() {
        return years;
    }

    void bankAccount::setDepositAmount(double userDeposit) {
        deposit = userDeposit;
    }
    double bankAccount::getDepositAmount() {
        return deposit;
    }

    void bankAccount::setStartingFund(double userFund) {
        fund = userFund;
    }
    double bankAccount::getStartingFund() {
        return fund;
    }
    
    void bankAccount::printTitlesInterest() {
         cout << setw (55) << "Balance and Interest without Monthly Deposits" 
        << endl;
       for(int i = 0; i < 65; ++i) { 
        putchar('=');}
        cout << endl << "Year" << setw(30) << "Year End Balance" << setw(30) <<
         "Yearly Interest" << endl;
         for(int i = 0; i < 65; ++i) { 
        putchar('-');}
        cout << endl;
        
    }

    void bankAccount::printTitlesWithDep(){
        cout << setw (55) << "Balance and Interest with Monthly Deposits" 
        << endl;
       for(i = 0; i < 65; ++i) { 
        putchar('=');}
        cout << endl << "Year" << setw(30) << "Year End Balance" << setw(30) <<
         "Yearly Interest" << endl;
         for(i = 0; i < 65; ++i) { 
        putchar('-');}
        cout << endl;
        
    }

    void bankAccount::printWithDeposit(){
        double tempfund;
        double yearlyInterestAmmount;

        for (i = 0; i < years; ++i) {
            yearlyInterestAmmount = 0;
            for (int j = 0; j < 12; ++j){
                double monthlyInterest = (tempfund + deposit) * 
                ((interest/100)/12);
                yearlyInterestAmmount = yearlyInterestAmmount + monthlyInterest;
                tempfund = tempfund + deposit + monthlyInterest;
            }
            cout << i + 1 << setw(30) << fixed << setprecision(2)
             << tempfund << setw(30) << yearlyInterestAmmount << endl;
        }
    }

    void bankAccount::printInterest(){
        double tempfund = fund;
        double tempinterest = interest;
       for (i = 0; i < years; ++i) {
       tempfund = tempfund + (tempfund + 0) * ((interest/100));
       tempinterest = tempfund * ((interest/100));
       cout << i + 1 << setw(30) << fixed << setprecision(2) << tempfund
        << setw(30) << tempinterest << endl;
       }
    }

    int main() {

    double userInterest;
    int userYears;
    double userDeposit;
    double userFund;

    bankAccount table; //one object created
    
    //Prompt user for entries and take input
    cout << "enter interest on bank account "; 
    cin >> userInterest;
    cout << "enter number of years to calculate ";
    cin >> userYears;
    cout << "enter monthly deposited ammount ";
    cin >> userDeposit;
    cout << "enter current fund ";
    cin >> userFund;

    table.setInterest(userInterest);
    table.setYears(userYears);
    table.setStartingFund(userFund);
    table.setDepositAmount(userDeposit);

    table.printTitlesInterest();
    table.printInterest();

    table.printTitlesWithDep();
    table.printWithDeposit();

    return 0;
    }

