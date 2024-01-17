#include <iostream>
using namespace std;

void printTerm(int coefficient, int power)
{
    if (coefficient != 0)
    {
        if (coefficient > 0)
        {
            cout << "+";
        }

        cout << coefficient;

        if (power > 0)
        {
            cout << "x";
            if (power > 1)
            {
                cout << "^" << power;
            }
        }
    }
}

int main()
{
    int a, b, c, p, q, r;
    cin >> a >> b >> c >> p >> q >> r;

    int hasilTurunan[3] = {a * p, b * q, c * r};
    int pangkat[3] = {p - 1, q - 1, r - 1};

    cout << "Turunan = ";
    printTerm(hasilTurunan[0], pangkat[0]);

    for (int i = 1; i < 3; i++)
    {
        printTerm(hasilTurunan[i], pangkat[i]);
    }

    cout << endl;

    return 0;
}
