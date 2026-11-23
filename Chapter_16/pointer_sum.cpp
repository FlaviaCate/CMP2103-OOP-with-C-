import std;
using namespace std;

int sum(int *p, int n)
{
    int s = 0;
    for (int I = 0; i < n; ++i)
        s += p[i];
    return s;
}
// what if p==nullptr?    What if n isn’t the number of elements?

int main()
{
    int arr[100];
    // …
    int r = sum(p, 100);

    cout << r << "\n";
}