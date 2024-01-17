#include <iostream>
using namespace std;

int main()
{
    int a, b, c, p, q, r;

    cin >> a >> b >> c >> p >> q >> r;

    int hasilTurunan[3] = {a * p, b * q, c * r};
    int pangkat[3] = {p - 1, q - 1, r - 1};

    cout << "Turunan = ";
    for (int i = 0; i < 3; i++)
    {
        if (hasilTurunan[i] != 0)
        {

            if (i == 0)
            {
                switch (pangkat[i])
                {
                case 0:
                    cout << hasilTurunan[i];
                    break;
                case 1:
                    cout << hasilTurunan[i] << "x";
                    break;
                default:
                    cout << hasilTurunan[i] << "x^" << pangkat[i];
                    break;
                }
            }

            if (i > 0)
            {
                if (hasilTurunan[i] > 0)
                {
                    switch (pangkat[i])
                    {
                    case 0:
                        cout << "+" << hasilTurunan[i];
                        break;
                    case 1:
                        cout << "+" << hasilTurunan[i] << "x";
                        break;
                    default:
                        cout << "+" << hasilTurunan[i] << "x^" << pangkat[i];
                        break;
                    }
                }
                else
                {
                    switch (pangkat[i])
                    {
                    case 0:
                        cout << hasilTurunan[i];
                        break;
                    case 1:
                        cout << hasilTurunan[i] << "x";
                        break;
                    default:
                        cout << hasilTurunan[i] << "x^" << pangkat[i];
                        break;
                    }
                }
            }
        }
    }
    cout << endl;

    return 0;
}