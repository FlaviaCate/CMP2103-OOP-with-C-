import std;
using namespace std;

// int sum(span<int> s)
// {
// 	int s = 0;
// 	for(int x : s)
// 		s += x;
// 	return s;
// }

// int arr[100];
// // …
// int r = sum(arr);

// int main()
// {
//     int arr[100];
//     // …
//     int r = sum(arr);
// }

import std;

int sum(span<int> values)
{
    int s = 0;

    for (int x : values) // for every number in array
        s += x;

    return s;
}

int main()
{
    int data[] = {1, 2, 3, 4, 5};

    span<int, 5> arr{data}; // span does not store the elements. It provides a view of existing array

    println("Sum = {}", sum(arr));
}

