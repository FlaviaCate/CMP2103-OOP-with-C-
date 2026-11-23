import std;
using namespace std;

class Vector
{
    int sz;       // the size
    double *elem; // a pointer to the elements
    int space;    // size + free space

public:
    // Default constructor
    Vector() : sz(0), elem(nullptr), space(0) {}

    // Constructor
    explicit Vector(int s)
        : sz(s), elem(new double[s]{}), space(s) {}

    // Copy constructor
    Vector(const Vector &);

    // Copy assignment
    Vector &operator=(const Vector &);

    // Destructor
    ~Vector()
    {
        delete[] elem;
    }

    // Access: return reference
    double &operator[](int n)
    {
        return elem[n];
    }

    // Current size
    int size() const
    {
        return sz;
    }
};

int main()
{
    Vector v(5);

    // Assign values using the subscript operator
    for (int i = 0; i < v.size(); ++i)
    {
        v[i] = (i + 1) * 10.0;
    }

    // Display the elements
    for (int i = 0; i < v.size(); ++i)
    {
        cout << "v[" << i << "] = " << v[i] << '\n';
    }

    cout << "Size: " << v.size() << '\n';

    return 0;
}


vector<double> name_x(5);
// int
// char
// Rectangle
// Circle
// Shape
// Graph
// Dataframe


