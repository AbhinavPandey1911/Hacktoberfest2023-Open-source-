#include <iostream>
#include <vector>
/*


Radix sort is a non-comparative sorting algorithm that works by distributing 
elements into buckets according to their individual digits. It processes 
the digits from the least significant digit (LSD) to the most significant
digit (MSD) or vice versa. The algorithm is often used for sorting integers, 
but it can be adapted for other data types. Here's a C++ code for radix sort 
with comments explaining the logic:

*/
// Function to find the maximum element in an array
int findMax(const std::vector<int>& arr) {
    int max = arr[0];
    for (int element : arr) {
        if (element > max) {
            max = element;
        }
    }
    return max;
}

// Function to perform counting sort on the array based on a specific digit
void countingSort(std::vector<int>& arr, int exp) {
    const int radix = 10; // Base 10 for integers
    int n = arr.size();
    std::vector<int> output(n, 0);
    std::vector<int> count(radix, 0);

    // Count the occurrences of each digit at the given position
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % radix;
        count[digit]++;
    }

    // Update the count array to store the position of each digit
    for (int i = 1; i < radix; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array based on the position of each digit
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % radix;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy the sorted output to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Radix Sort function
void radixSort(std::vector<int>& arr) {
    int max = findMax(arr);

    // Perform counting sort for each digit, starting from the least significant
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

int main() {
    std::vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    
    std::cout << "Original Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    radixSort(arr);

    std::cout << "Sorted Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
