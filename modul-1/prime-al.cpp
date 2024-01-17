#include <iostream>
using namespace std;

int main()
{
    int prime[10005] = {0};
    int a, b;

    cin >> a >> b;

    prime[0] = 1;
    prime[1] = 1;

    for (int i = 2; i * i < 10005; i++)
    {
        if (prime[i] == 0)
        {
            for (int j = i * i; j < 10005; j += i)
            {
                prime[j] = 1;
            }
        }
    }

    bool firstNumberPrinted = false;

    for (int i = a; i < b; i++)
    {
        if (prime[i] == 0)
        {
            if (firstNumberPrinted)
            {
                cout << " ";
            }
            cout << i;
            firstNumberPrinted = true;
        }
    }

    cout << endl;

    return 0;
}
