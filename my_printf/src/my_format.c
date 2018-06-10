/*
** EPITECH PROJECT, 2017
** format
** File description:
** format
*/

#include "my.h"

int	format_plus_minus(t_flags *flags, int *a)
{
	int	nb_letter = 0;

	if (flags->format[*a] == '%' && flags->format[*a + 1] == '+') {
		if (is_int(flags->format[*a + 2]) == 1) {
			nb_letter += my_put_nbr_plus(va_arg(flags->arg, int));
			*a += 2;
		}
		if (flags->format[*a + 2] == '-') {
			nb_letter += my_putchar('+');
			*a += 1;
			nb_letter += format_nb_p_m(flags, a, 0);
		}
	}
	else if (flags->format[*a] == '%' && flags->format[*a + 1] == '-') {
		if (is_int(flags->format[*a + 2]) == 1) {
			nb_letter += my_put_nbr(va_arg(flags->arg, int));
			*a += 2;
		}
	}
	return (nb_letter);
}

int	format_space(t_flags *flags, int *a)
{
	int	nb_letter = 0;

	if (flags->format[*a] == '%' && flags->format[*a + 1] == ' ') {
		if (is_int(flags->format[*a + 2]) == 1) {
			nb_letter += my_putchar(' ');
			*a += 2;
			while (if_flag(flags->format[*a]) != 1)
				(*a)++;
			flags->nb_format = check_format(flags->format[*a]);
		}
	}
	return (nb_letter);
}

int	format_nb(t_flags *flags, int *a)
{
	int	nb_letter = 0;

	if (flags->format[*a] == '%' && (is_digit(flags->format[*a + 1]) == 1 ||
					flags->format[*a + 1] == ' ')) {
		va_copy(flags->my_copy, flags->arg);
		(*a)++;
		if (flags->format[*a] == ' ')
			(*a)++;
		for (*a = *a; if_flag(flags->format[*a]) != 1; (*a)++) {
			flags->nb_space = flags->nb_space * 10;
			flags->nb_space += flags->format[*a] - 48;
		}
		if (flags->format[*a] == '%')
			return (nb_letter += my_putchar(flags->format[*a]));
		len_arg(flags, a);
		while (flags->nb_space-- > 0)
			nb_letter += my_putchar(' ');
		flags->nb_format = check_format(flags->format[*a]);
		va_end(flags->my_copy);
	}
	return (nb_letter);
}

int	format_nb_minus(t_flags *f, int *a, int letter)
{
	if (f->format[*a] == '%' && f->format[*a + 1] == '-' &&
			(is_digit(f->format[*a + 2]) == 1)) {
		va_copy(f->my_copy, f->arg);
		*a += 2;
		if (f->format[*a] == ' ')
			(*a)++;
		for (*a = *a; if_flag(f->format[*a]) != 1; (*a)++) {
			f->nb_space = f->nb_space * 10;
			f->nb_space += f->format[*a] - 48;
		}
		if (f->format[*a] == '%' && if_flag(f->format[*a + 1]) == 0)
			return (letter += my_putchar('%'));
		len_arg(f, a);
		f->nb_format = check_format(f->format[*a]);
		letter += (*f->tab_fonct[f->nb_format])(va_arg(f->arg, void *));
		for (f->nb_space = f->nb_space; f->nb_space > 0; f->nb_space--)
			letter += my_putchar(' ');
		va_end(f->my_copy);
	}
	return (letter);
}

int	format_nb_p_m(t_flags *f, int *a, int letter)
{
	if (f->format[*a] == '+' && f->format[*a + 1] == '-' &&
			(is_digit(f->format[*a + 2]) == 1)) {
		va_copy(f->my_copy, f->arg);
		*a += 2;
		if (f->format[*a] == ' ')
			(*a)++;
		for (*a = *a; if_flag(f->format[*a]) != 1; (*a)++) {
			f->nb_space = f->nb_space * 10;
			f->nb_space += f->format[*a] - 48;
		}
		if (f->format[*a] == '%' && if_flag(f->format[*a + 1]) == 0)
			return (letter += my_putchar('%'));
		len_arg(f, a);
		f->nb_format = check_format(f->format[*a]);
		letter += (*f->tab_fonct[f->nb_format])(va_arg(f->arg, void *));
		for (f->nb_space = f->nb_space; f->nb_space > 1; f->nb_space--)
			letter += my_putchar(' ');
		va_end(f->my_copy);
	}
	return (letter);
}
