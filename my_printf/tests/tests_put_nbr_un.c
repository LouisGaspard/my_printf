/*
** EPITECH PROJECT, 2017
** tests_add_it
** File description:
** tests_add_it
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void	redirect_all_std_un(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

Test(put_nbr_un1, test_put_nbr_un1, .init = redirect_all_std_un)
{
	my_put_nbr_unsigned(9);
	cr_assert_stdout_eq_str("9");
}

Test(put_nbr_un2, test_put_nbr_un2, .init = redirect_all_std_un)
{
	my_put_nbr_unsigned(42);
	cr_assert_stdout_eq_str("42");
}
