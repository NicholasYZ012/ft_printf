<!-- 
%[flags][width][.precision]type

High level:
	1.	Separate into normal strings and format strings 

Flags:5 (-+0 #)
	1.	-: left justify
	2.	+: print positive sign
	3.	0: pad number with zeros 
	4.	\s: insert space before positive numbers (to align with negative numbers)
	5.	#: adds prefix (0x hex; 0 octal; force decimal point, float)

Width: an integer specifying minimum number of chars to print

Precision: 
%f: limit digits after decimal point
%i: min digit counter
%s: cuts off string at maximum length

Type:9 (cspdiuxX%)
c: char
s: string
p: void * argument print as hex
d/i: integer
u: unsigned int
x: hex 
X: HEX
%: prints out %
 -->