#include <iostream>
int check_sign(const char*& ptr){
    if (*ptr == '-'){
        ptr = ptr+1;
        return -1;
    }
    else {
        if (*ptr == '+'){
            ptr = ptr+1;
        }
        return 1;
    }
    
}

int integer_part(const char*& ptr){
    const char* start = ptr;
    while (*ptr != '\0' && *ptr != '.' && *ptr != ','){
        ptr++;
    }
    return ptr-start;
    /// получаем длину целой части
}

int compare_integer_part(const char* start1, const char* start2, int len){
    for (int i = 0; i < len; i++){
        if (*start1 > *start2){
            return 1;
        }
        else if (*start2 > *start1){
            return -1;
        }
        start1++;
        start2++;
    }
    return 0;
}

int compare_float_part(const char*& ptr1, const char*& ptr2){
    if (*ptr1 == '.' || *ptr1 == ',') ptr1++;
    if (*ptr2 == '.' || *ptr2 == ',') ptr2++;
    while (*ptr1 != '\0' && *ptr2 != '\0'){
        if (*ptr1 > *ptr2) return 1;
        if (*ptr2 > *ptr1) return -1;
        ptr1++;
        ptr2++;
    }
    if (*ptr1 != '\0') return 1;
    if (*ptr2 != '\0') return -1;

    return 0; /// числа равны
}

int compare_numbers(const char* ptr1, const char* ptr2){
    int result = 0;
    int sign1 = check_sign(ptr1);
    int sign2 = check_sign(ptr2);

    if (sign1 != sign2){
        if (sign1 == 1) return 1; //greater
        return -1; //less
    }

    const char* start1 = ptr1;
    const char* start2 = ptr2;

    int len1 = integer_part(ptr1);
    int len2 = integer_part(ptr2);

    if (len1 != len2){
        if (len1 > len2)
            result = 1; //greater
        else result = -1; //less
        return result;
    }

    int integer_compare_res = compare_integer_part(start1,start2,len1); ///либо len1 либо len2 подставляем, так как на данном этапе len1 = len2
    if (integer_compare_res == 1) result = 1;
    if (integer_compare_res == -1) result = -1;

    int float_compare_res = compare_float_part(ptr1,ptr2);
    if (float_compare_res == 1) result = 1;
    if (float_compare_res == -1) result = -1;

    if (sign1 == -1){ ///учитываем инвертированную проверку если числа отрицательные
        return -result;
    }
    return result;
}

int main(int argc, char* argv[]){
    if (argc < 3){
        std::cout << "Minimum 3 arguments" << "\n";
        return 1;
    }

    int res = compare_numbers(argv[1],argv[2]);
    if (res == 1){
        std::cout << "Greater" << "\n";
    }
    if (res == 0){
        std::cout << "Equal" << "\n";
    }
    if (res == -1){
        std::cout << "Less" << "\n";
    }
    
}
