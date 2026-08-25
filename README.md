<!-- 
%[flags][width][.precision]type

Flags:5 (-+0 #)
	1.	-: left justify
	2.	+: print positive sign
	3.	0: pad number with zeros 
	4.	\s: insert space before positive numbers (to align with negative numbers)
	5.	#: adds prefix (0x hex)

Width: an integer specifying minimum number of chars to print

Precision: 
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

Current issue:
might need to implement flag for precision setting in order to differentiate precision 0 and unset precision

 -->
*This project has been created as part of the 42 curriculum by \<nilim>*

# Description
ft_printf is a reimplementation of the printf function in a slightly simpler format. Although all flags, width and precision are implemented, certain types are excluded.

# Instructions
A Makefile is included for compiling the library.

Standard commands (Usage: make *command*):
- all(default): compiles the object files, create and insert objects into ft_printf.a
- clean: removes all object files
- fclean: removes the object files and ft_printf.a
- re: updates the library and objects by removing them and recompiling and archiving again

# ft_printf
The function works according to the following procedures:

1. The inputted string is searched for placeholders char by char.
2. Each char that isn't after a placeholder is printed out.
2. If found, then the following chars are parsed for flags, width, precision, and the specifier and the information is then stored in a struct.
3. Using variables in the struct, the flags, width and precision are handled accordingly.
4. When they have been dealt with accordingly, the variadic arguments are called based on the specifier and printed out.
5. If required, then the second phase of flag handling will then commence.
6. These procedures loop until the NULL terminator of the string is reached.

# Resources