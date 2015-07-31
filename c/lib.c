/* minimal C library for MWarp demo. Barnett 7/30/15 */

#include <math.h>
#include <complex.h>
#include <stdio.h>

void myfunc(int n, double* in, double* out, double complex *z, int flag)
/* Just computes sin of a list of doubles, and squares a complex number,
   and prints the value of flag.
   Notes: * usual 0-indexing even though MATLAB was 1-indexed
          * names don't have to match those in demo.mw
*/
{
  int i;
  for (i=0;i<n;++i)
    out[i] = sin(in[i]);
  z[0] = z[0]*z[0];
  if (flag)
    printf("flag = %d\n",flag);
}
