#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
class bank {
    public:
    string name;
    int id;
    string type;
    double balance;
    
    bank (string n, int i, string t, double b){
        name =n;
        id = i;
        type = t;
        balance = b;
    }


void display(){
    cout << "Name: " << name << endl
         << "id: " << id << endl
         << "Type: " << type << endl
         << "Balance: " << balance << endl;
}
 
 double deposit(double x){
      balance = balance + x;
      return balance;
 }
 double withdraw(double x){
    balance = balance - x;
    return balance;
 }
 void disbank(){
    cout << "Current Balance: " << balance;
 }
};
int main() {
    bank s1("Tinhy", 211, "savings", 500 );
    s1.display();
    s1.deposit(50);
    s1.withdraw(300);
    s1.disbank();
    
    return 0;
}