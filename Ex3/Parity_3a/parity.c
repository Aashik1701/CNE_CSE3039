#include <stdio.h>

int main() {
    int n, b;
    printf("Enter the number of msgs : \n");
    scanf("%d", &n);

    printf("Enter the number of bits : \n");
    scanf("%d", &b);


    char m[n][b+1]; // Include space for the null terminator

    for (int i = 0; i < n; i++) {
        printf("Enter a %d-bit string for message %d: ", b, i + 1);
        scanf("%s", m[i]);
    }

    int flag;
    printf("Enter 0 for Even Parity and 1 for Odd Parity: \n");
    scanf("%d", &flag);

    for (int i = 0; i < n; i++) {
        int row_count = 0;
        for (int j = 0; j < b; j++) { 
            if (m[i][j] == '1') {
                row_count++;
            }
        }
        if (row_count % 2 == flag) {
            printf("%s0\n", m[i]);
        } else {
            printf("%s1\n", m[i]);
        }
    }
    return 0;
}

