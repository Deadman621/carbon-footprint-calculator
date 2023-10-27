#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include"CGLib/src/cglib.h"
#include"CGLib/src/cglib-other.h"

int SumArray(int n, int arr[]) {

    int sum;
    for(int i = 0; i < n; i++) 
        sum += arr[i];

    return sum;
}

void EnergyInput(int energy_type[]) {
    for(int i = 0, valid = 0; i < 12; i++) {
        printf("Enter for Month (#%d): ", i+1);
        valid = scanf("%d", &energy_type[i]);
        if (valid != 1) {
            while (valid != 1) {
                while ((getchar()) != '\n');
                printf("Invalid Input! Re-enter Value for Month (#%d): ", i+1);
                valid = scanf("%d", &energy_type[i]);
            }
        }
    }
}

