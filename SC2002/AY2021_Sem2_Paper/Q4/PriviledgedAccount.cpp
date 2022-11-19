#include <iostream>
#include "account.h"

using namespace std;

class PriviledgedAccount: public Account {
  private:
    float limit;
  public:
    PriviledgedAccount(string _name, string _accountNo, float _amount, float _limit): Account(_name, _accountNo, _amount), limit(_limit) {}
    ~PriviledgedAccount() {}
    void withdraw(float amount) {
      if (amount - this->getAmount() > limit) {
        cout << "Over Limit!";
      } else {
        this->deduct(amount);
      }
    }
};
