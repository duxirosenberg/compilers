function f
  params
    _result boolean
    a integer
    b float
  endparams

  vars
    x integer
    y boolean
    z integer 10
  endvars

     %1 = 9
     %2 = 67
     %3 = a + %2
     z[%1] = %3
     %4 = 34
     x = %4
     %5 = 3
     %6 = 56
     %7 = 9
     %8 = z[%7]
     %9 = %6 + %8
     z[%5] = %9
     %10 = 3
     %11 = z[%10]
     %13 = float %11
     %12 = %13 <=. b
     %12 = not %12
     ifFalse %12 goto else1
     %14 = 78
     x = %14
     writef b
     writes "\n"
     goto endif1
  label else1 :
     %15 = 99
     x = %15
  label endif1 :
     %16 = 3
     %17 = z[%16]
     writei %17
     writes "\n"
     %18 = 1
     _result = %18
     return
endfunction

function fz
  params
    r integer
  endparams

  label while1 :
     %1 = 0
     %2 = r <= %1
     %2 = not %2
     ifFalse %2 goto endwhile1
     %3 = 1
     %4 = r - %3
     r = %4
     goto while1
  label endwhile1 :
     return
endfunction

function main
  vars
    a integer
  endvars

     %1 = 3
     %2 = 2
     %3 = float %2
     pushparam 
     pushparam %1
     pushparam %3
     call f
     popparam 
     popparam 
     popparam %4
     ifFalse %4 goto endif1
     %5 = 3.7
     %7 = float a
     %6 = %7 +. %5
     %8 = 4
     %10 = float %8
     %9 = %6 +. %10
     writef %9
     writes "\n"
  label endif1 :
     return
endfunction


