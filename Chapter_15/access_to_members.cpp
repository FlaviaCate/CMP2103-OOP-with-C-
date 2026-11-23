class Vector
{ // a very simplified vector of doubles
public:
    Vector(int s) : sz{s}, elem{new double[s]}
    { /* ... */
    } // constructor

    ~Vector()
    {
        delete[] elem;
    }
    // destructor

    int size() const { return sz; }             // the current size
    double get(int n) const { return elem[n]; } // access: read
    void set(int n, double v) { elem[n] = v; }  // access: write

private:
    int sz;       // the size
    double *elem; // a pointer to the elements
};

int main()
{
    Vector v(5);
    for (int i = 0; i < v.size(); ++i)
    {
        v.set(i, 1.1 * i);
        cout << "v[" << i << "]==" << v.get(i) << '\n';
    }
}