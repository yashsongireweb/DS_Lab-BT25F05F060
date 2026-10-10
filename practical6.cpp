
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;
using namespace chrono;

// Merge two sorted vectors
vector<int> merge(vector<int> left, vector<int> right) {
    vector<int> result;
    int i = 0, j = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            result.push_back(left[i++]);
        } else {
            result.push_back(right[j++]);
        }
    }

    while (i < left.size()) {
        result.push_back(left[i++]);
    }

    while (j < right.size()) {
        result.push_back(right[j++]);
    }

    return result;
}

// Merge Sort
vector<int> mergeSort(vector<int> arr) {
    if (arr.size() <= 1) {
        return arr;
    }

    int mid = arr.size() / 2;

    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());

    return merge(mergeSort(left), mergeSort(right));
}

// Bubble Sort
vector<int> bubbleSort(vector<int> arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }

    return arr;
}

// Print vector
void printArray(const vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    vector<int> data = {38, 27, 43, 3, 9, 82, 10, 3};

    cout << "Original:    ";
    printArray(data);

    cout << "Merge Sort:  ";
    printArray(mergeSort(data));

    cout << "Bubble Sort: ";
    printArray(bubbleSort(data));

    // Verify results
    vector<int> expected = data;
    sort(expected.begin(), expected.end());

    if (mergeSort(data) == expected &&
        bubbleSort(data) == expected) {
        cout << "\nBoth sorting algorithms passed the test!\n";
    }

    // Generate 3000 random integers
    vector<int> big(3000);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, 100000);

    for (int& x : big) {
        x = dist(gen);
    }

    // Time Merge Sort
    auto start = high_resolution_clock::now();
    mergeSort(big);
    auto end = high_resolution_clock::now();

    cout << "Merge Sort on 3000 items: "
         << duration<double>(end - start).count()
         << " seconds\n";

    // Time Bubble Sort
    start = high_resolution_clock::now();
    bubbleSort(big);
    end = high_resolution_clock::now();

    cout << "Bubble Sort on 3000 items: "
         << duration<double>(end - start).count()
         << " seconds\n";

    return 0;
}