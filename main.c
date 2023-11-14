#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include"CGLib/src/cglib.h"
#include"CGLib/src/cglib-other.h"

int SumArrayInt(int n, int arr[]);
int SumArrayFloat(int n, float arr[]);
int DataValidationInteger(char str[], int  variable);
float DataValidationFloat(char str[], float  variable);
int yes_no(char variable);
int VehicleIO(float arr[][2], float product[], int number_of_vehicles);
void EnergyInput(int energy_type[]);

int main(void) {

// Variables to be used for Calculations:

    int total_electricity_units, total_gas_units, flights; 
    float vehicle_total, organic_food_percentage, inorganic_food_percentage, vegetarian_food_percentage, locally_produced_food;

// Calculate and print only if above values are not zero.

// Variables for Storing Data (Not to be used for Calcultions)

    int number_of_vehicles, flights_y_n;
    int electricity_units[12], gas_units[12];

    printf("\nCARBON FOOTPRINT CALCULATOR\n");

// HouseHold Energy Input

    printf("\nHOUSEHOLD ENERGY:\n");

// Electricity Input

    printf("\n1. Electricity:\nEnter the units consumed in past 12 months given in your Electricity Bill (in kWh):\n");
    EnergyInput(electricity_units);
    total_electricity_units = SumArrayInt(12, electricity_units);

// Gas Input

    printf("\n2. Gas:\nEnter the units consumed in past 12 months given in your Gas Bill (in Cubic Metre):\n");
    EnergyInput(gas_units);
    total_gas_units = SumArrayInt(12, gas_units);

// Transportation Input

    printf("\nTRANSPORTATION:\n");

// Input for Vehicles

    printf("How many Vehicles do you own?: ");
    number_of_vehicles = DataValidationInteger("Number of Vehicles", number_of_vehicles);
    
    float vehicles[number_of_vehicles][2]; 
    float total_miles_driven_all_cars[number_of_vehicles];
    vehicle_total = VehicleIO(vehicles, total_miles_driven_all_cars, number_of_vehicles);
    if (vehicle_total == 0)
        printf("Skipping Over Vehicle Calculation.");

// Input for Flights

    printf("\nDid You Take Any Flights In the Past 12 Months? (y/n): ");
    scanf("%c", &flights_y_n);

    if (yes_no(flights_y_n) == 1) {
        printf("\nEnter Hours of Flights Taken: ");
        DataValidationInteger("Hours of Flights Taken", flights);
    }
    else printf("Skipping Over Flight Calculation.");


// Input for Food

    puts("");
    printf("\nFOOD:\n");

    printf("\nHow much percent of your food is Organic on Monthly basis (approx.)?: ");
    DataValidationFloat("Percentage of Organic Food Consumed", organic_food_percentage);

    puts("");
    printf("How much percent of your food is vegetarian on Monthly basis (approx.)?: ");
    DataValidationFloat("Percentage of Veggies Consumed", inorganic_food_percentage);

    puts("");
    printf("How much percent of your food is prepared locally (approx.)?: ");
    DataValidationFloat("Percentage of Locally Produced Food", locally_produced_food);
    puts("");

    return 0;
}