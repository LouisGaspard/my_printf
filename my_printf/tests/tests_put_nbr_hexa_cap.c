/*
** EPITECH PROJECT, 2017
** tests_add_it
** File description:
** tests_add_it
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void	redirect_hexa_cap(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

Test(put_nbr_hexa_cap1, test_put_nbr_hexa_cap1, .init = redirect_hexa_cap)
{
	my_put_nbr_hexa_cap(10);
	cr_assert_stdout_eq_str("A");
}

Test(put_nbr_hexa_cap2, test_put_nbr_hexa_cap2, .init = redirect_hexa_cap)
{
	my_put_nbr_hexa_cap(42);
	cr_assert_stdout_eq_str("2A");
}
