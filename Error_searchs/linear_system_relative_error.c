#include "linear_system_relative_error.h"

double findRelativeError(Matrix *trueAns, Matrix *ans){

    size_t size = getMatrixRowNumber(trueAns);

    if(1 != getMatrixColumnNumber(trueAns)) return -1;
    if(size != getMatrixRowNumber(ans) || 1 != getMatrixColumnNumber(ans)) return -1;

    double errSq = 0;
    double normSq = 0;
    double rowErr;
    double ansElem;
    double trueAnsElem;
    for(size_t row = 0; row < size; row++){

        getMatrixElement(ans, row, 0, &ansElem);
        getMatrixElement(trueAns, row, 0, &trueAnsElem);

        normSq += trueAnsElem*trueAnsElem;
        
        rowErr = ansElem - trueAnsElem;

        errSq += rowErr*rowErr;

    }

    return sqrt(errSq)/sqrt(normSq);

}