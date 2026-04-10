#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <stdlib.h>

typedef struct _struct_Matrix Matrix;

int createMatrix(Matrix **mat, size_t rowNumber, size_t columnNumber);
void copyMatrix(const Matrix *source, Matrix *mat);
void copyMatrixLastColumn(const Matrix *source, Matrix *mat);
void freeMatrix(Matrix *mat);

size_t getMatrixRowNumber(const Matrix *mat);
size_t getMatrixColumnNumber(const Matrix *mat);

int setMatrixElement(Matrix *mat, size_t row, size_t column, double element);
int getMatrixElement(const Matrix *mat, size_t row, size_t column, double *element);

int rowSwitching(Matrix *mat, size_t row1, size_t row2);
int rowMultiplication(Matrix *mat, size_t row, double multiplier);
int rowDivision(Matrix *mat, size_t row, double divisor);
int rowAddition(Matrix *mat, size_t row1, size_t row2, double multiplier);

#endif //_MATRIX_H_