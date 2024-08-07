#include <iostream>
#include <string>

// #################################### Multidimensional Array (2D) ####################################
int main(){
    // array_name[rows][columns], when initialized [columns] is NEEDED, but not [rows] 
    std::string cars[][3] = {{"Mustang", "Escape", "F-150"}, 
                            {"Corvette", "Equinox", "Silverado"},
                            {"Challenger", "Durango", "Ram 1500"}};

    // for display an element:
    std::cout << cars[0][0] << " ";

    // for the number of rows and columns:
    int rows = sizeof(cars)/sizeof(cars[0]);
    int columns = sizeof(cars[0])/sizeof(cars[0][0]);

    // ****************************** Loop trough a Multidimensional Array ******************************
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            std::cout << cars[i][j] << " ";
        }
        std::cout << "\n";
    }
    

    return 0;
}