#include <iostream>
#include <chrono>
#include <functional>

template<typename T>
double benchmark(T a, T b, int n, const std::function<T(T,T)>& op) {
    T res{};
    auto start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < n; ++i) {
        res = op(a, b);
    }
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double, std::nano>(end - start).count() / n;
}

int main() {
    const int n = 100'000'000;

    int ai = 123, bi = 456;
    float af = 123.0f, bf = 456.0f;

    std::cout << "int add: " 
              << benchmark<int>(ai, bi, n, [](int x,int y){ return x+y; }) 
              << " ns per op\n";

    std::cout << "int mul: " 
              << benchmark<int>(ai, bi, n, [](int x,int y){ return x*y; }) 
              << " ns per op\n";

    std::cout << "float add: " 
              << benchmark<float>(af, bf, n, [](float x,float y){ return x+y; }) 
              << " ns per op\n";

    std::cout << "float mul: " 
              << benchmark<float>(af, bf, n, [](float x,float y){ return x*y; }) 
              << " ns per op\n";

    return 0;
}

/*
  LLVM IR has generated specilized versions of benchmark for int and float
  about 1900 lines of code generated

  for.body:
    %2 = load ptr, ptr %op.addr, align 8
    %3 = load i32, ptr %a.addr, align 4
    %4 = load i32, ptr %b.addr, align 4
    %call2 = call noundef i32 @_ZNKSt8functionIFiiiEEclEii(ptr noundef ... %2, i32 noundef %3, i32 noundef %4)
    store i32 %call2, ptr %res, align 4
    br label %for.inc

    instead of simple add it jumps into std::function per iteration, which is overhead
    we face to the runtime polymorphism (deciding what to do at runtime via a function pointer) using std::function

    as a result we have a very bad performance
    code works extremaly slow

    results

    int add: 6.53459 ns per op
    int mul: 6.50087 ns per op
    float add: 6.56625 ns per op
    float mul: 6.68719 ns per op

    int operations are faster
*/