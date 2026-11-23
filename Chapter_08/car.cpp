// import std;
// using namespace std;

// // Base class
// class Vehicle
// {
// public:
//     string brand = "Ford";
    
//     void sound()
//     {
//         cout << "Tuut, tuut! \n";
//     }
// };

// // Derived class
// class Car : public Vehicle
// {
// public:
//     string model = "Mustang";
// };

// int main()
// {
//     Car myCar;
//     myCar.sound();
//     cout << myCar.brand + " " + myCar.model;
//     return 0;
// }


import std;
using namespace std;

// Base class
class Vehicle
{
public:
    string brand;

    Vehicle(string brand)
        : brand(brand)
    {
    }

    void sound()
    {
        print("Tuut, tuut!\n");
    }
};

// Derived class
class Car : public Vehicle
{
public:
    string model;

    Car(string brand, string model)
        : Vehicle(brand), model(model)
    {
    }
};

int main()
{
    Car myCar{"Ford", "Mustang"};

    myCar.sound(); // parent
    print("{} {}\n", myCar.brand, myCar.model);

    return 0;
}
