int result[100];
int resultIndex = 0;

void addFactor(int factor)
{
    result[resultIndex] = factor;
    ++resultIndex;
    result[resultIndex] = 0; // zero-terminate the array
}

void resetFactors()
{
    resultIndex = 0;
    result[0] = 0; // zero-terminate the array
}

int* getFactors(unsigned int n)
{
    // {} -> {2}
    // {2} -> {n}
    // Added if
    // if -> while
    // 2, 3 -> factor
    // if -> while
    resetFactors();
    int factor = 2;
    while (n > 1)
    {
        while (n % factor == 0)
        {
            addFactor(factor);
            n = n / factor;
        }
        ++factor;
    }

//    addFactor(n);
    return result;
}