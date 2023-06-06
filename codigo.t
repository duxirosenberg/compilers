function read_chars
  params
    _result integer
    a character array
  endparams

  vars
    i integer
  endvars

     %1 = 0
     i = %1
  label while1 :
     %2 = 10
     %3 = i < %2
     ifFalse %3 goto endwhile1
     readc %4
     %5 = a
     %5[i] = %4
     %7 = a
     %6 = %7[i]
     %8 = '.'
     %9 = %6 == %8
     %9 = not %9
     ifFalse %9 goto else1
     %10 = 1
     %11 = i + %10
     i = %11
     goto endif1
  label else1 :
     _result = i
  label endif1 :
     goto while1
  label endwhile1 :
     %12 = 10
     _result = %12
     return
endfunction

function find_vowels
  params
    n integer
    vc character array
    vb boolean array
  endparams

  vars
    c character
  endvars

  label while1 :
     %1 = 0
     %2 = n <= %1
     %2 = not %2
     ifFalse %2 goto endwhile1
     %3 = 1
     %4 = n - %3
     %6 = vc
     %5 = %6[%4]
     c = %5
     %7 = 1
     %8 = n - %7
     %9 = 'a'
     %10 = c == %9
     %11 = 'e'
     %12 = c == %11
     %13 = %10 or %12
     %14 = 'i'
     %15 = c == %14
     %16 = %13 or %15
     %17 = 'o'
     %18 = c == %17
     %19 = %16 or %18
     %20 = 'u'
     %21 = c == %20
     %22 = %19 or %21
     %23 = vb
     %23[%8] = %22
     %24 = 1
     %25 = n - %24
     n = %25
     goto while1
  label endwhile1 :
     return
endfunction

function write_consonants
  params
    _result float
    n integer
    vc character array
    vb boolean array
  endparams

  vars
    k float
    i integer
  endvars

     %1 = 0
     i = %1
     %2 = 0
     %3 = float %2
     k = %3
  label while1 :
     %4 = i == n
     %4 = not %4
     ifFalse %4 goto endwhile1
     %6 = vb
     %5 = %6[i]
     ifFalse %5 goto else1
     %7 = 1
     %9 = float %7
     %8 = k +. %9
     k = %8
     goto endif1
  label else1 :
     %11 = vc
     %10 = %11[i]
     writec %10
  label endif1 :
     %12 = 1
     %13 = i + %12
     i = %13
     goto while1
  label endwhile1 :
     %14 = '\n'
     writec %14
     %15 = 100
     %17 = float %15
     %16 = %17 *. k
     %19 = float n
     %18 = %16 /. %19
     _result = %18
     return
endfunction

function main
  vars
    a character 10
    b boolean 10
    n integer
    p float
  endvars

   %1 = &a
   pushparam 
   pushparam %1
   call read_chars
   popparam 
   popparam %2
   n = %2
   %3 = &a
   %4 = &b
   pushparam n
   pushparam %3
   pushparam %4
   call find_vowels
   popparam 
   popparam 
   popparam 
   %5 = &a
   %6 = &b
   pushparam 
   pushparam n
   pushparam %5
   pushparam %6
   call write_consonants
   popparam 
   popparam 
   popparam 
   popparam %7
   p = %7
   writef p
   writes "\n"
   return
endfunction


