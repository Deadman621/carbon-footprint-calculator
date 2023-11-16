#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<unistd.h>
#include<limits.h>

int CurrentWorkingDirectory(char directory[]) {;
   char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
       strcpy(directory, cwd);
    else {
       perror("getcwd() error");
       return 1;
    }
    return 0;
}

int SumArrayInt(int n, int arr[]) {
    int sum;
    for(int i = 0; i < n; i++) 
        sum += arr[i];

    return sum;
}

float SumArrayFloat(int n, float arr[]) {
    float sum;
    for(int i = 0; i < n; i++) 
        sum += arr[i];

    return sum;
}

int DataValidationInteger(char str[], int  variable) {
    int valid;
    valid = scanf("%d", &variable);
    if (valid != 1 || variable < 0) {
        while(valid != 1 || variable < 0) {
            while ((getchar()) != '\n');
            printf("Invalid Input! Renter Value for %s: ", str);
            valid = scanf("%d", &variable);
            if (variable < 0)
                valid = 2;
        }
    }
    return variable;
}

float DataValidationFloat(char str[], float variable) {
    int valid;
    valid = scanf("%f", &variable);
    if (valid != 1 || variable < 0) {
        while(valid != 1 || variable < 0) {
            while ((getchar()) != '\n');
            printf("Invalid Input! Renter Value for %s: ", str);
            valid = scanf("%f", &variable);
            if (variable < 0)
                valid = 2;
        }
    }
    return variable;
}

int yes_no(char variable) {
    if (variable == 'y') 
        return 1;
    else if (variable == 'n')
        return 0;
    else {
        while ((getchar()) != '\n');
        printf("Invalid Input! Please Answer in (y/n): ");
        scanf("%c", &variable);
        yes_no(variable);
    }
}

void EnergyInput(int energy_type[]) {
    for(int i = 0, valid = 0; i < 12; i++) {
        printf("Enter for Month (#%d): ", i+1);
        valid = scanf("%d", &energy_type[i]);
        if (valid != 1 || energy_type[i] < 0) {
            while (valid != 1 || energy_type[i] < 0) {
                while ((getchar()) != '\n');
                printf("Invalid Input! Re-enter Value for Month (#%d): ", i+1);
                valid = scanf("%d", &energy_type[i]);
                if (energy_type[i] < 0)
                    valid = 2;
            }
        }
    }
}

float VehicleIO(float arr[][2], int number_of_vehicles) {

    float product[number_of_vehicles];

    if (number_of_vehicles == 0) 
        return 0;
    else if (number_of_vehicles == 1) {
        printf("Enter The Consumption of Fuel Per Mile For Your Vehicle (In Gallons): ");
        arr[0][0] = DataValidationFloat("Consumption of Fuel Per Mile", arr[0][0]);
        printf("Enter The Miles Travelled in 12 Months for your Vehicle: ");
        arr[0][1] = DataValidationFloat("Miles Travelled in 12 Months for your Vehicle", arr[0][1]);
    }
    else {
        for(int i = 0, valid = 0; i < number_of_vehicles; i++) {
            printf("Enter the Consumption of Fuel Per Mile For Vehicle (#%d) (In Gallons): ", i+1);
            valid = scanf("%f", &arr[i][0]);
            if (valid != 1 || arr[i][0] < 0) {
                while (valid != 1 || arr[i][0] < 0) {
                    while ((getchar()) != '\n');
                    printf("Invalid Input! Re-enter Value for the Consumption of Fuel Per Mile For Vehicle (#%d) (In Gallons): ", i+1);
                    valid = scanf("%f", &arr[i][0]);
                    if (arr[i][0] < 0)
                        valid = 2;
                }
            }
        }
        for(int i = 0, valid = 0; i < number_of_vehicles; i++) {
            printf("Enter the Miles Driven in 12 Months For Vehicle (#%d): ", i+1);
            valid = scanf("%f", &arr[i][1]);
            if (valid != 1 || arr[i][1] < 0) {
                while (valid != 1 || arr[i][1] < 0) {
                    while ((getchar()) != '\n');
                    printf("Invalid Input! Re-enter Value for the Miles Drived in 12 Months For Vehicle (#%d): ", i+1);
                    valid = scanf("%f", &arr[i][1]);
                    if (arr[i][1] < 0)
                        valid = 2;
                }
            }
        }
    }

    for(int i = 0, j = 0; i < number_of_vehicles; i++, j = 0)
        product[i] = arr[i][j] * arr[i][j+1];

    return SumArrayFloat(number_of_vehicles, product);
}