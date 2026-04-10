#include "hilbert_matrix.h"

int makeHilbertMatrix(Matrix *mat){
    
    size_t size = getMatrixRowNumber(mat);

    if(size+1 != getMatrixColumnNumber(mat)) return -1;

    double constTerm;
    for(size_t row = 0, column; row < size; row++){

        constTerm = 0;

        for(column = 0; column < size; column++){
            setMatrixElement(mat, row, column, 1/((double)(row+column+1)));
            constTerm += 1/((double)(row+column+1));
        }

        setMatrixElement(mat, row, column, constTerm);

    }

    return 1;
    
}