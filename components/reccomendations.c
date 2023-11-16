#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// function to generate random indexes
int getRandomIndex(int start, int end) {
    return (rand() % (end - start + 1) + start);
}

/*function that takes arguments and after evaluating prints the suitable statement accordingly*/
void index1(const char **recommendations,const char **suggestion, float CarbonValue, double avg_emission,float transporation_value,float diet_value,float resource_value) {
    int R_index,S_index=-1;
    double thresholdless=avg_emission-300,thresholdabove=avg_emission+300;//define range so that it become applicable in real world

    if (CarbonValue < thresholdless) {                  //if carbon value is less than Avg Value
        R_index  = getRandomIndex(0, 4);
    } else if (CarbonValue > thresholdabove) {          //if carbon value is greater than Avg Value

        // printf("Transportation: %.2f, Diet: %.2f, Resource: %.2f\n", transporation_value, diet_value, resource_value);
        R_index = getRandomIndex(10, 14);
        if(transporation_value > diet_value && transporation_value > resource_value){           //if transportation sector produce the most carbon Emission       
           S_index = getRandomIndex(0,2);
        }else if(diet_value > transporation_value && diet_value > resource_value){              //if diet  produce the most carbon Emission
           S_index = getRandomIndex(3,5);
        }else if(resource_value > transporation_value && resource_value > diet_value){          //if resource consumption produce the most carbon Emission
           S_index = getRandomIndex(6,8);               
        }

    } else {
        R_index = getRandomIndex(5, 9);
    }

    printf("\nREMARKS:\n");
    printf("\n%s\n", recommendations[R_index]);

    if (S_index != -1) {
                printf("\nSUGGESTION:\n");
                printf("\n%s\n", suggestion[S_index]);
    }

    return ;
}