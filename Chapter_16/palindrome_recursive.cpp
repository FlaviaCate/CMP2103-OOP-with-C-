import std;
using namespace std;

bool is_palindrome_r(const char *first, const char *last)
{
    if (first < last)
        return (*first == *last)
                   ? is_palindrome_r(first + 1, last - 1) // call self.
                   : false;

    return true;
}

int main()
{
    const char *word = "level";

    if (is_palindrome_r(word, word + strlen(word) - 1))
        cout << word << " is a palindrome\n";
    else
        cout << word << " is not a palindrome\n";
}