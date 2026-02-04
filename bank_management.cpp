#include <iostream>
using namespace std;

void credits();
class bankaccount
{
    string accname;
    int pin;
    float accbalance;
    static int inum; // inum is used to generate unique account numbers

public:
    int accnumber;
    bankaccount() // default constructor to intialize data members
    {
        accbalance = 0.0;
        pin = 0;
        accname[0] = '\0';
        accnumber = 0;
    }
    void openac()
    {
        cout << "Enter Account Holder Name: ";
        cin >> accname;
        accnumber = ++inum;
        cout << "your Account Number is : " << accnumber << endl;
        cout << "set your pin : ";
        cin >> pin;
        cout << "Account Opened successfully" << endl;
    }
    void disp()
    {
        cout << "Account Holder Name : " << accname << endl;
        cout << "Account Number : " << accnumber << endl;
        cout << "account Balance : " << accbalance << endl;
    }

    inline bool verify_pin(int p) { return p == pin; } // inline function to verify pin

    void deposit(float amt)
    {
        accbalance = accbalance + amt;
        cout << "Amount Deposited successfully" << endl;
    }
    void withdraw(float amt)
    {
        if (amt > accbalance)
        {
            cout << "Insufficient Balance" << endl;
        }
        else
        {
            accbalance -= amt;
            cout << "Amount withdrawn successfully" << endl;
        }
    }
    void change_pin(int olpin, int npin)
    {
        if (olpin != pin)
        {
            cout << "Incorrect Old Pin" << endl;
        }
        else
        {
            pin = npin;
            cout << "pin changed successfully" << endl;
        }
    }
};

int bankaccount::inum = 202500; // initializing static member to generate account numbers

// Main function
int main()
{
    bankaccount a[10];
    int c, n = 0;
    do
    {

        cout << "------------------------------" << endl;
        cout << "   Bank Management system" << endl;
        cout << "1. Open Account" << endl;
        cout << "2. Banking " << endl;
        cout << "3. Exit" << endl;
        cout << "------------------------------" << endl;
        cout << "Enter your choice : ";
        cin >> c;
        switch (c)
        {
        case 1:
        {
            if (n < 10)
            {
                a[n].openac();
                n++;
            }
            else
                cout << "Maximum accounts limit reached!" << endl;
            break;
        }
        case 2:
        {
            int y, z = -1;
            cout << "Enter your account number : ";
            cin >> y;
            for (int i = 0; i < n; i++)
            {
                if (a[i].accnumber == y)
                {
                    z = i;
                }
            }
            if (z == -1)
            {
                cout << "Account not found" << endl;
                break;
            }
            int x;
            bool exit = 0;
            do
            {
                int pin;
                float amt;
                cout << "------------------------------" << endl;
                cout << "      Banking Menu" << endl;
                cout << "1.Display Account Details" << endl;
                cout << "2.deposit" << endl;
                cout << "3.withdraw" << endl;
                cout << "4.change pin" << endl;
                cout << "5.Exit" << endl;
                cout << "------------------------------" << endl;
                cout << "Enter your choice : ";
                cin >> x;
                switch (x)
                {
                case 1:
                    a[z].disp();
                    break;
                case 2:
                    cout << "Enter pin : ";
                    cin >> pin;
                    if (a[z].verify_pin(pin) == true)
                    {
                        cout << "Enter amount to deposit : ";
                        cin >> amt;
                        a[z].deposit(amt);
                    }
                    else
                        cout << "Incorrect Pin" << endl;
                    break;
                case 3:
                    cout << "Enter pin : ";
                    cin >> pin;
                    if (a[z].verify_pin(pin) == true)
                    {
                        cout << "Enter amount to withdraw : ";
                        cin >> amt;
                        a[z].withdraw(amt);
                    }
                    else
                        cout << "Incorrect Pin" << endl;
                    break;
                case 4:
                    int olpin, npin;
                    cout << "Enter old pin : ";
                    cin >> olpin;
                    cout << "Enter new pin : ";
                    cin >> npin;
                    a[z].change_pin(olpin, npin);
                    break;
                case 5:
                    cout << "Exiting banking menu..." << endl;
                    exit = 1;
                    break;
                default:
                    cout << "Invalid choice" << endl;
                    break;
                }
            } while (exit == 0);
            break;
        }
        case 3:
            cout << "Exiting..." << endl;
            credits();
            exit(0);
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (true);
    return 0;
}
void credits()
{
    cout << "-------------------------" << endl;
    cout << "       Project By   " << endl;
    cout << "  1.Afridh Kareem M" << endl;
    cout << "  2.Aswin Kumar C" << endl;
    cout << "  3.Inisha T" << endl;
    cout << "  4.Kamali " << endl;
    cout << "-------------------------" << endl;
}
// afr1zz
