#include <iostream>
#include <iomanip>

int main() {
    const int n = 10000000;
    float sum = 0.0;
    float num = 1.5;

    for (int i = 0; i < n; ++i) {
        sum += num;
    }

    std::cout << std::fixed << sum << '\n';
}

// 17203796.000000 instead of 15000000.000000

/*
for.body:
  %1 = load float, ptr %num, align 4  -> load 1.5 from memory
  %2 = load float, ptr %sum, align 4  -> load calc value from memory (default 0.0) 
  %add = fadd float %2, %1            -> add them and store temporary into var (Result is rounded according to IEEE-754 rules)
  store float %add, ptr %sum, align 4 -> store var value into memory by pointer of sum
  br label %for.inc                   -> this jumps to the for.inc block to increment i
*/


// because on every iteration the number is rounded to nearest representable float we get wrong result
// If change to fixed point (double) we'll get the exact result
