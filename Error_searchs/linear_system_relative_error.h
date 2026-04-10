#ifndef _LINEAR_SYSTEM_RELATIVE_ERROR_H_
#define _LINEAR_SYSTEM_RELATIVE_ERROR_H_

#include "../matrix.h"
#include <math.h>
#include <stdio.h>

double findRelativeError(Matrix *trueAns, Matrix *ans);

#endif //_LINEAR_SYSTEM_RELATIVE_ERROR_H_