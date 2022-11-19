#include <iostream>

#ifndef ACCOUNT.H
#define ACCOUNT.H

using namespace std;

class Account {
  private:
    string name;
    string accountNo;
    float amount;
  public:
    Account(string _name, string _accountNo, float _amount): name(_name), accountNo(_accountNo), amount(_amount) {}
    ~Account() {}
    float getAmount() {
      return amount;
    }
    void deposit(float amount) {
      this->amount += amount;
    }
    virtual void withdraw(float amount) {
      if (amount >= this->amount) {
        this->amount -= amount;
      } else {
        cout << "Over Limit!";
      }
    }
    void deduct(float amount) {
      this->amount -= amount;
    }
};

#endif
