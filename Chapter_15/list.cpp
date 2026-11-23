#include <iostream>
#include <string>
using namespace std;

struct Link
{
    string name;
    Link *prev;
    Link *succ;

    Link(string n, Link *p, Link *s)
        : name{n}, prev{p}, succ{s} {}
};

int main()
{
    Link *presidents =
        new Link{"Milton Obote", nullptr, nullptr};

    presidents =
        new Link{"Idi Amin", nullptr, presidents};

    // Link presidents
    presidents->succ->prev = presidents;

    presidents =
        new Link{"Yoweri Museveni", nullptr, presidents};

    presidents->succ->prev = presidents;
}