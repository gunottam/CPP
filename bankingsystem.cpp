#include <iostream>
#include <cmath>

using namespace std;

const double INTEREST_RATE = 0.02;
const int MIN_SAVINGS = 1000;
const int MIN_CURRENT = 500;

class Accounts {
protected:
    string customername;
    int type_account;
    double bal;

public:
    void ini(string nm, double b, int cb) {
        customername = nm;
        bal = b;
        type_account = cb;
    }

    void showinfo() {
        cout << "Customer Name: " << customername;
        cout << "\nType Account: " << (type_account == 0 ? "Savings" : "Current");
        cout << "\nAccount Balance: " << bal << endl;
    }
};

class Savings : protected Accounts {
    bool svint;

public:
    Savings(string a, double b) {
        ini(a, b, 0);
        svint = false;
    }

    void check() {
        if (bal < MIN_SAVINGS) {
            cout << "Your Balance is less than Minimum Balance. Rs 100 is charged." << endl;
            bal -= 100;
        } else {
            cout << "Your Balance is Higher than Minimum Balance." << endl;
        }
    }

    void interest() {
        if (!svint) {
            int n, t;
            cout << "Input n (number of times interest applied per time period), t (time period): ";
            cin >> n >> t;

            double amount = bal * pow((1 + (INTEREST_RATE / n)), n * t);
            double in = amount - bal;
            bal = amount;
            svint = true;

            cout << "Interest: " << in << endl;
        } else {
            cout << "Interest has already been calculated." << endl;
        }

        cout << "Amount after Interest: " << bal << endl;
    }

    void depo() {
        double d;
        cout << "Enter the amount you want to deposit: ";
        cin >> d;
        bal += d;
        cout << "Your Current Savings Balance: " << bal << endl;
        svint = false;
    }

    void with() {
        double d;
        cout << "Enter the amount you want to withdraw: ";
        cin >> d;
        if (d > bal) {
            cout << "Insufficient balance for withdrawal." << endl;
        } else {
            bal -= d;
            cout << "Your Savings Balance: " << bal << endl;
            svint = false;
        }
    }

    void dis_savings() {
        showinfo();
    }
};

class Current : protected Accounts {
public:
    Current(string a, double b) {
        ini(a, b, 1);
    }

    void ccheck() {
        if (bal < MIN_CURRENT) {
            cout << "Your Balance is less than Minimum Balance. Rs 100 is charged." << endl;
            bal -= 100;
        } else {
            cout << "Your Balance is Higher than Minimum Balance." << endl;
        }
    }

    void cdepo() {
        double d;
        cout << "Enter the amount you want to deposit: ";
        cin >> d;
        bal += d;
        cout << "Your Current Balance: " << bal << endl;
    }

    void cwith() {
        double d;
        cout << "Enter the amount you want to withdraw: ";
        cin >> d;
        if (d > bal) {
            cout << "Insufficient balance for withdrawal." << endl;
        } else {
            bal -= d;
            cout << "Your Current Balance: " << bal << endl;
        }
    }

    void dis_current() {
        showinfo();
    }
};

int main() {
    string a;
    cout << "Enter Customer Name: ";
    getline(cin, a);
    cout << "Enter default balance: ";
    double dbal;
    cin >> dbal;
    int c;

    cout << "1. Current\n2. Savings\n3. Exit\n";
    cin >> c;

    if (c == 1) {
        Current object(a, dbal);
        while (true) {
            cout << "\nYou have selected Current account:\n1. Deposit\n2. Withdraw\n3. Display Info\n4. Display Min.\n5. Exit\n";
            cin >> c;
            switch (c) {
                case 1:
                    object.cdepo();
                    break;
                case 2:
                    object.cwith();
                    break;
                case 3:
                    object.dis_current();
                    break;
                case 4:
                    object.ccheck();
                    break;
                case 5:
                    return 0;
                default:
                    cout << "Invalid Input" << endl;
                    break;
            }
        }
    } else if (c == 2) {
        Savings object(a, dbal);
        while (true) {
            cout << "\nYou have selected Savings account:\n1. Deposit\n2. Withdraw\n3. Display Info\n4. Display Min.\n5. Display Interest\n6. Exit\n";
            cin >> c;
            switch (c) {
                case 1:
                    object.depo();
                    break;
                case 2:
                    object.with();
                    break;
                case 3:
                    object.dis_savings();
                    break;
                case 4:
                    object.check();
                    break;
                case 5:
                    object.interest();
                    break;
                case 6:
                    return 0;
                default:
                    cout << "Invalid Input" << endl;
                    break;
            }
        }
    } else {
        cout << "Exiting program." << endl;
    }

    return 0;
}
