//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
// File: averagingFilterCG.cpp
//
// MATLAB Coder version            : 24.2
// C/C++ source code generated on  : 20-Jul-2024 12:20:55
//

// Include Files
#include "averagingFilterCG.h"
#include "coder_array.h"
#include <algorithm>
#include <cstring>

// Function Definitions
//
// Arguments    : const coder::array<double, 2U> &x
//                coder::array<double, 2U> &y
// Return Type  : void
//
void averagingFilterCG(const coder::array<double, 2U> &x,
                       coder::array<double, 2U> &y)
{
  double slider[16];
  double b_slider[15];
  int i;
  int loop_ub;
  std::memset(&slider[0], 0, 16U * sizeof(double));
  y.set_size(1, x.size(1));
  loop_ub = x.size(1);
  for (i = 0; i < loop_ub; i++) {
    y[i] = 0.0;
  }
  i = x.size(1);
  for (loop_ub = 0; loop_ub < i; loop_ub++) {
    double b_y;
    std::copy(&slider[0], &slider[15], &b_slider[0]);
    //  move one position in the buffer
    b_y = x[loop_ub];
    slider[0] = b_y;
    //  Add a new sample value to the buffer
    for (int k{0}; k < 15; k++) {
      double d;
      d = b_slider[k];
      slider[k + 1] = d;
      b_y += d;
    }
    y[loop_ub] = b_y / 16.0;
    //  write the average of the current window to y
  }
}

//
// File trailer for averagingFilterCG.cpp
//
// [EOF]
//