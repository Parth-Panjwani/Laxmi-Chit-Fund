#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    string Name;
    float deposit;
    int a = 1;
    int b = 0;
    int c;
    char option;
    int day;
    int num;
    float result;
    int x;
    float fold = 1;
    float reminder;

    cout << "----------------------------------------------------------------------------------------------------------" << endl;
    cout << "Welcome to Laxmi Chit Fund" << endl;
    cout << "Our goal is to double the money of our customers in 21 days!" << endl;
    cout << "Enter your name, amount to be deposited then check what amount you'll get on every day till 21st Day!" << endl;
    cout << "----------------------------------------------------------------------------------------------------------" << endl;
    cout << "Enter your name: ";
    cin >> Name;

    cout << endl;

    cout << "Enter the amount you want to deposit: ";
    cin >> deposit;

    cout << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+" << endl;
    cout << endl;

    cout << "Your money successfully deposited" << endl;
    cout << "Press 1 if displayed amount is correct else press 0: ";
    cout << deposit << endl;
    cin >> c;
    cout << endl;

    if (c == 1)
    {
        cout << "Now you can check your how much money is increased everyday.. " << endl;
    }
    else if (c == 0)
    {
        cout << "End of program : Start again" << endl;
        return 0;
    }

    cout << "How much times you want to increase your deposit :";
    cin >> fold;

    float additive = (((fold-1) * deposit) - (fold-1)) / 21;
    reminder = fold/21;

    cout << "Do you want to print results automatically or want manually? " << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+" << endl;
    cout << "To print results automatically press 1 and to operate manually press 0: ";
    cin >> option;
    cout << endl;

    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+" << endl;

    if (option == '0')
    {
        while (true)
        {
            cout << "Enter the day number (Enter 0 to quit) : ";
            cin >> day;
            if (day == 0)
            {
                return 0;
            }
            else if (day <= 21)
            {
                for (int i = 1; i <= day; i++)
                {
                    if (i == 1)
                    {
                        result = additive + deposit + reminder;
                    }
                    else
                    {
                        result = additive + result + reminder;
                    }
                }
                if (day == 21)
                {
                    cout << endl;
                    cout << "Amount on " << day << " day : " << result << endl;
                    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+" << endl;
                    cout << "Your Initial deposit was : " << deposit << endl
                         << "And now it's : " << result << endl;
                    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+" << endl;
                    cout << "Thank You for investing in Laxmi Chit Fund :) ";
                    return 0;
                }
                else
                {
                    cout << "Amount on " << day << " day : " << result << endl;
                }
            }
            else
            {
                cout << "+-+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+" << endl;
                cout << "Sorry you are asking days beyond 21!! :: Try Again" << endl;
            }
        }
    }
    else if (option == '1')
    {
        for (int i = 1; i <= 21; i++)
        {
            if (i == 1)
            {
                result = additive + deposit + reminder;
            }
            else
            {
                result = additive + result + reminder;
            }
            cout << "Amount on " << i << " day : " << result << endl;
        }
        cout << "+-+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+" << endl;
        cout << endl;
        cout << "Your Initial deposit was : " << deposit << endl
             << "And now it's : " << result << endl;
        cout << "+-+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+" << endl;
        cout << "Thank You for investing in Laxmi Chit Fund :) ";
    }

     ofstream file("history.txt", ios::out | ios::app);
	if(file.is_open()) {
        file << "Name: " << Name << '\n';
		file << "Amount Deposited: " << deposit << '\n';
		file << "How much times increased: " << fold <<"x" << '\n';
		file << "Final maturity amount: " << result << '\n';

		file << "\n----------------------------------------------" << '\n';

    }


   

    return 0;
}
