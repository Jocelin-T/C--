#include <cstddef> // for typeid()
#include <iostream>
// #include <typeinfo> // for typeid()

// #################################### Multiple Template ####################################
// Notes:   In the template argument, it's possible to write object type (typename) or 
//           non-object type (size_t).
//          typeid() function return the data type, i => integer, f => float, ...


template<typename T1, typename T2> 
void Foo(T1 x, T2 y){
    std::cout << typeid(x).name() << "\n";
    std::cout << y << "\n";
}

// This function template is like an array.
// T => the data type (int, float, ...)
// N => the number of loop (in this case)
template<typename T, size_t N>
void Foo2(T x){
    for(size_t i = 0; i < N; i++){
        std::cout << typeid(N).name() << "\n";
        std::cout << N << "\n";
    }
    std::cout << typeid(x).name() << "\n";
}

int main(){

    Foo<int, float>(5, 3.14f);
    Foo2<int, 5>(3);

    return 0;
}
