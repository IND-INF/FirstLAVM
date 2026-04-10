#include "pivot_element_selection.h"

int solveWithPivotElementSelection(Matrix *mat){

    size_t size = getMatrixRowNumber(mat);
    
    if(size+1 != getMatrixColumnNumber(mat)) return -1;

    double elem, firstElem, maxElem;
    for(size_t column = 0, row, maxRow; column < size; column++){

        getMatrixElement(mat, column, column, &maxElem);
        if(maxElem < 0) maxElem *= -1;
        maxRow = column;

        for(row = column + 1; row < size; row++){

            getMatrixElement(mat, row, column, &elem);

            if(elem < 0) elem *= -1;
            if(elem > maxElem){
                maxElem = elem;
                maxRow = row;
            }

        }

        if(maxRow != column){
            rowSwitching(mat, column, maxRow);
        }

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