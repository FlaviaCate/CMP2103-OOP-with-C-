// class Vector
// {
//     int size;
//     double age0, age1, age2, age3;
// };

// class Vector
// {
//     int sz;
//     double *elem; // pointer to the first element of the vector

// public:
//     Vector(int s); // Constructor

//     int size() const
//     { // Return the size of the vector
//         return sz;
//     }
// };

// class Vector
// { // a very simplified vector of doubles
// public:
//     Vector(int s);              // constructor: allocate elements on the free store and initialize them
//     Vector() { delete[] elem; } // destructor: return elements to free store
//     // ...

// private:
//     int sz;       // the size
//     double *elem; // a pointer to the elements
// };

// Vector::Vector(int s)     // constructor
//     : sz{s},              // initialize sz
//       elem{new double[s]} // initialize elem to elements on the free store
// {
//     for (int i = 0; i < s; ++i) // initialize elements
//         elem[i] = 0;
// }
// Vector::~Vector() // destructor. Take note of the ~ operator. It is used to destroy the object and free up resources.
// {
//     delete[] elem; // return elements to free store
// }

// class Vector
// { // a very simplified vector of doubles
// public:
//     Vector(int s) : sz{s}, elem{new double[s]} { /* ... */ } // constructor
//     ~Vector() { delete[] elem; }                             // destructor

//     int size() const { return sz; }                          // the current size
//     double get(int n) const { return elem[n]; }              // access: read
//     void set(int n, double v) { elem[n] = v; }               // access: write
// private:
//     int sz;       // the size
//     double *elem; // a pointer to the elements
// };

// int main()
// {
//     Vector v(5);
//     for (int i = 0; i < v.size(); ++i)
//     {
//         v.set(i, 1.1 * i);
//         cout << "v[" << i << "]==" << v.g et(i) << '\n';
//     }
// }

// A segmentation error (or segmentation fault/segfault) is a runtime crash that happens
// when a computer program tries to read or write to a memory address it does not
// have permission to access.

// A bus error is a hardware-generated fault in computing that occurs when
// a program tries to access a physical memory address that the CPU cannot
// properly address or handle

// A core dump is a saved snapshot of a computer program's working memory
// and CPU state created when the program crashes or terminates unexpectedly,
// typically due to a fatal error like a segmentation fault.

// Unique_ptr is a smart pointer in C++ that manages the lifetime of a dynamically allocated object.
// It ensures that the object is automatically deleted when the unique_ptr goes out of scope,
// preventing memory leaks. A unique_ptr cannot be copied, only moved, which enforces unique
// ownership of the object it manages.
