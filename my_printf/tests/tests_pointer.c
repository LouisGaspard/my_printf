/*
** EPITECH PROJECT, 2017
** tests_pointeur
** File description:
** tests_pointeur
*/

#include "my.h"
#include <criterion/criterion.h>

Test(print_pointeur, check_print_pointeur)
{
	cr_assert_eq(my_print_pointer(12, 0), 3);
}

Test(my_pointeur, check_my_pointeur)
{
	cr_assert_eq(my_pointer(12), 1);
	cr_assert_eq(my_pointer(0), 0);
}
