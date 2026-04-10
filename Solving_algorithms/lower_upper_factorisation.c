#include "lower_upper_factorisation.h"

int findLowerUpperFactorisation(const Matrix *mat, Matrix *low, Matrix *upp){

    size_t size = getMatrixRowNumber(mat);

    if(size+1 != getMatrixColumnNumber(mat)) return -1;
    if(size != getMatrixRowNumber(low) || size != getMatrixColumnNumber(low)) return -1;
    if(size != getMatrixRowNumber(upp) || size != getMatrixColumnNumber(upp)) return -1;

    copyMatrix(mat, upp);

    double elem, firstElem;
    for(size_t column = 0, row; column < size; column++){

        getMatrixElement(upp, column, column, &firstElem);
        if(firstElem == 0) return -2;

        for(row = 0; row < column; row++){
            setMatrixElement(low, row, column, 0);
        }
        
        for(row = column + 1; row < size; row++){

            getMatrixElement(upp, row, column, &elem);

            rowAddition(upp, row, column, -elem/firstElem);
            setMatrixElement(upp, row, column, 0);

            setMatrixElement(low, row, column, elem/firstElem);

        }
        setMatrixElement(low, column, column, 1);

    }

    return 1;

}