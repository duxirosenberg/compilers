function main
  vars
    a integer
    b integer
    x float
    y float
  endvars

     %1 = 3
     %2 = float %1
     x = %2
     %3 = 2
     a = %3
     %4 = 6
     b = %4
     %5 = 2
     %6 = 3
     %9 = %6
     %8 = float %5
     %11 = %9
     %14 = 0
     %13 = 1
     %7 = float %13
  label while1_exponential :
     %12 = %13 <= %11
     ifFalse %12 goto endwhile1_exponential
     %7 = %7 *. %8
     %11 = %11 - %13
     goto while1_exponential
  label endwhile1_exponential :
     %15 = 4
     %18 = %15
     %17 = %7
     %19 = %18
     %22 = 0
     %21 = 1
     %16 = float %21
  label while2_exponential :
     %20 = %21 <= %19
     ifFalse %20 goto endwhile2_exponential
     %16 = %16 *. %17
     %19 = %19 - %21
     goto while2_exponential
  label endwhile2_exponential :
     y = %16
     writef y
     writes "\n"
     %23 = 2
     %24 = 2.1
     %25 = 3
     %28 = %25
     %27 = %24
     %29 = %28
     %32 = 0
     %31 = 1
     %26 = float %31
  label while3_exponential :
     %30 = %31 <= %29
     ifFalse %30 goto endwhile3_exponential
     %26 = %26 *. %27
     %29 = %29 - %31
     goto while3_exponential
  label endwhile3_exponential :
     %33 = 4
     %36 = %33
     %35 = %26
     %37 = %36
     %40 = 0
     %39 = 1
     %34 = float %39
  label while4_exponential :
     %38 = %39 <= %37
     ifFalse %38 goto endwhile4_exponential
     %34 = %34 *. %35
     %37 = %37 - %39
     goto while4_exponential
  label endwhile4_exponential :
     %42 = float %23
     %41 = %42 /. %34
     y = %41
     writef y
     writes "\n"
     %43 = 2
     %44 = 2.1
     %46 = float %43
     %45 = %46 /. %44
     %47 = 3
     %50 = %47
     %49 = %45
     %51 = %50
     %54 = 0
     %53 = 1
     %48 = float %53
  label while5_exponential :
     %52 = %53 <= %51
     ifFalse %52 goto endwhile5_exponential
     %48 = %48 *. %49
     %51 = %51 - %53
     goto while5_exponential
  label endwhile5_exponential :
     %55 = 4
     %58 = %55
     %57 = %48
     %59 = %58
     %62 = 0
     %61 = 1
     %56 = float %61
  label while6_exponential :
     %60 = %61 <= %59
     ifFalse %60 goto endwhile6_exponential
     %56 = %56 *. %57
     %59 = %59 - %61
     goto while6_exponential
  label endwhile6_exponential :
     y = %56
     writef y
     writes "\n"
  label while13 :
     %65 = b
     %64 = float a
     %67 = %65
     %70 = 0
     %69 = 1
     %63 = float %69
  label while7_exponential :
     %68 = %69 <= %67
     ifFalse %68 goto endwhile7_exponential
     %63 = %63 *. %64
     %67 = %67 - %69
     goto while7_exponential
  label endwhile7_exponential :
     %71 = 10
     %73 = float %71
     %72 = %63 <=. %73
     %72 = not %72
     ifFalse %72 goto endwhile13
     %74 = 2
     %77 = b
     %76 = float a
     %79 = %77
     %82 = 0
     %81 = 1
     %75 = float %81
  label while8_exponential :
     %80 = %81 <= %79
     ifFalse %80 goto endwhile8_exponential
     %75 = %75 *. %76
     %79 = %79 - %81
     goto while8_exponential
  label endwhile8_exponential :
     %84 = float %74
     %83 = %84 *. %75
     %85 = 5
     %87 = float %85
     %86 = %83 /. %87
     writef %86
     writes "\n"
     %88 = 2
     %89 = %88 * a
     %92 = b
     %91 = float %89
     %94 = %92
     %97 = 0
     %96 = 1
     %90 = float %96
  label while9_exponential :
     %95 = %96 <= %94
     ifFalse %95 goto endwhile9_exponential
     %90 = %90 *. %91
     %94 = %94 - %96
     goto while9_exponential
  label endwhile9_exponential :
     %98 = 5
     %100 = float %98
     %99 = %90 /. %100
     writef %99
     writes "\n"
     %101 = 2
     %102 = 5
     %103 = b / %102
     %106 = %103
     %105 = float a
     %108 = %106
     %111 = 0
     %110 = 1
     %104 = float %110
  label while10_exponential :
     %109 = %110 <= %108
     ifFalse %109 goto endwhile10_exponential
     %104 = %104 *. %105
     %108 = %108 - %110
     goto while10_exponential
  label endwhile10_exponential :
     %113 = float %101
     %112 = %113 *. %104
     writef %112
     writes "\n"
     %114 = 2
     %117 = b
     %116 = float a
     %119 = %117
     %122 = 0
     %121 = 1
     %115 = float %121
  label while11_exponential :
     %120 = %121 <= %119
     ifFalse %120 goto endwhile11_exponential
     %115 = %115 *. %116
     %119 = %119 - %121
     goto while11_exponential
  label endwhile11_exponential :
     %124 = float %114
     %123 = %124 *. %115
     %125 = 5
     %127 = float %125
     %126 = %123 /. %127
     writef %126
     writes "\n"
     %128 = 2
     %129 = %128 * a
     %130 = 5
     %131 = b / %130
     %134 = %131
     %133 = float %129
     %136 = %134
     %139 = 0
     %138 = 1
     %132 = float %138
  label while12_exponential :
     %137 = %138 <= %136
     ifFalse %137 goto endwhile12_exponential
     %132 = %132 *. %133
     %136 = %136 - %138
     goto while12_exponential
  label endwhile12_exponential :
     writef %132
     writes "\n"
     %140 = 1
     %141 = b - %140
     b = %141
     goto while13
  label endwhile13 :
     %142 = 2
     %143 = 4
     %144 = %143 / a
     %145 = b + %144
     %148 = %145
     %147 = float %142
     %150 = %148
     %153 = 0
     %152 = 1
     %146 = float %152
  label while14_exponential :
     %151 = %152 <= %150
     ifFalse %151 goto endwhile14_exponential
     %146 = %146 *. %147
     %150 = %150 - %152
     goto while14_exponential
  label endwhile14_exponential :
     %154 = 1
     %155 = b - %154
     %158 = %155
     %157 = %146
     %159 = %158
     %162 = 0
     %161 = 1
     %156 = float %161
  label while15_exponential :
     %160 = %161 <= %159
     ifFalse %160 goto endwhile15_exponential
     %156 = %156 *. %157
     %159 = %159 - %161
     goto while15_exponential
  label endwhile15_exponential :
     writef %156
     writes "\n"
     return
endfunction


