/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 * File: averagingFilterCG.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 20-Jul-2024 12:20:51
 */

/* Include Files */
#include "averagingFilterCG.h"
#include "averagingFilterCG_emxutil.h"
#include "averagingFilterCG_types.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const emxArray_real_T *x
 *                emxArray_real_T *y
 * Return Type  : void
 */
void averagingFilterCG(const emxArray_real_T *x, emxArray_real_T *y)
{
  double slider[16];
  double b_slider[15];
  const double *x_data;
  double *y_data;
  int i;
  int k;
  int loop_ub;
  x_data = x->data;
  memset(&slider[0], 0, 16U * sizeof(double));
  i = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = x->size[1];
  emxEnsureCapacity_real_T(y, i);
  y_data = y->data;
  loop_ub = x->size[1];
  for (i = 0; i < loop_ub; i++) {
    y_data[i] = 0.0;
  }
  i = x->size[1];
  for (loop_ub = 0; loop_ub < i; loop_ub++) {
    double b_y;
    memcpy(&b_slider[0], &slider[0], 15U * sizeof(double));
    /*  move one position in the buffer */
    b_y = x_data[loop_ub];
    slider[0] = b_y;
    /*  Add a new sample value to the buffer */
    for (k = 0; k < 15; k++) {
      double d;
      d = b_slider[k];
      slider[k + 1] = d;
      b_y += d;
    }
    y_data[loop_ub] = b_y / 16.0;
    /*  write the average of the current window to y */
  }
}

/*
 * File trailer for averagingFilterCG.c
 *
 * [EOF]
 */