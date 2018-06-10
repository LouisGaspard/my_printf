/*
** EPITECH PROJECT, 2017
** tests_add_it
** File description:
** tests_add_it
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void	redirect_all_std_nbr(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

Test(put_nbr_1, test_put_nbr_1, .init = redirect_all_std_nbr)
{
	my_put_nbr(9);
	cr_assert_stdout_eq_str("9");
}

Test(put_nbr2, test_put_nbr2, .init = redirect_all_std_nbr)
{
	my_put_nbr(42);
	cr_assert_stdout_eq_str("42");
}
