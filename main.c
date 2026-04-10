#include "Experiments/first_experiment.h"
#include "Experiments/second_experiment.h"
#include "Experiments/third_experiment.h"

int main(){

    int input;
    int exitFlag = 0;
    printf("Enter a number of an experiment (or any other key to exit)\n");

    while(scanf("%d", &input)){

        switch(input){
            case 1:
                firstExperiment();
                break;
            case 2:
                secondExperiment();
                break;
            case 3:
                thirdExperiment();
                break;
            default:
                exitFlag = 1;
        }

        if(exitFlag) break;

        printf("\nEnter a number of an experiment (or any other key to exit)\n");

    }

    return 0;

}