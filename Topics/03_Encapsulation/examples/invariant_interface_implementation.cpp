#include<iostream>

class BankAccount{
private:
    double balance;

public:
    BankAccount(double initialBalance)
        : balance(initialBalance)
    {
    }

    void deposit(double amount){
        if (amount > 0)
            balance += amount;
    }

    bool withdraw(double amount){
        if (amount > 0 && amount <= balance){
            balance -= amount;
            return true;
        }
        return false;
    }

    double getBalance() const{
        return balance;
    }
};

int main(){
    BankAccount account(10000);

    account.deposit(5000);

    std::cout << "Balance : " << account.getBalance() << '\n';
    
    account.withdraw(2500);

    std::cout << "Balance : " << account.getBalance() << '\n';

    return 0;
}