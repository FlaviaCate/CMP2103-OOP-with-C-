//From my originality!!
//For simple resistive cicruits
//Used AI mainly to help me out with error handling situations

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

class ResistiveCircuit {
protected:
    int size = 0;
    vector<double> resistors;
    double Req = 0.0;
    double SourceVoltage = 10.0;

public:
//first constructor, one can have more than one
    ResistiveCircuit(int number) 
    : size(number), resistors(number) {
        if (number <= 0) {
            throw invalid_argument("Number of resistors must be positive.");
        }

        //this is so that a user could put in the number of resistors
        for (int i = 0; i < number; i++) {
            cout << "Enter resistance of resistor " << i + 1 << " (ohms): ";
            cin >> resistors[i];

            if (!cin || resistors[i] <= 0) //this is so that a positive integer must be put in.
            {
                throw invalid_argument("Resistance must be positive.");
            }
        }
    }
//second constructor!!Found out it could be possible and the compiler chooses which constructor to use according parametres passed
    ResistiveCircuit(int number, double resistance)
        : size(number), resistors(number, resistance)//there the vector size is initialised AND also its members, so it will be full of the same value.
        {
        if (number <= 0) {
            throw invalid_argument("Number of resistors must be positive.");
        }

        if (resistance <= 0) {
            throw invalid_argument("Resistance must be positive.");
        }
    }

    virtual double calculateEquivalentResistance() = 0;//this is an implementation of polymorphism

    double calculatePower() //function for calculating power
    {
        double Req = calculateEquivalentResistance();
        return (SourceVoltage * SourceVoltage) / Req;
    }
};

class Series : public ResistiveCircuit {
public:
//first series constructor to match with parent class
    Series(int number)
        : ResistiveCircuit(number) {}
//second series constructor to match with parent class, this one is going to calculate for when resistances are equal.
    Series(int number, double resistance)
        : ResistiveCircuit(number, resistance) {}

    double calculateEquivalentResistance() override {
        Req = 0.0;

        for (double resistance : resistors) {
            Req += resistance;
        }

        return Req;
    }
};

class Parallel : public ResistiveCircuit {
public:
//first parallel Circuit constructor to match with parent class
    Parallel(int number) : ResistiveCircuit(number) {}
//second parallel Circuit constructor to match with parent class,this one is going to calculate for when resistances are equal.
    Parallel(int number, double resistance)
        : ResistiveCircuit(number, resistance) {}

    double calculateEquivalentResistance() override {
        double InvReq = 0.0;

        for (double resistance : resistors) {
            InvReq += 1.0 / resistance;
        }

        Req = 1.0 / InvReq;
        return Req;
    }
};

class EqualSeries : public Series {
public:
    EqualSeries(int number, double resistance)
        : Series(number, resistance) {}//just calls on the function in parent class to calculate equivalent resistances whe resistors ave equal resistor values.
};

class EqualParallel : public Parallel {
public:
    EqualParallel(int number, double resistance)
        : Parallel(number, resistance) {}
};

int main() {
    try {
        int number;
        cout << "Enter the number of resistors: ";
        if (!(cin >> number)) {
            throw invalid_argument("Please enter a valid number.");
        }
        cout << "\n";

        Series seriesCircuit(number);

        cout << "Series equivalent resistance: "
             << seriesCircuit.calculateEquivalentResistance()
             << " ohms\n";

        cout << "Series power: "
             << seriesCircuit.calculatePower()
             << " W";
        cout << "\n";
        Parallel parallelCircuit(number);

        cout << "\nEnter the resistances for the parallel circuit when prompted.\n";

        cout << "Parallel equivalent resistance: "
             << parallelCircuit.calculateEquivalentResistance()
             << " ohms\n";

        cout << "Parallel power: "
             << parallelCircuit.calculatePower()
             << " W\n";

        double resistance;
        cout << "\nEnter the common resistance for equal circuits (ohms): ";
        if (!(cin >> resistance)) {
            throw invalid_argument("Please enter a valid resistance.");
        }

        EqualSeries equalSeries(number, resistance);

        cout << "\nEqual series equivalent resistance: "
             << equalSeries.calculateEquivalentResistance()
             << " ohms\n";

        cout << "Equal series power: "
             << equalSeries.calculatePower()
             << " W\n";

        EqualParallel equalParallel(number, resistance);

        cout << "\nEqual parallel equivalent resistance: "
             << equalParallel.calculateEquivalentResistance()
             << " ohms\n";

        cout << "Equal parallel power: "
             << equalParallel.calculatePower()
             << " W\n";
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << '\n';
        return 1;
    }

    return 0;
}
