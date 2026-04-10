#include "matrix_generation.h"

void generateMatrix(Matrix *mat, time_t seed){

    srand(seed);

    size_t rowNumber = getMatrixRowNumber(mat);
    size_t columnNumber = getMatrixColumnNumber(mat);
    double newElem;
    int singDefinition;

    for(size_t row = 0, column; row < rowNumber; row++){
        for(column = 0; column < columnNumber; column++){

            newElem = ((double)rand())/RAND_MAX;

            singDefinition = rand();
            if(singDefinition%2){
                newElem *= -1;
            }

            setMatrixElement(mat, row, column, newElem);

        }
    }

}