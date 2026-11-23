import std;
using namespace std;

template<typename T, typename U>
class Pair {
    T first;
    U second;

public:
    Pair(T a, U b) : first(a), second(b) {}

    void display() const {
        print("First: {}\n", first);
        print("Second: {}\n", second);
    }
};

int main() {
    Pair<int, string> p1(10, "Steven");
    Pair<double, int> p2(3.14, 100);

    p1.display();
    print('\n');
    p2.display();
}