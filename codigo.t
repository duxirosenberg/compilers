function f
  params
    _result boolean
    a integer
    f float
  endparams

  vars
    x integer
    b boolean
    z integer 10
  endvars

     %1 = 5
     readi %2
     z[%1] = %2
     %3 = 5
     %4 = z[%3]
     %5 = 88
     %7 = float %5
     %6 = %7 *. f
     %9 = float %4
     %8 = %9 -. %6
     writef %8
     readi b
     readf f
     ifFalse b goto endif1
     writes "h\n\tl\\a"
     %10 = -. f
     %11 = -. %10
     %12 = -. %11
     writef %12
     writes "\n"
  label endif1 :
     %13 = 1
     _result = %13
     return
endfunction

function fz
  params
    _result float
    r integer
    u float
  endparams

  label while1 :
     %1 = 0.01
     %3 = float r
     %2 = %3 <=. %1
     %2 = not %2
     ifFalse %2 goto endwhile1
     %4 = 1
     %5 = r - %4
     r = %5
     goto while1
  label endwhile1 :
     %6 = 0
     %7 = r == %6
     ifFalse %7 goto endif1
     %8 = 55555
     %9 = 5
     %10 = - %9
     %11 = 4
     %12 = %10 / %11
     %13 = float %12
     pushparam 
     pushparam %8
     pushparam %13
     call f
     popparam 
     popparam 
     popparam 
  label endif1 :
     %14 = 3
     %15 = r + %14
     %17 = float %15
     %16 = %17 *. u
     _result = %16
     return
endfunction

function main
  vars
    a integer
    q float
  endvars

   %1 = 1
   %2 = - %1
   %3 = float %2
   q = %3
   %4 = 2
   %5 = 2
   %6 = 3
   %8 = float %6
   %7 = q +. %8
   pushparam 
   pushparam %5
   pushparam %7
   call fz
   popparam 
   popparam 
   popparam %9
   pushparam 
   pushparam %4
   pushparam %9
   call fz
   popparam 
   popparam 
   popparam %10
   q = %10
   %11 = 3.7
   %12 = q +. %11
   %13 = 4
   %15 = float %13
   %14 = %12 +. %15
   writef %14
   writes "\n"
   return
endfunction


