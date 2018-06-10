/*
** EPITECH PROJECT, 2017
** tests_add_it
** File description:
** tests_add_it
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void	redirect_all_std_binary(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

Test(put_nbr_binary1, test_put_nbr_binary1, .init = redirect_all_std_binary)
{
	my_put_nbr_binary(10);
	cr_assert_stdout_eq_str("1010");
}

Test(put_nbr_binary2, test_put_nbr_binary2, .init = redirect_all_std_binary)
{
	my_put_nbr_binary(42);
	cr_assert_stdout_eq_str("101010");
}
