#include "Context.hpp"
#include "ConcreteStateA.hpp"
#include "ConcreteStateB.hpp"

#include <iostream>

/* #################################### State - Behavioural ####################################
* Notes:   The state pattern is used to allow an object to change its behavior when its internal
*          state changes. This pattern is particularly useful when an object has multiple states
*          and the behavior of the object is dependent on the state it is in.
* Common Uses: - User roles rights in an application
*/

int main(){

    Context traffic_light;
    traffic_light.handle();
    std::cout << '\n';
    
    traffic_light.setState(std::make_unique<ConcreteStateA>());
    traffic_light.handle();
    std::cout << '\n';
    
    traffic_light.setState(std::make_unique<ConcreteStateB>());
    traffic_light.handle();
    std::cout << '\n';


    return 0;
}