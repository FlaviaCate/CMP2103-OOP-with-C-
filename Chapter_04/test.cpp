
export module validate_credit_card;

import std;
using namespace std;

// Function declarations
export bool isValid(vector<int> number);
export int sumOfDoubleEvenPlace(vector<int> number);
export int getDigit(int number);
export int sumOfOddPlace(vector<int> number);
export int getSize(vector<int> number);
export bool prefixMatched(vector<int> number);
export vector<int> readCardNumber();
export int getPrefix(vector<int> number, int k);

// Return true if the card number passes the Luhn test,
// has a supported prefix, and contains 13 to 16 digits.
export bool isValid(vector<int> number)
{
    int size = getSize(number);

    return size >= 13 &&
           size <= 16 &&
           (sumOfDoubleEvenPlace(number) +
            sumOfOddPlace(number)) % 10 == 0 &&
           prefixMatched(number);
}

// Double every second digit, starting from the second-last
// digit, and add the resulting digits.
export int sumOfDoubleEvenPlace(vector<int> number)
{
    int sum = 0;

    for (int i = static_cast<int>(number.size()) - 2;
         i >= 0; i -= 2)
    {
        sum += getDigit(number[i] * 2);
    }

    return sum;
}

// Return the number if it is a single digit.
// Otherwise, return the sum of its two digits.
export int getDigit(int number)
{
    if (number < 10)
    {
        return number;
    }

    return number / 10 + number % 10;
}

// Return the sum of digits in odd positions,
// counting from the rightmost digit.
export int sumOfOddPlace(vector<int> number)
{
    int sum = 0;

    for (int i = static_cast<int>(number.size()) - 1;
         i >= 0; i -= 2)
    {
        sum += number[i];
    }

    return sum;
}

// Return the number of digits in the card number.
export int getSize(vector<int> number)
{
    return static_cast<int>(number.size());
}

// Return true if the card number starts with
// 4, 5, 37, or 6.
export bool prefixMatched(vector<int> number)
{
    int size = getSize(number);

    if (size < 1)
    {
        return false;
    }

    int firstDigit = getPrefix(number, 1);

    if (firstDigit == 4 ||
        firstDigit == 5 ||
        firstDigit == 6)
    {
        return true;
    }

    if (size >= 2 && getPrefix(number, 2) == 37)
    {
        return true;
    }

    return false;
}

// Read a card number and convert each digit
// into an integer stored in a vector.
export vector<int> readCardNumber()
{
    string number;

    cout << "Enter card number: ";
    cin >> number;

    vector<int> cardDigits;

    for (char digit : number)
    {
        if (!isdigit(static_cast<unsigned char>(digit)))
        {
            cout << "Invalid input. Enter digits only.\n";
            return {};
        }

        cardDigits.push_back(digit - '0');
    }

    return cardDigits;
}

// Return the first k digits of the card number.
export int getPrefix(vector<int> number, int k)
{
    if (k < 1 || k > static_cast<int>(number.size()))
    {
        return -1;
    }

    int prefix = 0;

    for (int i = 0; i < k; ++i)
    {
        prefix = prefix * 10 + number[i];
    }

    return prefix;
}
