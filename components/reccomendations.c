#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int compare(float *previous_total, float current_total) ;
void store(float Total);

// function to generate random indexes
int getRandomIndex(int start, int end) {

    return (rand() % (end - start + 1) + start);

}

//function that prints the suitable statement accordingly
void index1(const char **recommendations,const char **suggestion, float CarbonValue, double avg_emission,float transporation_value,float diet_value,float resource_value) {
  
    int R_index,S_index=-1;
    float previous_value= 0.0;

    double  thresholdless=avg_emission-300,
            thresholdabove=avg_emission+300;        //defined range so that it become applicable in real world

    if (CarbonValue < thresholdless) {  
        
        //if carbon value is less than Avg Value
       
         R_index  = getRandomIndex(0, 4);

    } else if (CarbonValue > thresholdabove) {        
        
        //if carbon value is greater than Avg Value

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

    compare(&previous_value,CarbonValue);
    store(CarbonValue);
    

    
    return ;
}

void store(float Total){                        //SAAD FUNCTION
    


    FILE *fptr = fopen("Data Base File.txt","a+");
    int count = 1;

    if (fptr == NULL) {
        fptr = fopen("Data Base File.txt","w+");
    }


    fprintf(fptr,"%f\n",Total);
    

    fclose(fptr);
}



 int compare(float *previous_total, float current_total) {

    printf("\n\nCOMPARISION FROM THE PREVIOUS FOOTPRINT :\n\n");

    FILE *fptr = fopen("Data Base File.txt", "r");

    if (fptr == NULL) {
        printf("Error:\nThe FILE is not Available.\n");
        return -1;                                               // Returning -1 if file does not exist
    }

    int count = 0;
    float temp;

                                                                
    while (fscanf(fptr, "%f", &temp) == 1) {                    // Read all values in the file till the last value and store it 
        *previous_total = temp;
        count++;
    }

    fclose(fptr);



    if (count == 0) {
        printf("\nThe FILE is EMPTY.\nNo DATA Found...\n");
        return -1;                                               // Returning -1 if file is empty
    }

    // Compare the previous value with the current one
    if (*previous_total > current_total) {

        printf("Congratulations! You have improved from the previous total which is %f KG.\n",*previous_total);

    } else if (*previous_total < current_total) {

        printf("There's room for improvement.!\nYour carbon emissions have increased. You should work to make more eco-friendly choices and stick to your previous routine!\n");


    } else {

        printf("Your current total is the same as the previous one.\n");

    }

    return 0;
}
