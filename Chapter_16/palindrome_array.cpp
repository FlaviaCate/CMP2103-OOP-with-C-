
import std;
using namespace std;

// Read a word from an input stream into a character buffer.
// Read at most max - 1 characters, leaving space for '\0'.
istream &read_word(istream &is, char *buffer, int max)
{
    is.width(max); // Limit the next input operation to max characters,
                   // including the terminating '\0'.

    is >> buffer; // Read characters until whitespace is encountered.
                  // Automatically appends '\0' to terminate the string.

    return is; // Return the stream so the caller can check
               // whether the input operation succeeded.
}

int main()
{
    constexpr int max = 128;

    // Create a buffer and repeatedly read words while input succeeds.
    for (char s[max]; read_word(cin, s, max);)
    {

        cout << s << " is"; // Print the word followed by " is".

        if (!is_palindrome(s, strlen(s)))
            cout << " not";

        cout << " a palindrome\n"; // Finish the result and start a new line.
    }
}

//arr = [9, 0, 4, 3, 0]
// arr[9]