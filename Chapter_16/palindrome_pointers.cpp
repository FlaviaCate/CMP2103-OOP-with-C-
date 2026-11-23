
import std;
using namespace std;

// Check whether characters between first and last form a palindrome.
// first points to the first character.
// last points to the last character.
bool is_palindrome(const char *first, const char *last)
{
    while (first < last)
    {                        // We haven't reached the middle
        if (*first != *last) // Compare the characters
            return false;

        ++first; // Move forward
        --last;  // Move backward
    }

    return true; // All characters matched
}

int main()
{
    const char *word = "level";

    // Point to the first and last characters of the word.
    const char *first = word;
    const char *last = word + strlen(word) - 1;

    if (is_palindrome(first, last))
        cout << word << " is a palindrome\n";
    else
        cout << word << " is not a palindrome\n";
}
