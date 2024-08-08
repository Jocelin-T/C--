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

// **** Possibility to return type: **** //
// "auto"
template<typename T1, typename T2>
auto Multiply1(const T1& a, const T2& b){
    return a * b;
}
// "-> decltype()" still require "auto"
template<typename T1, typename T2>
auto Multiply2(const T1& a, const T2& b) -> decltype(a * b){
    return a * b;
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

    std::cout << Multiply1<float, int>(7.53f, 5) << "\n"; 
    std::cout << Multiply2<float, int>(7.53f, 5) << "\n"; 

    return 0;
}
