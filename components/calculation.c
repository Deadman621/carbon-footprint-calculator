#include<stdio.h>
#include<stdlib.h>

float HouseholdEmission(int total_electricity_unites, int total_gas_unites){
    float Erate = 0.309;   //Co2 released (in kg) per kwh
    float Gtokwh = 11.2 ;  //cubic meter (of gas) to kwh
    float Grate = 0.203;   //Co2 released (in kg) per kwh

    float electricity_emission = total_electricity_unites * Erate;
    float gas_emission = (total_gas_unites * Gtokwh) * Grate;

    return (electricity_emission + gas_emission);
}

float TransportEnergy(float vehicle_total, int flight){
    float Vrate = 10.9;   //Co2 released (in kg) per gallons
    float Frate = 250.0;   //Co2 released (in kg) per hours of flight

    float vehicle_emission = vehicle_total * Vrate;
    float flight_emission = flight * Frate;

    return (vehicle_emission + flight_emission);
}

float Foodemission(float organic_food_percentage, float inorganic_food_percentage, float locally_produced_food){
    float avgConsumption = 75.0; //Food consumed in kg in a month
    float Orate = 1.0;   //Co2 released (in kg) for 1 kg of organic food
    float Irate = 0.8;   //Co2 released (in kg) for 1 kg of inorganic food
    float Lrate = 0.5;   //Co2 released (in kg) for 1 kg of locally produced food

    float OrganicConsumption = avgConsumption * organic_food_percentage / 100;
    float InorganicConsumption = avgConsumption * inorganic_food_percentage / 100;
    float LocalConsumption = avgConsumption * locally_produced_food / 100;

    float organic_emission = OrganicConsumption * Orate;
    float inorganic_emission = InorganicConsumption * Irate;
    float local_emission = LocalConsumption * Lrate;

    return (organic_emission + inorganic_emission + local_emission);
}

// QtyRequested means number of previous total requested, 
// If number of previous total stored < QtyRequested, 
// then all available previous totals are given in total array 
// and QtyRequested is updated.
int retrive(float total[], int *QtyRequested){ 



    FILE *fptr = fopen("Data Base File.txt","r");

    if (fptr == NULL) {
        return 0; // Returning 0 if file does not exist
    }

    int count = 0, i;
    float temp;
    int line;
    
    
    do {
        line = fscanf(fptr, "%f", &temp); // fscanf returns 1 if it successfully reads %f
        if(line == 1) {
            count++;
        }
    } while(line != EOF);


    
    if (count == 0) {
        fclose(fptr);
        return 0; // Returning 0 if file is empty
    }

    rewind(fptr);

    if (count < *QtyRequested) {

        for(i = 0; i < count; i++) {
            fscanf(fptr, "%f", &total[i]);
        }
        *QtyRequested = count;

    } else {

        int start = count - *QtyRequested, i;

        for(i = 0; i < start; i++) {
            fscanf(fptr, "%f", &temp); 
        }

        for(i = 0; i < *QtyRequested; i++) {
            fscanf(fptr, "%f", &total[i]);
        }

    }

    fclose(fptr);
    return 1;
}