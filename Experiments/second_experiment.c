#include "second_experiment.h"

int secondExperiment(){
    
    time_t seed = time(NULL);
    printf("The seed is %lld.\n", seed);
    
    clock_t solutionTime;
    size_t size = 500;
    int quantities[3] = {1, 10, 100};

    Matrix *mat, *low, *upp, *rPart;

    if(!(createMatrix(&rPart, size, 1))){
        printf("Bad allocation\n");
        return 0;
    }
    
    if(!(createMatrix(&low, size, size))){
        freeMatrix(rPart);
        printf("Bad allocation\n");
        return 0;
    }

    if(!(createMatrix(&upp, size, size))){
        freeMatrix(low);
        freeMatrix(rPart);
        printf("Bad allocation\n");
        return 0;
    }

    if(!(createMatrix(&mat, size, size+1))){
        freeMatrix(upp);
        freeMatrix(low);
        freeMatrix(rPart);
        printf("Bad allocation\n");
        return 0;
    }
    generateMatrix(mat, seed);

    for(short number = 0; number < 3; number++){

        printf("\nThe number of right parts is %d\n\n", quantities[number]);

        Matrix* matrices[quantities[number]];
        Matrix* copies[quantities[number]];
        for(int matNumber = 0; matNumber < quantities[number]; matNumber++){

            if(!(createMatrix(&(matrices[matNumber]), size, size+1))){
                for(matNumber--; matNumber >= 0; matNumber--){
                    freeMatrix(matrices[matNumber]);
                    freeMatrix(copies[matNumber]);
                }
                freeMatrix(mat);
                freeMatrix(upp);
                freeMatrix(low);
                freeMatrix(rPart);
                printf("Bad allocation\n");
                return 0;
            }
            copyMatrix(mat, matrices[matNumber]);

            generateMatrix(rPart, seed);
            copyMatrixLastColumn(rPart, matrices[matNumber]);

            if(!(createMatrix(&(copies[matNumber]), size, size+1))){
                freeMatrix(matrices[matNumber]);
                for(matNumber--; matNumber >= 0; matNumber--){
                    freeMatrix(matrices[matNumber]);
                    freeMatrix(copies[matNumber]);
                }
                freeMatrix(mat);
                freeMatrix(upp);
                freeMatrix(low);
                freeMatrix(rPart);
                printf("Bad allocation\n");
                return 0;
            }
            copyMatrix(matrices[matNumber], copies[matNumber]);

        }

        solutionTime = clock();
        for(int matNumber = 0; matNumber < quantities[number]; matNumber++){
            if(solveWithPivotElementSelection(matrices[matNumber]) == -2){
                printf("Singular matrix\n");
                return -1;
            }
        }
        solutionTime = clock() - solutionTime;
        printf("The solution time with Gaussian elimination with the pivot element selection is %lf ms.\n",
                    ((double)solutionTime)*1000/CLOCKS_PER_SEC);

        solutionTime = clock();
        if(findLowerUpperFactorisation(mat, low, upp) == -2){
            printf("Matrix not able to do factorisation\n");
            return -1;
        }
        for(int matNumber = 0; matNumber < quantities[number]; matNumber++){
            solveWithLowerAndUpper(copies[matNumber], low, upp);
        }
        solutionTime = clock() - solutionTime;
        printf("The solution time with lower-upper factorisation is %lf ms.\n",
                    ((double)solutionTime)*1000/CLOCKS_PER_SEC);

        for(int matNumber = 0; matNumber < quantities[number]; matNumber++){
            freeMatrix(matrices[matNumber]);
            freeMatrix(copies[matNumber]);
        }

    }
    freeMatrix(mat); freeMatrix(upp); freeMatrix(low); freeMatrix(rPart);

    return 1;

}