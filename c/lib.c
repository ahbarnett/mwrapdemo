/* minimal C library for cdemo. Barnett 7/30/15 */

#include <math.h>

void arraysin1d(int n, double* in, double* out)
/* Just computes sin of a list of doubles.
   Notes: * usual 0-indexing even though MATLAB was 1-indexed
          * names don't have to match those in demo.mw
*/
{
  int i;
  for (i=0;i<n;++i) out[i] = sin(in[i]);
}
