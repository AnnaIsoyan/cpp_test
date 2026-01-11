#include <iostream>

// compile (pre-processor, translator, assembler, linker)

// C++            -> Pre-processor                -> Pure C++         -> -E
// Pure C++       -> Translator (Compilor)        -> LLVM IR          -> -S -emit-llvm
// Pure C++       -> Translator (Compiler)        -> CPU Assembly     -> -S
// CPU Assembly   -> CPU Assembler                -> Object file      -> -c
// Object file    -> Linker                       -> Executable file  -> -o <name> 

int main(int argc, char** argv)
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}