/*
** EPITECH PROJECT, 2017
** tests_str
** File description:
** tests_str
*/

#include "my.h"
#include <criterion/criterion.h>

Test(putstr, check_putstr)
{
	cr_assert_eq(my_putstr(""), 0);
	cr_assert_eq(my_putstr("toto"), 4);
}

Test(strlen, check_strlen)
{
	cr_assert_eq(my_strlen(""), 0);
	cr_assert_eq(my_strlen("toto"), 4);
}
