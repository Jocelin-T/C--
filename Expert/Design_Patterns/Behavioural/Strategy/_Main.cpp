#include "Context.hpp"
#include "ConcreteStrategyA.hpp"
#include "ConcreteStrategyB.hpp"

#include <iostream>
#include <memory>

/* #################################### Strategy - Behavioural ####################################
* Notes:   The Strategy pattern is a behavioural design pattern that enables selecting an algorithm at runtime.
* Common Uses:
*/

int main(){

    Context context;
    context.executeStrategy(5);
    std::cout << '\n';

    context.setStrategy(std::make_unique<ConcreteStrategyA>());
    context.executeStrategy(1);
    std::cout << '\n';

    context.setStrategy(std::make_unique<ConcreteStrategyB>());
    context.executeStrategy(2);
    std::cout << '\n';

    return 0;
}