/* minimal C library showing openmp and overwriting arrays. Barnett 7/30/15 */

#include <math.h>
#include <omp.h>
#include <stdio.h>

void array2d(int n, double* a, int reps)
/* Computes iterated sin of a list of doubles, overwriting.
   Similar as code as ../c/lib.c
*/
{
  int i,r;
  for (i=0;i<n;++i)
    for (r=0;r<reps;++r)
      a[i] = sin(a[i]);
}

void array2domp(int n, double* a, int reps)
/* Computes iterated sin of a list of doubles, overwriting, using OpenMP.
*/
{
  int i,r;
#pragma omp parallel
  {
    if (omp_get_thread_num()==0) printf("%d threads\n", omp_get_num_threads());
#pragma omp for private(i,r) schedule(static)
    for (i=0;i<n;++i)
      for (r=0;r<reps;++r)
	a[i] = sin(a[i]);
  }
}
