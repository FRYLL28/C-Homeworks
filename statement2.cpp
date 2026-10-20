#include <iostream>
#include <cmath>
#include <cstdlib>
void reverse_part_of_array(int* start,int* end){
    int* true_start = start;
    for (int i = 0; i<((end-start)/2 + 1);i++){      
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

void print_array(int* array,int len){
    for (int i = 0; i<len ; i++){
        std::cout << array[i] << "\n";
    }
    for (int i = 0; i<len ; i++){
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}

int main(int argc, char* argv[]){
    if (argc < 2){
        std::cout << "Minimum 2 arguments" << "\n";
        return 1;
    }
    const char* ptr = argv[1];
    
    int num = 0;

    while (*ptr != '\0'){
        num = num*10+(*ptr - '0'); //сдвиг по аски
        ptr++;
    }
    int* array = new int[num];
    
    for (int i = 0; i<num; i++){
        std::cin >> array[i];
    }
    int k = 0;
    std::cin >> k;
    if (k>0){
        k = k%num;
    }
    else if (k < 0){
        k = (k+num)%num;
    }
    else{
        print_array(array,num);
        return 0;
    }
    reverse_part_of_array(array,array+num-1);
    reverse_part_of_array(array,array+k-1);
    reverse_part_of_array(array+k,array+num-1);
    print_array(array,num);
    delete[] array;
    return 0;
}