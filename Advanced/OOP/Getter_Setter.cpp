#include <iostream>
// #################################### OOP Getter and Setter ####################################
class pubStove{
    public: // CAN be access from everywhere
        int temperature = 0;
};
class privStove{
    private: // CAN NOT be access from everywhere
        int temperature = 0;

    public:
    // Getter
    int getTemperature(){ 
        return temperature;
    }
    // Setter, can be used in the constructor too!
    void setTemperature(int temperature){
        // Logic can be added here:
        if(temperature < 0){
            this->temperature = 0;
            std::cout << "Temperature can't be less than 0°\n";
            std::cout << "Temperature set to: " << getTemperature() << "\n";
        }
        else if (temperature >= 100){
            this->temperature = 100;
            std::cout << "Temperture can't be more that 100°\n";
            std::cout << "Temperature set to: " << getTemperature() << "\n";
        }
        else{
            this->temperature = temperature; // Or only this line is needed, like a constructor
            std::cout << "Temperature set to: " << getTemperature() << "\n";
        }
    }
};

int main(){
    // Abstration   = hiding unnecessary data from outside a class
    // getter       = function that makes a private attribute READABLE
    // setter       = function that makes a private attribute WRITEABLE

    pubStove stove_1;

    stove_1.temperature = 1000;
    std::cout << "Public Temperature: " << stove_1.temperature << "\n\n";

    privStove stove_2;

    std::cout << "Private Temperature: " << stove_2.getTemperature() << "\n\n";
    stove_2.setTemperature(1000);
    std::cout << "Private Set Temperature: " << stove_2.getTemperature() << "\n\n";

    return 0;
}