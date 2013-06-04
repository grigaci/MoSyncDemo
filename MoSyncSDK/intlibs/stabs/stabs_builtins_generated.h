#define BUILTINS(f, m)\
f(int,Int)\
m(char,Char)\
m(long int,LongInt)\
m(unsigned int,UnsignedInt)\
m(long unsigned int,LongUnsignedInt)\
m(long long int,LongLongInt)\
m(long long unsigned int,LongLongUnsignedInt)\
m(short int,ShortInt)\
m(short unsigned int,ShortUnsignedInt)\
m(signed char,SignedChar)\
m(unsigned char,UnsignedChar)\
m(wchar_t,Wchar)\
m(float,Float)\
m(double,Double)\
m(long double,LongDouble)\

#define BROKEN_BUILTINS(m)\
m(complex int,ComplexInt)\
m(complex float,ComplexFloat)\
m(complex double,ComplexDouble)\
m(complex long double,ComplexLongDouble)\
m(void,Void)\
m(nothrow_t,Nothrow)\

