/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
int* repeatedNumber(const int* A, int n1, int *len1) {
    long long sum = 0;
    long long sumOfSquares = 0;
    long long expectedSum = (long long)n1 * (n1 + 1) / 2;
    long long expectedSumOfSquares = (long long)n1 * (n1 + 1) * (2 * n1 + 1) / 6;
    int i;
    for ( i = 0; i < n1; i++) {
        sum += A[i];
        sumOfSquares += (long long)A[i] * A[i];
    }

    long long diffSum = expectedSum - sum; // x - y
    long long diffSumOfSquares = expectedSumOfSquares - sumOfSquares; // x^2 - y^2

    // x^2 - y^2 = (x - y)(x + y)
    // x + y = (x^2 - y^2) / (x - y)
    long long sumXplusY = diffSumOfSquares / diffSum; // x + y

    long long x = (diffSum + sumXplusY) / 2;
    long long y = sumXplusY - x;

    int* result = (int*)malloc(2 * sizeof(int));
    result[0] = (int)y; // repeated number
    result[1] = (int)x; // missing number
    *len1 = 2;

    return result;
}
