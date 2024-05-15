#include <iostream>

using namespace std;

void print_array(const int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << '\t';
    }
    cout << endl;
}

int* filter_simple(const int* numbers, int size, int& result_size) {
    int* primes = new int[size]; 
    result_size = 0; 
    for (int i = 0; i < size; ++i) {
        bool is_prime = true;
        for (int j = 2; j * j <= numbers[i]; ++j) {
            if (numbers[i] % j == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime && numbers[i] > 1) {
            primes[result_size] = numbers[i];
            ++result_size;
        }
    }

    int* resized_primes = new int[result_size];
    for (int i = 0; i < result_size; ++i) {
        resized_primes[i] = primes[i];
    }
    delete[] primes; 

    return resized_primes;
}

int* filter_multiple_of_three(const int* numbers, int size, int& result_size) {
    int* multiples = new int[size];
    result_size = 0; 
    for (int i = 0; i < size; ++i) {
        if (numbers[i] % 3 == 0) {
            multiples[result_size] = numbers[i];
            ++result_size;
        }
    }

    int* resized_multiples = new int[result_size];
    for (int i = 0; i < result_size; ++i) {
        resized_multiples[i] = multiples[i];
    }
    delete[] multiples;

    return resized_multiples;
}

int* filter_even(const int* numbers, int size, int& result_size) {
    int* evens = new int[size];
    result_size = 0;
    for (int i = 0; i < size; ++i) {
        if (numbers[i] % 2 == 0) {
            evens[result_size] = numbers[i];
            ++result_size;
        }
    }

    int* resized_evens = new int[result_size];
    for (int i = 0; i < result_size; ++i) {
        resized_evens[i] = evens[i];
    }
    delete[] evens;

    return resized_evens;
}

int main() {
    const int size = 7;
    int arr[size] = { 99, 33, 8, 7, 77, 89, 44};

    int result_size;

    cout << "Original array: ";
    print_array(arr, size);

    int* primes = filter_simple(arr, size, result_size);
    cout << "Prime numbers: ";
    print_array(primes, result_size);
    delete[] primes;

    int* multiples_of_three = filter_multiple_of_three(arr, size, result_size);
    cout << "Numbers multiple of three: ";
    print_array(multiples_of_three, result_size);
    delete[] multiples_of_three;

    int* evens = filter_even(arr, size, result_size);
    cout << "Even numbers: ";
    print_array(evens, result_size);
    delete[] evens;

    return 0;
}
