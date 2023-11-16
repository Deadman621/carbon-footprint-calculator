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
void print(const char **recommendations, const char **suggestion);
void index1(const char **recommendations, const char **suggestion, float CarbonValue, double avg_emission, float transporation_value, float diet_value, float resource_value);
int getRandomIndex(int start, int end);
float HouseholdEmission(int total_electricity_unites, int total_gas_unites);
float TransportEnergy(float vehicle_total, int flight);
float Foodemission(float organic_food_percentage, float inorganic_food_percentage, float locally_produced_food);

int main(void) {
  
    srand(time(NULL));

    const char *recommendations[] = {
         "Kudos! Your carbon footprint is impressively below average. Your commitment to sustainability is truly making a difference. Keep up the excellent work!",
 		 "Fantastic job! Your carbon emissions are shining examples of responsible living. Your choices are not just commendable; they're inspirational. Keep paving the way for a greener world!",
		 "Bravo! Your carbon footprint is shining brightly below the average. Your eco-conscious decisions are like green beacons lighting the way. Keep up the stellar work!",
		 "Well done! Your carbon emissions are impressively low, showcasing a dedication to a sustainable lifestyle. Your choices aren't just reducing your footprint; they're creating ripples of positive change.",
		 "Congratulations! Your carbon footprint is below average. Your conscious choices are making a positive impact. Keep it up!",
		 
		 "Being conscious of your carbon emissions is a vital step towards a sustainable lifestyle. Your efforts are commendable. To amplify your impact, pinpoint areas where small changes can lead to a greener living.",
		 "Awareness is the first step, and you're there! Your commitment to understanding your carbon footprint is praiseworthy. Consider incorporating specific changes in your routine to enhance your eco-friendly journey.",
		 "Being aware of your carbon emissions is a crucial step towards a sustainable lifestyle. Your dedication is praiseworthy. To amplify your impact, identify specific changes in your routine that can lead to a greener living.",
   		 "Congratulations on understanding your carbon footprint! Your commitment to awareness is commendable. Consider incorporating targeted changes in your routine to enhance your eco-friendly journey.",
		 "You're aware of your carbon emissions, and that's a positive step. To make an even greater impact, look into specific areas where small changes can lead to a greener lifestyle.",
		 
		 
		 "Your carbon footprint is higher than the average, raising some environmental concerns. Let's work together to tackle this. Small changes can lead to a significant reduction. Are you ready to make a positive change?",
		 "It looks like there's room for improvement in lowering your carbon emissions. No worries, though! Making sustainable choices can be a rewarding journey. Ready to explore some impactful changes in your lifestyle?",
		 "Your carbon footprint is higher than the average, raising environmental concerns. Let's work together to address this. Small changes can result in a significant reduction. Are you ready to make a positive change?",
		 "There's room for improvement in lowering your carbon emissions. No worries, though! Making sustainable choices can be a rewarding journey. Ready to explore impactful changes in your lifestyle?",
		 "Your carbon footprint is higher than the average. Let's work together to reduce it. Small changes can make a big difference."

    };

    const char *suggestion[] = {
                    "Explore alternative transportation options like carpooling, biking, or using public transit to reduce your carbon footprint.",
                    "If feasible, consider switching to an electric vehicle (EV) or a hybrid. EVs produce fewer emissions compared to traditional gasoline-powered vehicles and can be a cleaner transportation option.",
                    "Adopt fuel-efficient driving habits, such as maintaining a steady speed, avoiding rapid acceleration and braking, and keeping your vehicle well-maintained. Regular maintenance, such as proper tire inflation, can improve fuel efficiency.",

                    "Consider adopting a more plant-based diet. Reducing meat consumption can significantly lower your environmental impact.",
                    "Explore meat alternatives such as veggie burgers, plant-based sausages, and meat substitutes made from ingredients like soy, mushrooms, or legumes. These options can provide the taste and texture of meat with a smaller environmental footprint.",
                    "Select locally grown fruits and vegetables to support local farmers and reduce the carbon footprint associated with transportation. Local, seasonal produce often requires less energy to produce and transport.",

                    "Practice energy-saving habits: turn off lights, unplug devices, and use energy-efficient appliances.",
                    "Look into renewable energy sources for your home. Switching to clean energy can contribute to a sustainable future.",
                    "Get involved in local environmental initiatives or volunteer for green projects. Your actions can have a positive impact on the community."

    };

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
    number_of_vehicles = DataValidatioyyynInteger("Number of Vehicles", number_of_vehicles);
    
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

     
    print(recommendations,suggestion);
  
  return 0;
}
