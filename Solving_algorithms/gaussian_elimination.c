#include "gaussian_elimination.h"

int solveWithGaussianElimination(Matrix *mat){

    size_t size = getMatrixRowNumber(mat);

    if(size+1 != getMatrixColumnNumber(mat)) return -1;

    double elem, firstElem;
    for(size_t column = 0, row; column < size; column++){

        getMatrixElement(mat, column, column, &firstElem);
        if(firstElem == 0) return -2;

        for(row = column + 1; row < size; row++){

            getMatrixElement(mat, row, column, &elem);

            rowAddition(mat, row, column, -elem/firstElem);
            setMatrixElement(mat, row, column, 0);

        }

        rowDivision(mat, column, firstElem);
        setMatrixElement(mat, column, column, 1);

    }

    for(size_t column = size - 1, row; column > 0; column--){
        for(row = column; row > 0; row--){
            getMatrixElement(mat, row-1, column, &elem);
            rowAddition(mat, row-1, column, -elem);
            setMatrixElement(mat, row-1, column, 0);
        }
    }

    return 1;

}