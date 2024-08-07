#include <iostream>

// #################################### Array ####################################
double getTotal(double numbers[], int size);
void sortArray(int array[], int size);
int main(){
    // ****************************** Declaration ******************************
    // Pour déclarer un array, il faut d'abord lui dire combien de slot il dispose
    int my_array[3]; // Une fois le nombre de slot donné, il ne peut PAS être modifié
    // Puis donner les valeurs pour chaque slot
    my_array[0] = 10;
    my_array[1] = 15;
    my_array[2] = 20;

    std::cout << my_array[0] << "\n" 
            << my_array[1] << "\n" 
            << my_array[2] << "\n";

    // Ou possible comme ça ET PAS BESOIN de déclarer le nombre de slot
    int my_array_2[] = {1, 2, 3};

    std::cout << my_array_2[0] << "\n" 
            << my_array_2[1] << "\n" 
            << my_array_2[2] << "\n";

    // ****************************** Size of an array ******************************
    // Calculer le nombre d'élément dans un Array
    std::cout << sizeof(my_array) << " bytes\n"; // sizeof(array)
    std::cout << sizeof(int) << " bytes\n"; // sizeof(type of the array)
    std::cout << sizeof(my_array)/sizeof(int) << " elements\n"; // sizeof(array) / sizeof(type of the array) OR
    std::cout << sizeof(my_array)/sizeof(my_array[0]) << " elements\n"; // sizeof(array) / sizeof(1st element of the array)

    // ****************************** Loop true an array (for) ******************************
    for(int i = 0; i < sizeof(my_array)/sizeof(int); i++){
        std::cout << my_array[i] << "\n";
    }

    // ****************************** Loop true an array (foreach) ******************************
    for(int num : my_array_2){
        std::cout << num << "\n";
    }

    // ****************************** Pass an array to a function (function getTotal()) ******************************
    // When passing an array in argument, [] are NOT needed, but
    // size of the array is REQUIRE when passed to a function
    double numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(numbers)/sizeof(numbers[0]);
    std::cout << "Total: " << getTotal(numbers, size) << "\n"; // When passing an array in argument, [] are NOT needed

    // ****************************** Sort an array (function sortArray()) ******************************
    int array_sort[] = {10, 1, 9, 2, 8, 3, 7, 4, 6, 5};
    int size_sort = sizeof(array_sort)/sizeof(array_sort[0]);

    sortArray(array_sort, size_sort);

    for(int element : array_sort){
        std::cout << element << " ";
    }

    return 0;
}

// ****************************** Sort an array (bubble sort) ******************************
void sortArray(int array[], int size){
    int temp; // temporary variable
    for(int i = 0; i < size - 1; i++){ // size -1 because the last element doesn't need to be compared
        for(int j = 0; j < size - i - 1; j++){
            if(array[j] > array[j + 1]){
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp; 
                for(int k = 0; k < size ; k++){
                    std::cout << array[k] << " " ;
                }
                std::cout << "\n";
            }
        }
    }
}

// ****************************** Pass an array to a function ******************************
double getTotal(double numbers[], int size){ // size of the array is REQUIRE when pass to a function
    double result = 0;
    for(int i = 0; i < size; i++){
        result += numbers[i];
    }
    return result;
}