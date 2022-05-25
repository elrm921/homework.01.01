#include <iostream>
#include <fstream>

void read_input(std::ifstream &input, int* arr, int size);
void shift_left(int* arr, int size);
void shift_right(int* arr, int size);
void write_output(std::ofstream &output, int* arr, int size);

int main() {
    std::ifstream input("in.txt");
    int size_arr_1, size_arr_2;

    input >> size_arr_1;
    if (size_arr_1 < 1) {
        std::cerr << "Неправильный размер массива";
        return 1;
    }

    int *arr_1 = new int[size_arr_1];
    read_input(input, arr_1, size_arr_1);

    input >> size_arr_2;
    if (size_arr_2 < 1) {
        std::cerr << "Неправильный размер массива";
        return 1;
    }

    int *arr_2 = new int[size_arr_2];
    read_input(input, arr_2, size_arr_2);
    input.close();

    shift_left(arr_1, size_arr_1);
    shift_right(arr_2, size_arr_2);

    std::ofstream output("out.txt");
    write_output(output, arr_2, size_arr_2);
    write_output(output, arr_1, size_arr_1);
    output.close();

    return 0;
}

void read_input(std::ifstream &input, int* arr, int size) {
    for (int i = 0; i < size; i++) {
        input >> arr[i];
    }
}

void shift_left(int* arr, int size) {
    int temp_first, temp_this;

    for (int i = 0; i < size; i++) {
        if (i == 0) {
            temp_first = arr[i];
        }
        if (i > 0 && i < size) {
            temp_this = arr[i];
            arr[i - 1] = temp_this;
        }
        if (i == size - 1) {
            arr[i] = temp_first;
        }
    }
}

void shift_right(int* arr, int size) {
    int temp_last, temp_this;

    for (int i = size - 1; i >= 0; i--) {
        if (i == size - 1) {
            temp_last = arr[i];
        }
        if (i >= 0 && i < size - 1) {
            temp_this = arr[i];
            arr[i + 1] = temp_this;
        }
        if (i == 0) {
            arr[i] = temp_last;
        }
    }
}

void write_output(std::ofstream &output, int* arr, int size) {
    output << size << "\n";
    for (int i = 0; i < size; i++) {
        output << arr[i] << " ";
    }
    output << "\n";
}