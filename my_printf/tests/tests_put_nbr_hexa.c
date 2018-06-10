/*
** EPITECH PROJECT, 2017
** tests_add_it
** File description:
** tests_add_it
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void	redirect_all_std_hexa(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

Test(put_nbr_hexa1, test_put_nbr_hexa1, .init = redirect_all_std_hexa)
{
	my_put_nbr_hexa(10);
	cr_assert_stdout_eq_str("a");
}

Test(put_nbr_hexa2, test_put_nbr_hexa2, .init = redirect_all_std_hexa)
{
	my_put_nbr_hexa(42);
	cr_assert_stdout_eq_str("2a");
}
