/*
** EPITECH PROJECT, 2017
** tests_add_it
** File description:
** tests_add_it
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

Test(put_nbr_octal, test_put_nbr_octal)
{
	int	r_value = 0;

	r_value = my_put_nbr_octal(10);
	cr_assert_eq(r_value, 2);
	r_value = my_put_nbr_octal(42);
	cr_assert_eq(r_value, 2);
}

Test(put_nbr_unsigned, test_put_nbr_unsigned)
{
	int	r_value = 0;

	r_value = my_put_nbr_unsigned(10);
	cr_assert_eq(r_value, 2);
	r_value = my_put_nbr_unsigned(420);
	cr_assert_eq(r_value, 3);
}

Test(put_nbr_plus, test_put_nbr_plus)
{
	int	r_value = 0;

	r_value = my_put_nbr_plus(10);
	cr_assert_eq(r_value, 3);
	r_value = my_put_nbr_plus(420);
	cr_assert_eq(r_value, 4);
}
