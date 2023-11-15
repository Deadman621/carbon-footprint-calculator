#include <stdio.h>

float HouseholdEmission(int total_electricity_unites, int total_gas_unites){
    float Erate = 0.309;   //Co2 released (in kg) per kwh
    float Gtokwh = 11.2 ;  //cubic meter (of gas) to kwh
    float Grate = 0.203;   //Co2 released (in kg) per kwh

    return ((total_electricity_unites * Erate) + ((total_gas_unites*Gtokwh) * Grate));

}


float TransportEnergy(float vehicle_total, int flight){
    float Vrate = 10.9;   //Co2 released (in kg) per gallons
    float Frate = 250.0;   //Co2 released (in kg) per hours of flight

    return ((vehicle_total * Vrate) + (flight * Frate));

}


float Foodemission(float organic_food_percentage, float inorganic_food_percentage, float locally_produced_food){
    float avgConsumption = 75.0; //Food consumed in kg in a month
    float Orate = 1.0;   //Co2 released (in kg) for 1 kg of organic food
    float Irate = 0.8;   //Co2 released (in kg) for 1 kg of inorganic food
    float Lrate = 0.5;   //Co2 released (in kg) for 1 kg of locally produced food

    float OrganicConsumption = avgConsumption * organic_food_percentage / 100;
    float InorganicConsumption = avgConsumption * inorganic_food_percentage / 100;
    float LocalConsumption = avgConsumption * locally_produced_food / 100;

    return ((OrganicConsumption * Orate)+(InorganicConsumption * Irate)+(LocalConsumption * Lrate));

}



// int main(){

//     printf("\n%f", HouseholdEmission(5,1500));
//     printf("\n%f", TransportEnergy(5.527,46));
//     printf("\n%f", Foodemission(5.0527,46,6.37));

    
// }