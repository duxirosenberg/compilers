function f1
  params
    a integer
    b integer
  endparams

  vars
    c float
    d integer
    found boolean
  endvars

     %1 = 0
     found = %1
     %2 = 0.7
     %4 = float a
     %3 = %4 +. %2
     c = %3
     %5 = 0
     d = %5
     %6 = a + d
     %7 = %6 <= c
     %7 = not %7
     %8 = not found
     %9 = %7 or %8
     ifFalse %9 goto endif1
  label while1 :
     %10 = 0
     %11 = b <= %10
     %11 = not %11
     ifFalse %11 goto endwhile1
     %12 = 1
     %13 = b - %12
     b = %13
     %14 = 1
     found = %14
     goto while1
  label endwhile1 :
  label endif1 :
     %15 = 11
     %16 = b <= %15
     ifFalse %16 goto endif2
     %17 = 2
     %19 = float %17
     %18 = %19 *. c
     %20 = 1
     %22 = float %20
     %21 = %18 +. %22
     c = %21
  label endif2 :
     writef c
     writes "\n"
     return
endfunction

function main
  vars
    a integer
    b integer
  endvars

   %1 = 4
   a = %1
   %2 = 2
   %3 = %2 * a
   %4 = 1
   %5 = %3 + %4
   b = %5
   %6 = 3
   %7 = %6 + b
   pushparam 
   call f1
   popparam 
   return
endfunction


