import std;
using namespace std;

int my_strlen(const char *p)
{
    if (p == nullptr)
        return 0;

    int n = 0;
    while (*p++)
        ++n;
    return n;
}

int main()
{
    const char *name = "sfrica";
    cout << my_strlen(name) << "\n";
}