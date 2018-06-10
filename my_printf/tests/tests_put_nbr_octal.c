/*
** EPITECH PROJECT, 2017
** tests_add_it
** File description:
** tests_add_it
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void	redirect_all_std_octal(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

Test(put_nbr_octal1, test_put_nbr_octal1, .init = redirect_all_std_octal)
{
	my_put_nbr_octal(10);
	cr_assert_stdout_eq_str("12");
}

Test(put_nbr_octal2, test_put_nbr_octal2, .init = redirect_all_std_octal)
{
	my_put_nbr_octal(42);
	cr_assert_stdout_eq_str("52");
}
