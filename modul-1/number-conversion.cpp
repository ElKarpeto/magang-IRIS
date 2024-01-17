#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int charToDecimal(char karakter)
{
    if (karakter >= '0' && karakter <= '9')
    {
        return karakter - '0';
    }
    else if (karakter >= 'A' && karakter <= 'F')
    {
        return karakter - 'A' + 10;
    }
    else
    {
        return 0;
    }
}

char decimalToChar(int x)
{
    if (x > 9)
    {
        return (char)('A' + x - 10);
    }
    else
    {
        return (char)(x + '0');
    }
}

void convertNumber(const string &num, int basisAwal, int basisAkhir)
{
    int decimal = 0;
    int len = num.length();
    for (int i = len - 1; i >= 0; i--)
    {
        int digit = charToDecimal(num[i]);
        decimal += digit * pow(basisAwal, len - 1 - i);
    }

    string result = "";

    while (decimal > 0)
    {
        int digit = decimal % basisAkhir;
        result.push_back(decimalToChar(digit));
        decimal /= basisAkhir;
    }

    for (int i = result.length() - 1; i >= 0; i--)
    {
        cout << result[i];
    }

    cout << endl;
}

int main()
{
    string num;
    int basisAwal, basisAkhir;

    cin >> num;
    cin >> basisAwal;
    cin >> basisAkhir;
    convertNumber(num, basisAwal, basisAkhir);

    return 0;
}
