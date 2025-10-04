#include<iostream>
#include<cstdlib>
using namespace std;

void showbalance(double balance){
    cout << "Your balance is: " << balance << endl;
}

double deposit(double balance){
    double amount = 0;
    cout << "Enter the amount you want to deposit: ";
    cin >> amount;
    balance = balance + amount;
    cout << "Your current balance is: " << balance << endl;
    return balance;
}

double withdraw(double balance){
    double amount = 0;
    cout << "Enter the amount you want to witwithdraw: ";
    cin >> amount ;
    if ( amount <= balance){
        balance -= amount;
    }
    else{
        cout << "Insufficient funds!" << endl;
    }
    cout << "Your current balance is :" << balance  ;
    return balance;
}

int main(){
    double balance = 0;
    int choice = 0;
      do {
        cout << "**************"<<endl;
        cout << "Enter your choice" << endl;
        cout << "*****************" << endl;
        cout << "1. Show your balance"<< endl;
        cout << "2. Deposit your money" << endl;
        cout << "3. Withdraw your money" << endl;
        cout << "4. Exit " << endl;
        cin >> choice;
        
        switch(choice){
            case 1: showbalance(balance);
                    break;
            case 2: balance = deposit(balance);
                    break;
            case 3: balance = withdraw(balance);
                    break;
            case 4: cout << "Thanks for visiting";
                    break;
            default: cout << "Invalid option";
        }
        
            }
        while(choice !=4);
        
      
    return 0;
}