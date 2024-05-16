#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Non-recursive function to compute T(n)
int NRT(int n) {
    int T[n + 1];
    T[0] = 1;
    T[1] = 3;

    for(int i = 2; i <= n; i++) {
        T[i] = 4 * T[i-1] - 3 * T[i-2] + 4;
    }

    return T[n];
}

// Recursive function to compute T(n)
int RT(int n) {
    if (n == 0) {
        return 1;
    } else if (n == 1) {
        return 3;
    }
    return 4 * RT(n-1) - 3 * RT(n-2) + 4;
}

// Closed-form solution function to compute T(n)
int T(int n) {
    return 2 * (pow(3, n)) - (2 * n) - 1; 
}

int main() {
    int n;
    
    printf("Input the value for N: ");
    scanf("%d", &n);

    // Call the functions NRT() RT() T()
    int nrt = NRT(n);
    int rt = RT(n);
    int t = T(n); 

    // Display the results
    printf("The Non-Recursive Function: %d\n", nrt);
    printf("The Recursive Function: %d\n", rt);
    printf("The Closed-Form Function: %d\n", t);

    // Check if all values are equal
    if (nrt == rt && rt == t) {
        printf("All methods produce the same result.\n");
    } else {
        printf("Methods produce different results.\n");
    }

    return 0;
}
