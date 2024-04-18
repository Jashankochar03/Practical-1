# Practical-1

Here's a README file for the analysis and design of the binary search algorithm:

---

# AIM - Analysis and Design of Binary Search Algorithm

## Binary Search

Binary Search is a searching algorithm used in a sorted array by repeatedly dividing the search interval in half. The idea of binary search is to utilize the information that the array is sorted.

### Algorithm

```cpp
BinSearch(a, n, x) {
    low := 1;
    high := n;
    while (low < high) do {
        mid = (low + high) / 2;
        if (x < a[mid])
            high = mid - 1;
        else if (x > a[mid])
            low = mid + 1;
        else
            return mid;
    }
    return 0;
}
```

## Source Code

```cpp
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int size = 100000;

void sorted_generator(int a[], int n) {
    for (int i = 0; i < n; i++) {
        a[i] = i;
    }
}

void binary_search(int a[], int stop, int n_to_search, int start = 0) {
    int mid = start + (stop - start) / 2;
    if (start > stop) {
        cout << "Number not found in array" << endl;
        return;
    } else {
        if (a[mid] == n_to_search) {
            cout << "Number found" << endl;
            return;
        } else if (a[mid] > n_to_search) {
            stop = mid - 1;
            binary_search(a, stop, n_to_search, start);
        } else {
            start = mid + 1;
            binary_search(a, stop, n_to_search, start);
        }
    }
}

int main() {
    int a[size];
    fstream file;
    file.open("binary_search_result.txt", ios::out);
    for (int i = 1; i <= size; i = i * 10) {
        int avg_time = 0;
        int total_time = 0;
        sorted_generator(a, i);
        for (int m = 0; m < 10; m++) {
            auto start = high_resolution_clock::now();
            binary_search(a, i - 1, 3000001);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            total_time += duration.count();
        }
        avg_time = total_time / 10;
        cout << "Average time taken for size of array = " << i << " is " << avg_time << " microseconds" << endl;
        file << i << "   " << avg_time << endl;
    }
    return 0;
}


## Usage

1. Compile the Source Code: Compile the provided source code using a C++ compiler.

2. Run the Executable: Run the compiled executable to perform binary search on arrays of various sizes.

3. Output: The program outputs the average time taken for each array size to the console and writes the results to a text file named `binary_search_result.txt`.

## Note

- This implementation of the binary search algorithm is for educational purposes and may not be optimal for all scenarios.
- Ensure that the input array is sorted before performing binary search.
