import std;
using namespace std;

bool is_palindrome(const string &s)
{
    int first = 0;             // Index of first character
    int last = s.length() - 1; // Index of last character

    while (first < last)
    { // We haven't reached the middle
        if (s[first] != s[last])
            return false;

        ++first; // Move forward
        --last;  // Move backward
    }

    return true;
}

int main()
{
    string word;

    cout << "Enter a word: ";
    cin >> word;

    if (is_palindrome(word))
        cout << word << " is a palindrome.\n";
    else
        cout << word << " is not a palindrome.\n";
}
