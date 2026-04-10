#include "matrix.h"

typedef struct _struct_Matrix{
    double *values;
    size_t rowNumber;
    size_t columnNumber;
} Matrix;

int createMatrix(Matrix **mat, size_t rowNumber, size_t columnNumber){

    if(!(*mat = malloc(sizeof(Matrix)))) return 0;

    if(!rowNumber || !columnNumber){

        (*mat)->rowNumber = 0;
        (*mat)->columnNumber = 0;

        (*mat)->values = NULL;

        return 1;
        
    }

    (*mat)->rowNumber = rowNumber;
    (*mat)->columnNumber = columnNumber;

    if(!((*mat)->values = malloc(rowNumber*columnNumber*sizeof(double)))) return 0;

    return 1;

}
void copyMatrix(const Matrix *source, Matrix *mat){
    for(size_t row = 0, column; row < source->rowNumber && row < mat->rowNumber; row++){
        for(column = 0; column < source->columnNumber && column < mat->columnNumber; column++){
            mat->values[row*(mat->columnNumber) + column] = source->values[row*(source->columnNumber) + column];
        }
    }
}
void copyMatrixLastColumn(const Matrix *source, Matrix *mat){

    size_t sourceColumn = source->columnNumber - 1;
    size_t matColumn = mat->columnNumber - 1;

    for(size_t row = 0; row < source->rowNumber && row < mat->rowNumber; row++){
        mat->values[row*(mat->columnNumber) + matColumn] =
                    source->values[row*(source->columnNumber) + sourceColumn];
    }

}
void freeMatrix(Matrix *mat){
    free(mat->values);
    free(mat);
}

size_t getMatrixRowNumber(const Matrix *mat){
    return mat->rowNumber;
}
size_t getMatrixColumnNumber(const Matrix *mat){
    return mat->columnNumber;
}

int setMatrixElement(Matrix *mat, size_t row, size_t column, double element){

    if(row >= mat->rowNumber || column >= mat->columnNumber) return 0;

    mat->values[row*(mat->columnNumber) + column] = element;

    return 1;

}
int getMatrixElement(const Matrix *mat, size_t row, size_t column, double *element){
    
    if(row >= mat->rowNumber || column >= mat->columnNumber) return 0;

    *element = mat->values[row*(mat->columnNumber) + column];
    
    return 1;

}

int rowSwitching(Matrix *mat, size_t row1, size_t row2){

    if(row1 >= mat->rowNumber || row2 >= mat->rowNumber) return 0;

    double subservient;
    for(size_t column = 0; column < mat->columnNumber; column++){
        subservient = mat->values[row1*(mat->columnNumber) + column];
        mat->values[row1*(mat->columnNumber) + column] = mat->values[row2*(mat->columnNumber) + column];
        mat->values[row2*(mat->columnNumber) + column] = subservient;
    }

    return 1;

}
int rowMultiplication(Matrix *mat, size_t row, double multiplier){

    if(row >= mat->rowNumber) return 0;

    for(size_t column = 0; column < mat->columnNumber; column++){
        mat->values[row*(mat->columnNumber) + column] *= multiplier;
    }

    return 1;

}
int rowDivision(Matrix *mat, size_t row, double divisor){

    if(row >= mat->rowNumber) return 0;
    if(divisor == 0) return -1;

    for(size_t column = 0; column < mat->columnNumber; column++){
        mat->values[row*(mat->columnNumber) + column] /= divisor;
    }

    return 1;

}
int rowAddition(Matrix *mat, size_t row1, size_t row2, double multiplier){

    if(row1 >= mat->rowNumber || row2 >= mat->rowNumber) return 0;

    for(size_t column = 0; column < mat->columnNumber; column++){
        mat->values[row1*(mat->columnNumber) + column] +=
                    mat->values[row2*(mat->columnNumber) + column]*multiplier;
    }

    return 1;

}