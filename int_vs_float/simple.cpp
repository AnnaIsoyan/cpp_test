#include <iostream>
#include <chrono>

double benchmark_int_add(int a, int b, int n) {
    int res = 0;
    auto start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < n; ++i) {
        res = a + b;
    }
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double, std::nano>(end - start).count() / n;
}

double benchmark_int_mul(int a, int b, int n) {
    int res = 0;
    auto start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < n; ++i) {
        res = a * b;
    }
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double, std::nano>(end - start).count() / n;
}

double benchmark_float_add(float a, float b, int n) {
    float res = 0.0;
    auto start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < n; ++i) {
        res = a + b;
    }
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double, std::nano>(end - start).count() / n;
}

double benchmark_float_mul(float a, float b, int n) {
    float res = 0.0;
    auto start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < n; ++i) {
        res = a * b;
    }
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double, std::nano>(end - start).count() / n;
}

int main() {
    const int n = 100000000;

    int a_int = 123, b_int = 456;
    float a_float = 123.0, b_float = 456.0;

    std::cout << "int add: " << benchmark_int_add(a_int, b_int, n) << " ns per op\n";
    std::cout << "int mul: " << benchmark_int_mul(a_int, b_int, n) << " ns per op\n";
    std::cout << "float add: " << benchmark_float_add(a_float, b_float, n) << " ns per op\n";
    std::cout << "float mul: " << benchmark_float_mul(a_float, b_float, n) << " ns per op\n";
    std::cout << "int add: " << benchmark_int_add(a_int, b_int, n) << " ns per op\n";

    return 0;
}

/*
  about 400 lines in LLVM IR

  for.body:
    %2 = load i32, ptr %a.addr, align 4
    %3 = load i32, ptr %b.addr, align 4
    %mul = mul nsw i32 %2, %3
    store i32 %mul, ptr %res, align 4
    br label %for.inc

  very fast
  strange behavior - setting int addition into the end we get different score. Because of CPU warm-up I guess

  results

  int add: 0.482508 ns per op
  int mul: 0.352621 ns per op
  float add: 0.354301 ns per op
  float mul: 0.355631 ns per op
  int add: 0.353885 ns per op

  if no strange behavior the int operations are faster
*/