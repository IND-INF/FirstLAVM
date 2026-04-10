#include "first_experiment.h"

int firstExperiment(){
    
    time_t seed = time(NULL);
    printf("The seed is %lld.\n", seed);

    clock_t solutionTime;
    size_t sizes[4] = {100, 200, 500, 1000};
    Matrix *mat, *copy, *low, *upp;

    for(short number = 0; number < 4; number++){

        printf("\nThe matrix size is %lld.\n\n", sizes[number]);

        if(!(createMatrix(&low, sizes[number], sizes[number]))){
            printf("Bad allocation\n");
            return 0;
        }

        if(!(createMatrix(&upp, sizes[number], sizes[number]))){
            freeMatrix(low);
            printf("Bad allocation\n");
            return 0;
        }

        if(!(createMatrix(&mat, sizes[number], sizes[number]+1))){
            freeMatrix(upp);
            freeMatrix(low);
            printf("Bad allocation\n");
            return 0;
        }
        generateMatrix(mat, seed);

        if(!(createMatrix(&copy, sizes[number], sizes[number]+1))){
            freeMatrix(mat);
            freeMatrix(upp);
            freeMatrix(low);
            printf("Bad allocation\n");
            return 0;
        }
        copyMatrix(mat, copy);

        solutionTime = clock();
        if(solveWithGaussianElimination(copy) == -2){
            printf("Matrix not able to do factorisation\n");
            return -1;
        }
        solutionTime = clock() - solutionTime;
        printf("The solution time with Gaussian elimination is %lf ms.\n",
                    ((double)solutionTime)*1000/CLOCKS_PER_SEC);
        
        copyMatrix(mat, copy);

        solutionTime = clock();
        if(solveWithPivotElementSelection(copy) == -2){
            printf("Singular matrix\n");
            return -1;
        }
        solutionTime = clock() - solutionTime;
        printf("The solution time with Gaussian elimination with the pivot element selection is %lf ms.\n",
                    ((double)solutionTime)*1000/CLOCKS_PER_SEC);

        copyMatrix(mat, copy);

        solutionTime = clock();
        if(findLowerUpperFactorisation(copy, low, upp) == -2){
            printf("Matrix not able to do factorisation\n");
            return -1;
        }
        solveWithLowerAndUpper(copy, low, upp);
        solutionTime = clock() - solutionTime;
        printf("The whole factorisation and solution time with lower-upper factorisation is %lf ms.\n",
                    ((double)solutionTime)*1000/CLOCKS_PER_SEC);

        copyMatrix(mat, copy);

        solutionTime = clock();
        if(findLowerUpperFactorisation(copy, low, upp) == -2){
            printf("Matrix not able to do factorisation\n");
            return -1;
        }
        solutionTime = clock() - solutionTime;
        printf("The lower-upper factorisation time is %lf ms.\n",
                    ((double)solutionTime)*1000/CLOCKS_PER_SEC);

        solutionTime = clock();
        solveWithLowerAndUpper(copy, low, upp);
        solutionTime = clock() - solutionTime;
        printf("The solution time with lower-upper factorisation is %lf ms.\n",
                    ((double)solutionTime)*1000/CLOCKS_PER_SEC);
    
        freeMatrix(copy); freeMatrix(mat); freeMatrix(upp); freeMatrix(low);

    }

    return 1;

}