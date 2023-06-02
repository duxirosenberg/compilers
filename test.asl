func f(a:int, b:float): bool
  var x:int
  var y:bool
  var z:array[10] of int
  z[9] = (a + 67);
  x = z[9];
  write z[3]; write "\n";
  return true;
endfunc


func main()
  var a:int
  if f(3, 2) then
     write a+3.7+4; write "\n";
  endif
endfunc
