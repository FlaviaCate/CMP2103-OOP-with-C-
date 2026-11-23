
import std;
using namespace std;

// Define a concept
template<typename T>
concept Element = is_arithmetic_v<T>;

// Class template constrained by Element
template<Element T>
class Vector
{
    int sz;
    T* elem;

public:
    // Constructor
    Vector(int s)
        : sz(s), elem(new T[s]{})
    {
    }

    // Destructor
    ~Vector()
    {
        delete[] elem;
    }

    // Access an element
    T& operator[](int n)
    {
        return elem[n];
    }

    // Get vector size
    int size() const
    {
        return sz;
    }
};

int main()
{
    Vector<int> numbers(3);
    numbers[0] = 10;
    numbers[1] = 20;
    numbers[2] = 30;

    print("Integer vector:\n");
    for (int i = 0; i < numbers.size(); ++i)
        print("{} ", numbers[i]);

    print("\n\n");

    Vector<double> values(3);
    values[0] = 1.5;
    values[1] = 2.5;
    values[2] = 3.5;

    print("Double vector:\n");
    for (int i = 0; i < values.size(); ++i)
        print("{} ", values[i]);

    print("\n");
}
