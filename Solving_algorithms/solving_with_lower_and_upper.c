#include "solving_with_lower_and_upper.h"

int solveWithLowerAndUpper(Matrix *mat, Matrix *low, Matrix *upp){

    size_t size = getMatrixRowNumber(mat);

    if(size+1 != getMatrixColumnNumber(mat)) return -1;
    if(size != getMatrixRowNumber(low) || size != getMatrixColumnNumber(low)) return -1;
    if(size != getMatrixRowNumber(upp) || size != getMatrixColumnNumber(upp)) return -1;

    copyMatrix(low, mat);

    double elem;
    for(size_t column = 0, row; column < size; column++){
        for(row = column+1; row < size; row++){
            getMatrixElement(mat, row, column, &elem);
            rowAddition(mat, row, column, -elem);
        }
    }

    copyMatrix(upp, mat);

    for(size_t row = size - 1; row > 0; row--){
        getMatrixElement(mat, row-1, row, &elem);
        rowAddition(mat, row-1, row, -elem);
    }

    return 1;

}