#include <iostream>
using namespace std;

void cetakPangkat(int koefisien, int pangkat)
{
    if (pangkat == 0)
    {
        cout << koefisien;
    }
    else if (koefisien == 0)
    {
        if (pangkat > 0)
        {
            cout << koefisien << "x^" << pangkat;
        }
        else if (pangkat == 1)
        {
            cout << "x";
        }
        else if (pangkat < 0)
        {
            cout << koefisien;
        }
    }
    else if (koefisien == 1)
    {
        cout << "x";
        if (pangkat != 1)
        {
            cout << "^" << pangkat;
        }
    }
    else
    {
        cout << koefisien << "x";
        if (pangkat != 1)
        {
            cout << "^" << pangkat;
        }
    }
}

void tambahSuku(int koefisien[], int pangkat[], int &size, int koef, int pang)
{
    for (int i = 0; i < size; i++)
    {
        if (pangkat[i] == pang)
        {
            koefisien[i] += koef;
            return;
        }
    }

    if (size < 3)
    {
        koefisien[size] = koef;
        pangkat[size] = pang;
        size++;
    }
}

void cetakJawaban(int a, int b, int c, int p, int q, int r)
{
    int koefisien[3];
    int pangkat[3];
    int size = 0;

    tambahSuku(koefisien, pangkat, size, a * p, p - 1);
    tambahSuku(koefisien, pangkat, size, b * q, q - 1);
    tambahSuku(koefisien, pangkat, size, c * r, r - 1);

    cout << "Turunan = ";

    for (int i = 0; i < size; i++)
    {
        if (i > 0)
        {
            cout << (koefisien[i] >= 0 ? "+" : "");
        }
        cetakPangkat(koefisien[i], pangkat[i]);
    }

    cout << endl;
}

int main()
{
    int a, b, c, p, q, r;

    cin >> a >> b >> c >> p >> q >> r;

    cetakJawaban(a, b, c, p, q, r);

    return 0;
}
