#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>
#include<math.h>
#include"CGLib/src/cglib.h"
#include"CGLib/src/cglib-other.h"

int SumArrayInt(int n, int arr[]);
int SumArrayFloat(int n, float arr[]);
int DataValidationInteger(char str[], int  variable);
int getRandomIndex(int start, int end);
int yes_no(char variable);
int CurrentWorkingDirectory(char cwd[]);
void EnergyInput(int energy_type[]);
void index1(const char **recommendations, const char **suggestion, float CarbonValue, double avg_emission, float transporation_value, float diet_value, float resource_value);
int compare(float *previous_total, float current_total) ;
void store(float Total);
float VehicleIO(float arr[][2], int number_of_vehicles);
float DataValidationFloat(char str[], float  variable);
float HouseholdEmission(int total_electricity_unites, int total_gas_unites);
float TransportEnergy(float vehicle_total, int flight);
float Foodemission(float organic_food_percentage, float inorganic_food_percentage, float locally_produced_food);
float HouseholdEmission(int total_electricity_unites, int total_gas_unites);
float TransportEnergy(float vehicle_total, int flight);
float Foodemission(float organic_food_percentage, float inorganic_food_percentage, float locally_produced_food);

int main(void) {
  
    srand(time(NULL));

// Variables to be used for Calculations:

    int total_electricity_units, total_gas_units, flights; 
    float vehicle_total, organic_food_percentage, inorganic_food_percentage, vegetarian_food_percentage, locally_produced_food;

// Calculate and print only if above values are not zero.

// Variables for Storing Data (Not to be used for Calcultions)

    int number_of_vehicles, flights_y_n;
    int electricity_units[12], gas_units[12];
    char directory[PATH_MAX];

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

// Transportation 

    printf("\nTRANSPORTATION:\n");

// Input for Vehicles

    printf("\nHow many Vehicles do you own?: ");
    number_of_vehicles = DataValidationInteger("Number of Vehicles", number_of_vehicles);
    
    float vehicles[number_of_vehicles][2]; 
    vehicle_total = VehicleIO(vehicles, number_of_vehicles);
    if (vehicle_total == 0)
        printf("Skipping Over Vehicle Calculation.");

// Input for FlightsW

    printf("\nDid You Take Any Flights In the Past 12 Months? (y/n): ");
    scanf("%c", &flights_y_n);

    if (yes_no(flights_y_n) == 1) {
        printf("\nEnter Hours of Flights Taken: ");
        flights = DataValidationInteger("Hours of Flights Taken", flights);
    }
    else {
        printf("Skipping Over Flight Calculation.");
        flights = 0;
    } 

// Input for Food

    puts("");
    printf("\nFOOD:\n");

    printf("\nHow much percent of your food is Organic on Monthly basis (approx.)?: ");
    organic_food_percentage = DataValidationFloat("Percentage of Organic Food Consumed", organic_food_percentage);
    printf("How much percent of your food is vegetarian on Monthly basis (approx.)?: ");
    inorganic_food_percentage = DataValidationFloat("Percentage of Veggies Consumed", inorganic_food_percentage);
    printf("How much percent of your food is prepared locally (approx.)?: ");
    locally_produced_food = DataValidationFloat("Percentage of Locally Produced Food", locally_produced_food);
    puts("");

// Avg carbon emission by a person yearly

    double avg_emission = 3991.6129; 
    float transporation_value = TransportEnergy(vehicle_total, flights), diet_value = Foodemission(organic_food_percentage, inorganic_food_percentage, locally_produced_food), resource_value = HouseholdEmission(total_electricity_units, total_gas_units);    
    float CarbonValue = transporation_value + diet_value + resource_value ;

    printf("SUMMARY:\n");

// value of carbon produced by transport

    printf("\nThe Carbon Emission From the Transporation sector: %0.2f KG\n",transporation_value);                 

// value of carbon produced by food

    printf("The contribution of Diet in Carbon Emission: %0.2f KG\n", diet_value);                              

// value of carbon produced by natural resource    

    printf("The amount of Carbon produced due to Consumption of Natural Resources: %0.2f KG\n",resource_value);

// Total amount of carbon produced 

    printf("The Total Value of Carbon Emitted: %0.2f KG\n",CarbonValue);                           

    index1(recommendations, suggestion, CarbonValue , avg_emission, transporation_value , diet_value, resource_value);

// Graph Data

    float result[3] = {resource_value, transporation_value, diet_value};
    char string_results[3][20] = {"Household Energy", "Transportation", "Food"};

    struct general_data* general = malloc(sizeof(struct general_data));
    general->stroke_width = 1;
    general->margin = 100;
    general->viewport_x = 640;
    general->viewport_y = 360;
    general->font_size = 12;
    general->d_file = 0;

    struct axel_data* axel = malloc(sizeof(struct axel_data));
    axel->axel_rgb[0] = 100;
    axel->axel_rgb[1] = 100;
    axel->axel_rgb[2] = 100;

    axel->axel_lines_rgb[0] = 220;
    axel->axel_lines_rgb[1] = 220;
    axel->axel_lines_rgb[2] = 220;

    axel->horizontal_lines = 1;
    axel->vertical_lines = 1;
    axel->numbered_x = 1;
    axel->numbered_y = 1;

    axel->x_axel_text_angle = -30.0;

    axel->axel_number_offset = 5.0;
    
    axel->n_measure_points = 5;

    axel->w[0] = -25;
    axel->w[1] = 25;
    axel->h[0] = -200;
    axel->h[1] = 200;

    struct theme_data* theme = malloc(sizeof(struct theme_data));
    theme->stop.r = 34;     
    theme->stop.g = 139;    
    theme->stop.b = 34;     

    theme->start.r = 139;   
    theme->start.g = 69;    
    theme->start.b = 19;    

    theme->theme_type = 0;
    
    theme->lightness_mod_percentage = 0.6;

    struct graph_data* gp = malloc(sizeof(struct graph_data));
    gp->general = general;
    gp->axel_data = axel;
    general->file_name = malloc(sizeof(char) * 30);

// Plotting Graph

    struct pie_data* pd = malloc(sizeof(struct pie_data));
    free(general->file_name);
    general->file_name = malloc(sizeof(char) * 30);
    strcpy(general->file_name, "./pie-chart/pie.svg\0");
    general->margin = 40.0;
    pd->general = general;
    pd->axel_data = axel;
    pd->theme = theme;
    pd->n_slices = 3;
    pd->slices = malloc(sizeof(struct pie_slice) * pd->n_slices);

    pd->d_h1_font_size = 50;
    pd->d_h2_font_size = 20;

    for(int i = 0; i < pd->n_slices; i++) {
        pd->slices[i].percentage = result[i] / CarbonValue;
        pd->slices[i].name = malloc(strlen(string_results[i])+1);
        strcpy(pd->slices[i].name, string_results[i]);
    }

    pie(pd);

    for(int i = 0; i < pd->n_slices; i++) 
        free(pd->slices[i].name);

    free(pd->slices);
    free(pd);
    free(general->file_name);
    free(general);
    free(axel);
    free(theme);

    printf("\nPress Enter to open Graph...\n");
    while (getch() != 13);

    CurrentWorkingDirectory(directory);
    char cmd[100] ="start chrome "; 
    strcat(cmd, directory);
    strcat(cmd, "/pie-chart/pie.svg\0");
    system(cmd);

  return 0;
}