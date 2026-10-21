# Simple Resistive Circuit Calculator

## What the program does

This program is for simple resistive circuits. It calculates the equivalent resistance and power for series and parallel circuits. It also has two extra classes for the cases where all the resistors have equal resistance values.

The source voltage is currently set to `10.0 V` in the parent class.

## The classes

### `ResistiveCircuit`

This is the parent class. It stores the resistor values, the equivalent resistance and the source voltage.

It has two constructors:

- The first constructor takes the number of resistors and asks the user to enter each resistance.
- The second constructor takes the number of resistors and one resistance value. It uses that value to fill the vector, so all the resistors have the same resistance.

The compiler chooses which constructor to use depending on the parameters passed.

`calculateEquivalentResistance()` is a pure virtual function. This means that `ResistiveCircuit` is an abstract class, and the child classes provide their own way of calculating equivalent resistance.

`calculatePower()` is in the parent class because the power calculation is the same for both series and parallel circuits:

\[
P = \frac{V^2}{R_{eq}}
\]

### `Series`

This is a child class of `ResistiveCircuit`. It calculates equivalent resistance by adding all the resistor values:

\[
R_{eq} = R_1 + R_2 + \cdots + R_n
\]

It has two constructors to match the two constructors in the parent class. The first one allows the user to enter each resistor value, while the second one is used when all the resistors have equal values.

### `Parallel`

This is also a child class of `ResistiveCircuit`. It calculates equivalent resistance using the reciprocal formula:

\[
\frac{1}{R_{eq}} = \frac{1}{R_1} + \frac{1}{R_2} + \cdots + \frac{1}{R_n}
\]

Like `Series`, it has two constructors to match the parent class.

### `EqualSeries`

This is a grandchild class of `ResistiveCircuit` through `Series`. It is for a series circuit where all the resistors have the same resistance value.

It calls the second constructor in `Series`, which then calls the second constructor in `ResistiveCircuit`. The vector is filled with the same resistance value, so the user does not have to enter every resistor separately.

The equivalent resistance calculation is inherited from `Series`.

### `EqualParallel`

This is a grandchild class of `ResistiveCircuit` through `Parallel`. It is for a parallel circuit where all the resistors have the same resistance value.

It works in the same way as `EqualSeries`, but it inherits the equivalent resistance calculation from `Parallel`.

## The four pillars of OOP in the program

- **Encapsulation:** The circuit data and functions are grouped inside classes. The data members are `protected`, so the child classes can access them.
- **Inheritance:** `Series` and `Parallel` inherit from `ResistiveCircuit`. `EqualSeries` inherits from `Series`, while `EqualParallel` inherits from `Parallel`.
- **Polymorphism:** The function `calculateEquivalentResistance()` is declared as a pure virtual function in the parent class and overridden in `Series` and `Parallel`.
- **Abstraction:** `ResistiveCircuit` describes what a resistive circuit should be able to calculate without specifying one formula for every possible connection.

## Error handling

The program checks that the number of resistors is positive and that each resistance entered is positive. It also checks whether the user entered a valid number when asked for the number of resistors or the common resistance. If an invalid value is entered, an exception is thrown and the error message is displayed.

## A note about the constructors

The two constructors have different jobs. `ResistiveCircuit(number)` asks for each resistor value, while `ResistiveCircuit(number, resistance)` creates a vector with `number` elements, all initialised to `resistance`. The same two constructor options are provided in `Series` and `Parallel` so that the equal-resistance grandchild classes can pass their arguments through the inheritance chain.
