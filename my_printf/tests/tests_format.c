/*
** EPITECH PROJECT, 2017
** tests_add_it
** File description:
** tests_add_it
*/

#include "my.h"
#include <criterion/criterion.h>

Test(is_digit, check_is_digit)
{
	cr_assert_eq(is_digit('2'), 1);
	cr_assert_eq(is_digit('o'), 0);
}

Test(is_int, check_is_int)
{
	cr_assert_eq(is_int('d'), 1);
	cr_assert_eq(is_int('i'), 1);
	cr_assert_eq(is_int('s'), 0);
}

Test(check_format, check_position_flag)
{
	cr_assert_eq(check_format('s'), 0);
	cr_assert_eq(check_format('o'), 3);
	cr_assert_eq(check_format('S'), 7);
	cr_assert_eq(check_format('#'), 12);
	cr_assert_eq(check_format('g'), -1);
}

Test(if_flag, check_if_format_is_flag)
{
	cr_assert_eq(if_flag('s'), 1);
	cr_assert_eq(if_flag('o'), 1);
	cr_assert_eq(if_flag('S'), 1);
	cr_assert_eq(if_flag('g'), 0);
}
