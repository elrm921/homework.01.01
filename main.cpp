#include <iostream>
#include <fstream>

void read_input(std::ifstream &input, int* arr, int size);
void shift_left(int* arr, int size);
void shift_right(int* arr, int size);
void write_output(std::ofstream &output, int* arr, int size);

int main() {
    std::ifstream input("in.txt");

    int size_arr_1;
    int size_arr_2;

    input >> size_arr_1;
    int arr_1[size_arr_1];
    read_input(input, arr_1, size_arr_1);

    input >> size_arr_2;
    int arr_2[size_arr_2];
    read_input(input, arr_2, size_arr_2);
    input.close();

    shift_left(arr_1, size_arr_1);
    shift_right(arr_2, size_arr_2);

    std::ofstream output("out.txt");
    write_output(output, arr_2, size_arr_2);
    write_output(output, arr_1, size_arr_1);
    output.close();

}

void read_input(std::ifstream &input, int* arr, int size) {
    for (int i = 0; i < size; i++) {
        input >> arr[i];
    }
}

void shift_left(int* arr, int size) {
    int temp[size];
    for (int i = 0; i < size; i++) {
        if (i == 0) {
            temp[size - 1] = arr[0];
        }
        else if (i > 0 && i < size) {
            temp[i - 1] = arr[i];
        }
    }
    for (int i = 0; i < size; i++) {
        arr[i] = temp[i];
    }
}

void shift_right(int* arr, int size) {
    int temp[size];
    for (int i = 0; i < size; i++) {
        if (i == size - 1) {
            temp[0] = arr[size - 1];
        }
        else if (i >= 0 && i < size - 1) {
            temp[i + 1] = arr[i];
        }
    }
    for (int i = 0; i < size; i++) {
        arr[i] = temp[i];
    }
}

void write_output(std::ofstream &output, int* arr, int size) {
    output << size << "\n";
    for (int i = 0; i < size; i++) {
        output << arr[i] << " ";
    }
    output << "\n";
}