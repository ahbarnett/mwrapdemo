C     minimal Fortran library showing openmp and overwriting arrays.
C     Barnett 7/31/15. Removed mexPrintf since write now works. 8/26/22

      subroutine array2d(n, a, reps)
C     Computes iterated sin of a list of doubles, overwriting.
C     Similar as code as ../c/lib.c
      implicit none
      integer n,reps,i,r
      real*8 a(*)

      do i=1,n
         do r=1,reps
            a(i) = sin(a(i))
         enddo
      enddo
      end

      subroutine array2domp(n, a, reps)
C     Computes iterated sin of a list of doubles, overwriting, using OpenMP
      implicit none
      integer n,reps,i,r
      real*8 a(*)
c     needed for omp
      integer OMP_GET_THREAD_NUM, omp_get_num_threads

C$OMP PARALLEL
      if (omp_get_thread_num().eq.0) then
         write(*,*) omp_get_num_threads(), ' threads',achar(10)
      endif
C$OMP DO private(i,r) schedule(static)
      do i=1,n
         do r=1,reps
            a(i) = sin(a(i))
         enddo
      enddo
C$OMP END DO
C$OMP END PARALLEL
      end
