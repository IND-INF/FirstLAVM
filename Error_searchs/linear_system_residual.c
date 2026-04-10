#include "linear_system_residual.h"

double findResidual(Matrix *mat, Matrix *ans){
    
    size_t size = getMatrixRowNumber(mat);

    if(size+1 != getMatrixColumnNumber(mat)) return -1;
    if(size != getMatrixRowNumber(ans) || 1 != getMatrixColumnNumber(ans)) return -1;

    double residualSq = 0;
    double rowResidual;
    double ansElem;
    double coefficient;
    for(size_t row = 0, column; row < size; row++){

        rowResidual = 0;

        for(column = 0; column < size; column++){
            getMatrixElement(mat, row, column, &coefficient);
            getMatrixElement(ans, column, 0, &ansElem);
            rowResidual += coefficient*ansElem;
        }
        getMatrixElement(mat, row, size, &coefficient);
        rowResidual -= coefficient;
        
        residualSq += rowResidual*rowResidual;
        
    }

    return sqrt(residualSq);

}