#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include"CGLib/src/cglib.h"
#include"CGLib/src/cglib-other.h"


int getRandomIndex(int start, int end);


void index1(const char **recommendations,const char **suggestion, double CarbonValue, double avg_emission,float transporation_value,float diet_value,float resource_value);


int main(void) {
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

    srand(time(NULL));

    double avg_emission=3991.6129 ;
    float transporation_value = 1200.12, diet_value = 4221.24, resource_value = 2321.2548;
    double CarbonValue = transporation_value + diet_value + resource_value ;


    index1(recommendations, suggestion, CarbonValue , avg_emission, transporation_value , diet_value, resource_value);

    return 0;
}

// function to generate random indexes
int getRandomIndex(int start, int end) {
    return (rand() % (end - start + 1) + start);
}

/*function that takes arguments and after evaluating prints the suitable statement accordingly*/
void index1(const char **recommendations,const char **suggestion, double CarbonValue, double avg_emission,float transporation_value,float diet_value,float resource_value) {
    int R_index,S_index=-1;
    double thresholdless=avg_emission-300,thresholdabove=avg_emission+300;//define range so that it become applicable in real world

    if (CarbonValue < thresholdless) {
        R_index  = getRandomIndex(0, 4);
    } else if (CarbonValue > thresholdabove) {

        // printf("Transportation: %.2f, Diet: %.2f, Resource: %.2f\n", transporation_value, diet_value, resource_value);
        R_index = getRandomIndex(10, 14);
        if(transporation_value > diet_value && transporation_value > resource_value){
           S_index = getRandomIndex(0,2);
        }else if(diet_value > transporation_value && diet_value > resource_value){
           S_index = getRandomIndex(3,5);
        }else if(resource_value > transporation_value && resource_value > diet_value){
           S_index = getRandomIndex(6,8);
        }

    } else {
        R_index = getRandomIndex(5, 9);
    }

    printf("\n\n%s\n", recommendations[R_index]);

    if (S_index != -1) {
                 printf("\n\n%s\n", suggestion[S_index]);
    }

    return ;
}





