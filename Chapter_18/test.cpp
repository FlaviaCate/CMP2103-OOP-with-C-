import std;
using namespace std;

// integral
// floating_point
// range
// size_t
// is_num(T)

// template<typename T, typename U>
// concept NumericPair = (integral<T> || floating_point<T>) && (integral<U> || floating_point<U>);

// predicate
// Yes, No
// True, False

template <typename T>
// requires NumericPair<T, U>
T fc(T t)
{
    return t;
}
int main()
{
    int r = fc(5);
    double d = fc(6.9);

    print("{}\n", r);
    print("{}", d);
}