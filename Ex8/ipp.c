#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_OCTET_SIZE 8
#define MAX_IP_OCTETS 4

int ip[MAX_IP_OCTETS];
int mask[MAX_IP_OCTETS];
int FA[MAX_IP_OCTETS];
int LA[MAX_IP_OCTETS];
int ip_c = 0;

void decimalToBinary(int decimalNum, int* binaryArray) {
    for (int i = MAX_OCTET_SIZE - 1; i >= 0; i--) {
        binaryArray[i] = decimalNum % 2;
        decimalNum /= 2;
    }
}

int binaryToDecimal(int* binaryArray) {
    int decimal = 0;
    for (int i = 0; i < MAX_OCTET_SIZE; i++) {
        decimal += binaryArray[i] * pow(2, MAX_OCTET_SIZE - 1 - i);
    }
    return decimal;
}

void calcCIDR(int maskNum) {
    for (int i = 0; i < MAX_IP_OCTETS; i++) {
        mask[i] = (i < maskNum / MAX_OCTET_SIZE) ? 255 : (i == maskNum / MAX_OCTET_SIZE ? (255 << (MAX_OCTET_SIZE - maskNum % MAX_OCTET_SIZE)) : 0);
        FA[i] = ip[i] & mask[i];
        LA[i] = ip[i] | ~mask[i];
    }

    printf("Subnet(Binary) = ");
    for (int i = 0; i < MAX_IP_OCTETS; i++) {
        int binaryArray[MAX_OCTET_SIZE] = {0};
        decimalToBinary(mask[i], binaryArray);
        for (int j = 0; j < MAX_OCTET_SIZE; j++) {
            printf("%d", binaryArray[j]);
        }
        printf(".");
    }
    printf("\n");

    printf("FA(Binary) = ");
    for (int i = 0; i < MAX_IP_OCTETS; i++) {
        int binaryArray[MAX_OCTET_SIZE] = {0};
        decimalToBinary(FA[i], binaryArray);
        for (int j = 0; j < MAX_OCTET_SIZE; j++) {
            printf("%d", binaryArray[j]);
        }
        printf(".");
    }
    printf("\n");

    printf("LA(Binary) = ");
    for (int i = 0; i < MAX_IP_OCTETS; i++) {
        int binaryArray[MAX_OCTET_SIZE] = {0};
        decimalToBinary(LA[i], binaryArray);
        for (int j = 0; j < MAX_OCTET_SIZE; j++) {
            printf("%d", binaryArray[j]);
        }
        printf(".");
    }
    printf("\n\n");

    printf("Mask = %d.%d.%d.%d\n", mask[0], mask[1], mask[2], mask[3]);
    printf("FA = %d.%d.%d.%d\n", FA[0], FA[1], FA[2], FA[3]);
    printf("LA = %d.%d.%d.%d\n", LA[0], LA[1], LA[2], LA[3]);

    printf("Number of Hosts: %ld\n", (long)pow(2, (32 - maskNum)));
}

int main() {
    char ip_address[16];
    char *token;

    printf("Enter an IP address: ");
    scanf("%15s", ip_address);
    token = strtok(ip_address, ".");

    while (token != NULL) {
        int digit = atoi(token);
        ip[ip_c] = digit;
        ip_c++;
        printf("\n%d\n", digit);

        token = strtok(NULL, ".");
    }

    printf("\nBinary IP = ");
    for (int i = 0; i < MAX_IP_OCTETS; i++) {
        int binaryArray[MAX_OCTET_SIZE] = {0};
        decimalToBinary(ip[i], binaryArray);
        for (int j = 0; j < MAX_OCTET_SIZE; j++) {
            printf("%d", binaryArray[j]);
        }
        printf(".");
    }
    printf("\n");

    int choice, maskNum;
    printf("\n1. Classful\n2. Classless\n3. Exit\n>> Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {

        case 1:
            if (ip[0] >= 1 && ip[0] <= 127) {
                printf("Class A\n");
                printf("IP = %d.%d.%d.%d/8\n", ip[0], ip[1], ip[2], ip[3]);
                calcCIDR(8);
            } else if (ip[0] <= 191) {
                printf("Class B\n");
                printf("IP = %d.%d.%d.%d/16\n", ip[0], ip[1], ip[2], ip[3]);
                calcCIDR(16);
            } else if (ip[0] <= 223) {
                printf("Class C\n");
                printf("IP = %d.%d.%d.%d/24\n", ip[0], ip[1], ip[2], ip[3]);
                calcCIDR(24);
            } else if (ip[0] <= 239) {
                printf("Class D\n");
            } else {
                printf("Class E\n");
            }
            break;

        case 2:
            printf("Enter mask number: ");
            scanf("%d", &maskNum);
            calcCIDR(maskNum);
            break;

        case 3:
            exit(0);
            break;

        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}
