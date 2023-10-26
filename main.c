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

int main(void) {

    int total_energy_units, total_gas_units;
    int electricity_units[12], gas_units[12];


    printf("\nCARBON FOOTPRINT CALCULATOR\n");

    printf("\nHOUSEHOLD ENERGY:\n");

    printf("\n1. Electricity:\nEnter the units consumed in past 12 months given in your Electricity Bill (in kWh):\n");
    EnergyInput(electricity_units);
    total_energy_units = SumArray(12, electricity_units);
    system('cls');

    printf("\n2. Gas:\nEnter the units consumed in past 12 months given in your Gas Bill (in Cubic Metre):\n");
    EnergyInput(gas_units);
    total_energy_units = SumArray(12, gas_units);

    return 0;
}