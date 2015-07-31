C     minimal Fortran library for MWrap demo. Barnett 7/31/15

      subroutine myfunc(n, in, out, z, flag)
C     Just computes sin of a list of doubles, and squares a complex number,
C     and prints the value of flag.
C     Notes: * 1-indexing as with MATLAB
C            * names don't have to match those in demo.mw
*/
      implicit none
      integer n,flag,i
      real*8 in(1:n),out(*)
      complex*16 z(*)

      do i=1,n
         out(i) = sin(in(i))
      enddo
      z(1) = z(1)*z(1)
      if (flag.ne.0) then
         write(5,*) 'flag = ',flag
      endif
      end
