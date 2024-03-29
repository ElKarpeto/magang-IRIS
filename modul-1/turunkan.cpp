#include <iostream>
using namespace std;

// void sortingPangkat(int koefisien[], int pangkat[], int size)
// {
//     for (int i = 0; i < size - 1; i++)
//     {
//         for (int j = 0; j < size - i - 1; j++)
//         {
//             if (pangkat[j] > pangkat[j + 1])
//             {
//                 int tempPangkat = pangkat[j];
//                 pangkat[j] = pangkat[j + 1];
//                 pangkat[j + 1] = tempPangkat;

//                 int tempKoefisien = koefisien[j];
//                 koefisien[j] = koefisien[j + 1];
//                 koefisien[j + 1] = tempKoefisien;
//             }
//         }
//     }
// }

void cetakPangkat(int koefisien, int pangkat)
{
    if (pangkat == 0)
    {
        cout << koefisien;
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

    if (a * p != 0)
    {
        tambahSuku(koefisien, pangkat, size, a * p, p - 1);
    }

    if (b * q != 0)
    {
        tambahSuku(koefisien, pangkat, size, b * q, q - 1);
    }

    if (c * r != 0)
    {
        tambahSuku(koefisien, pangkat, size, c * r, r - 1);
    }

    // sortingPangkat(koefisien, pangkat, size);

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
