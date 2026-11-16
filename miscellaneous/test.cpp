import std;
using namespace std;

int main()
{
    vector<int> x = {5, 6, 7};
    vector<int> y = {8, 9, 10};

    for (int item : x, y)
    {
        x.push_back(item);
        y.push_back(item);
        cout << item << "\n";
        // cout << y[y.size() - 1] << "\n";
    }

    // for (int i = 0; i < x.size(); ++i)
    // {
    //     cout << x[i] << "\n";

    //     // cout << y[i] << "\n";
    // }

    // for (int i = 0; i < y.size(); ++i)
    // {
    //     cout << y[i] << "\n";

    //     // cout << y[i] << "\n";
    // }
}
