function main
  vars
    a integer
    b integer
    end boolean
    pi float
  endvars

   %1 = 12
   a = %1
   %2 = 5
   %3 = a * %2
   %4 = 1
   %5 = a + %4
   %6 = a * %5
   %7 = %3 + %6
   b = %7
   %8 = b < a
   %8 = not %8
   %9 = 0
   %10 = a == %9
   %11 = not %10
   %12 = %8 and %11
   end = %12
   %13 = 3.3
   %14 = 1
   %15 = %14 / a
   %17 = float %15
   %16 = %13 +. %17
   %18 = 2.0
   %19 = -. %18
   %21 = float a
   %20 = %19 /. %21
   %22 = %16 -. %20
   pi = %22
   %23 = a == b
   %24 = %23 or end
   writei %24
   writes "\n"
   %25 = a * b
   writei %25
   writes "\n"
   %26 = 2
   %28 = float %26
   %27 = %28 *. pi
   writef %27
   writes "\n"
   return
endfunction


