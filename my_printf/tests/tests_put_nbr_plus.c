/*
** EPITECH PROJECT, 2017
** tests_add_it
** File description:
** tests_add_it
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void	redirect_all_std_plus(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}
Test(put_nbr_plus1, test_put_nbr_plus1, .init = redirect_all_std_plus)
{
	my_put_nbr_plus(6);
	cr_assert_stdout_eq_str("+6");
}

Test(put_nbr_plus2, test_put_nbr_plus2, .init = redirect_all_std_plus)
{
	my_put_nbr_plus(42);
	cr_assert_stdout_eq_str("+42");
}
