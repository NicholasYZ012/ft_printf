#include "../libft/libft.h"
#include "../ft_printf.h"
#include <stdio.h>

int main(){
	ft_printf("### FT_PRINTF TEST ###\n");
	ft_printf("|%u|\n", -1000);
    printf("|%u|\n\n", -1000);

    ft_printf("|%d|\n", -2147483648);
    printf("|%d|\n\n", -2147483648);

    ft_printf("|%i|\n", 2147483647);
    printf("|%i|\n\n", 2147483647);


    // === 2. FLAGS (-, 0, ., #, space, +) ===
    ft_printf("### Left-justify vs Zero-padding ###\n");
    ft_printf("|%-10d|\n", 42);
    printf("|%-10d|\n\n", 42);

    ft_printf("|%010d|\n", 42);
    printf("|%010d|\n\n", 42);

    // Sign forcing flags (+ and space)
	ft_printf("### Sign forcing flags ###\n");
    ft_printf("|%+d|\n", 42);
    printf("|%+d|\n\n", 42);

    ft_printf("|% i|\n", 42);
    printf("|% i|\n\n", 42);

    // Alternative form (#) with Hexadecimal
	ft_printf("### Alternative form (#) with Hexadecimal ###\n");
    ft_printf("|%#x|\n", 255);
    printf("|%#x|\n\n", 255);

    ft_printf("|%#X|\n", 0);
    printf("|%#X|\n\n", 0);


    // === 3. PRECISION VS WIDTH EDGE CASES ===
	ft_printf("### PRECISION VS WIDTH EDGE CASES ###\n");
    // Precision greater than width
    ft_printf("|%5.10d|\n", 123);
    printf("|%5.10d|\n\n", 123);

    // Width greater than precision
    ft_printf("|%10.5d|\n", 123);
    printf("|%10.5d|\n\n", 123);

    // Zero flag overridden by precision in integers
    ft_printf("|%010.5d|\n", 123);
    printf("|%010.5d|\n\n", 123);

    // Empty/Zero precision with 0 value (should print nothing for the number)
    ft_printf("|%.0d|\n", 0);
    printf("|%.0d|\n\n", 0);

    ft_printf("|%.d|\n", 0);
    printf("|%.d|\n\n", 0);


    // === 4. COMPLEX FLAG COMBINATIONS ===
	ft_printf("### COMPLEX FLAG COMBINATIONS ###\n");
    // Minus and Zero flags combined (Minus overrides Zero)
    ft_printf("|%-010d|\n", 888);
    printf("|%-010d|\n\n", 888);

    // Plus and Space flags combined (Plus overrides Space)
    ft_printf("|%+ d|\n", 888);
    printf("|%+ d|\n\n", 888);

    // Hash, Zero, Width and Precision combined
    ft_printf("|%#012.8x|\n", 4242);
    printf("|%#012.8x|\n\n", 4242);

    ft_printf("|%-#12.8X|\n", 4242);
    printf("|%-#12.8X|\n\n", 4242);


    // === 5. POINTER SPECIFIER (%p) EDGE CASES ===
	ft_printf("### POINTER SPECIFIER (%%p) EDGE CASES ###\n");
    ft_printf("|%p|\n", NULL);
    printf("|%p|\n\n", NULL);

    ft_printf("|%20p|\n", (void *)0x123abc);
    printf("|%20p|\n\n", (void *)0x123abc);

    ft_printf("|%-20p|\n", (void *)0x123abc);
    printf("|%-20p|\n\n", (void *)0x123abc);


    // === 6. PERCENT SPECIFIER (%%) WITH FLAGS ===
	ft_printf("### PERCENT SPECIFIER (%%) WITH FLAGS ###\n");
    ft_printf("|%%|\n");
    printf("|%%|\n\n");

    ft_printf("|%10%|\n");
    printf("|%10%|\n\n");

    ft_printf("|%-10%|\n");
    printf("|%-10%|\n\n");

}