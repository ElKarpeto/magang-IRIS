#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int hexCharToDecimal(char hexChar)
{
    if (hexChar >= '0' && hexChar <= '9')
    {
        return hexChar - '0';
    }
    else if (hexChar >= 'A' && hexChar <= 'F')
    {
        return hexChar - 'A' + 10;
    }
    else if (hexChar >= 'a' && hexChar <= 'f')
    {
        return hexChar - 'a' + 10;
    }
    else
    {
        return 0;
    }
}

int convertBase(const string &number, int baseFrom, int baseTo)
{
    int decimalNumber = 0;

    for (int i = number.length() - 1; i >= 0; i--)
    {
        int digit = hexCharToDecimal(number[i]);
        decimalNumber += digit * pow(baseFrom, number.length() - 1 - i);
    }

    int result = 0;
    int multiplier = 1;

    while (decimalNumber > 0)
    {
        int digit = decimalNumber % baseTo;
        result += digit * multiplier;
        multiplier *= 10;
        decimalNumber /= baseTo;
    }

    return result;
}

int main()
{
    string number;
    int baseFrom, baseTo;

    cin >> number;
    cin >> baseFrom;
    cin >> baseTo;
    int result = convertBase(number, baseFrom, baseTo);
    cout << result << endl;

    return 0;
}
