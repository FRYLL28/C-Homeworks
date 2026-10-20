#include <iostream>
double calculate_scalar(double* array, int len){
    double* start_of_array = array;
    double* mid_of_array = start_of_array+len/2;
    double result = 0;
    for (int i = 0; i < len/2; i++){
        result = result+(*start_of_array)*(*mid_of_array);
        start_of_array++;
        mid_of_array++;
    }
    return result;
}

int main(int argc, char* argv[]){
    if (argc < 2){
        std::cout << "Minumum 2 arguments";
        return 1;
    }
    const char* ptr = argv[1];
    int num = 0;
    while (*ptr != '\0'){
        num = num*10+(*ptr - '0'); //сдвиг по аски
        ptr++;
    }
    double* array = new double[num*2];
    for (int i = 0; i<num;i++){
        std::cin >> array[i];
    }
    for (int i = num; i<num*2;i++){
        std::cin >> array[i];
    }
    double res = calculate_scalar(array,num*2);
    std::cout << res << "\n";
    delete[] array;
}