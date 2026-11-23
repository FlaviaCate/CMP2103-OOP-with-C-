import std;
using namespace std;

bool is_palindrome(const char* first, const char* last)
{
    if (first >= last)
        return true;

    if (*first != *(last - 1))
        return false;

    return is_palindrome(first + 1, last - 1);
}

bool is_palindrome(span<char> s)
{
    return s.size()
        ? is_palindrome(s.data(), s.data() + s.size())
        : true;
}

int main()
{
    char word[] = "level";
    char word2[] = "hello";
    char word3[] = "abba";
    char word4[] = "";

    print("level: {}\n", is_palindrome(span<char>{word, 5}));
    print("hello: {}\n", is_palindrome(span<char>{word2, 5}));
    print("abba: {}\n", is_palindrome(span<char>{word3, 4}));
    print("empty: {}\n", is_palindrome(span<char>{word4, 0}));
}