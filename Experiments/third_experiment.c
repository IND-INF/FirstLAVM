#include "third_experiment.h"

int thirdExperiment(){
    
    size_t sizes[3] = {5, 10, 15};
    Matrix *mat, *copy, *low, *upp, *trueAns, *ans;

    for(short number = 0; number < 3; number++){

        printf("\nThe matrix size is %lld.\n", sizes[number]);

        if(!(createMatrix(&trueAns, sizes[number], 1))){
            printf("Bad allocation\n");
            return 0;
        }
        for(size_t ansNumber = 0; ansNumber < sizes[number]; ansNumber++){
            setMatrixElement(trueAns, ansNumber, 0, 1);
        }

        if(!(createMatrix(&ans, sizes[number], 1))){
            freeMatrix(trueAns);
            printf("Bad allocation\n");
            return 0;
        }

        if(!(createMatrix(&low, sizes[number], sizes[number]))){
            freeMatrix(ans);
            freeMatrix(trueAns);
            printf("Bad allocation\n");
            return 0;
        }

        if(!(createMatrix(&upp, sizes[number], sizes[number]))){
            freeMatrix(low);
            freeMatrix(ans);
            freeMatrix(trueAns);
            printf("Bad allocation\n");
            return 0;
        }

        if(!(createMatrix(&mat, sizes[number], sizes[number]+1))){
            freeMatrix(upp);
            freeMatrix(low);
            freeMatrix(ans);
            freeMatrix(trueAns);
            printf("Bad allocation\n");
            return 0;
        }
        makeHilbertMatrix(mat);

        if(!(createMatrix(&copy, sizes[number], sizes[number]+1))){
            freeMatrix(mat);
            freeMatrix(upp);
            freeMatrix(low);
            freeMatrix(ans);
            freeMatrix(trueAns);
            printf("Bad allocation\n");
            return 0;
        }

        copyMatrix(mat, copy);

        printf("\nGaussian elimination\n");
        solveWithGaussianElimination(copy);
        copyMatrixLastColumn(copy, ans);
        printf("The relative error is %.5e\n", findRelativeError(trueAns, ans));
        printf("The residual is %.5e\n", findResidual(mat, ans));

        copyMatrix(mat, copy);

        printf("\nGaussian elimination with the pivot element selection\n");
        solveWithPivotElementSelection(copy);
        copyMatrixLastColumn(copy, ans);
        printf("The relative error is %.5e\n", findRelativeError(trueAns, ans));
        printf("The residual is %.5e\n", findResidual(mat, ans));

        copyMatrix(mat, copy);

        printf("\nSolving with lower-upper factorisation\n");
        findLowerUpperFactorisation(copy, low, upp);
        solveWithLowerAndUpper(copy, low, upp);
        copyMatrixLastColumn(copy, ans);
        printf("The relative error is %.5e\n", findRelativeError(trueAns, ans));
        printf("The residual is %.5e\n", findResidual(mat, ans));

        freeMatrix(copy);
        freeMatrix(mat);
        freeMatrix(upp);
        freeMatrix(low);
        freeMatrix(ans);
        freeMatrix(trueAns);
        
    }

    return 1;

}