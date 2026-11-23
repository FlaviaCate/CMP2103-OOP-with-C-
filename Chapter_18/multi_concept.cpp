import std;
using namespace std;

template<typename T, typename U>
concept NumericPair =
    (integral<T> || floating_point<T>) &&
    (integral<U> || floating_point<U>);

template<typename T, typename U>
    requires NumericPair<T, U>
class Pair {
public:
    T first;
    U second;

    Pair(T a, U b) : first(a), second(b) {}

    auto sum() const {
        return first + second;
    }
};

int main() {
    Pair<int, double> p(10, 2.5);

    print("Sum: {}\n", p.sum());
}