function main
  vars
    n integer
    f integer
    aux integer
    end boolean
  endvars

     readi n
     aux = n
     %1 = 0
     %2 = n < %1
     ifFalse %2 goto endif1
     writes "n >= 0!\n"
     %3 = 1
     end = %3
  label endif1 :
     %4 = 1
     f = %4
  label while1 :
     %5 = not end
     %6 = 1
     %7 = n <= %6
     %7 = not %7
     %8 = %5 and %7
     ifFalse %8 goto endwhile1
     %9 = f * n
     f = %9
     %10 = 1
     %11 = n - %10
     n = %11
     goto while1
  label endwhile1 :
     %12 = 0
     %13 = end ==. %12
     ifFalse %13 goto endif2
     writei aux
     writes "!="
     writei f
     writes "\n"
  label endif2 :
     return
endfunction


