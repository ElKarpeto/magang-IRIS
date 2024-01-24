#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void bilanganBulat(double num)
{
    if (num == floor(num))
    {
        cout << fixed << setprecision(0) << num;
    }
    else
    {
        cout << fixed << setprecision(2) << num;
    }
}

int main()
{
    int a, b, c;

    cin >> a >> b >> c;

    double diskriminan = (b * b) - 4 * a * c;

    if (diskriminan < 0)
    {
        double Real = -b / (double)(2 * a);
        double Imaginer = sqrt((-diskriminan)) / (double)(2 * a);

        if (Real == 0)
        {
            if (Imaginer == 1)
            {
                cout << "i" << endl;
            }
            else if (Imaginer == -1)
            {
                cout << "-i" << endl;
            }
            else
            {
                bilanganBulat(Imaginer);
                cout << "i" << endl;
            }
        }
        else
        {
            if (Imaginer == 1)
            {
                bilanganBulat(Real);
                cout << "-i ";
                bilanganBulat(Real);
                cout << "+i" << endl;
            }
            else if (Imaginer == -1)
            {
                bilanganBulat(Real);
                cout << "+i ";
                bilanganBulat(Real);
                cout << "-i" << endl;
            }
            else
            {
                bilanganBulat(Real);
                cout << "-";
                bilanganBulat(Imaginer);
                cout << "i ";
                bilanganBulat(Real);
                cout << "+";
                bilanganBulat(Imaginer);
                cout << "i" << endl;
            }
        }
    }
    else
    {
        double root1 = (-b - sqrt(diskriminan)) / (double)(2 * a);
        double root2 = (-b + sqrt(diskriminan)) / (double)(2 * a);
        if (root1 == root2)
        {
            bilanganBulat(root1);
            cout << endl;
        }
        else
        {
            bilanganBulat(root1);
            cout << " ";
            bilanganBulat(root2);
            cout << endl;
        }
    }

    return 0;
}