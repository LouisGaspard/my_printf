/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** my_printf
*/

#include "my.h"

void	init_tab_fonct(int (**tab_fonct)())
{
	tab_fonct[0] = my_putstr;
	tab_fonct[1] = my_put_nbr;
	tab_fonct[2] = my_put_nbr;
	tab_fonct[3] = my_put_nbr_octal;
	tab_fonct[4] = my_put_nbr_hexa;
	tab_fonct[5] = my_put_nbr_hexa_cap;
	tab_fonct[6] = my_put_nbr_unsigned;
	tab_fonct[7] = my_printable;
	tab_fonct[8] = my_print_pointer;
	tab_fonct[9] = my_put_nbr_binary;
	tab_fonct[10] = my_putchar;
	tab_fonct[11] = my_put_nbr_long;
}

int	my_flag(t_flags *f, char format)
{
	if (format == 'o') {
		f->nb_letter += my_putchar('0');
		f->nb_letter += my_put_nbr_octal(va_arg(f->arg, int));
	}
	if (format == 'x') {
		f->nb_letter += my_putstr("0x");
		f->nb_letter += my_put_nbr_hexa(va_arg(f->arg, int));
	}
	if (format == 'X') {
		f->nb_letter += my_putstr("0x");
		f->nb_letter += my_put_nbr_hexa_cap(va_arg(f->arg, int));
	} else {
		f->nb_format = check_format(format);
		if (f->nb_format != -1)
			f->nb_letter += (*f->tab_fonct[f->nb_format])(va_arg(f->arg, void *));
		else
			f->nb_letter += my_putchar(format);
	}
	return (f->nb_letter);
}

int	parse_format(t_flags *f)
{
	for (int a = 0; f->format[a] != '\0'; a++) {
		f->nb_space = 0;
		f->nb_format = -1;
		if (f->format[a] == '%' && f->format[a + 1] == '\0')
			return (0);
		if ((f->s_nb_letter = format_plus_minus(f, &a)) > 0) {
			f->nb_letter += f->s_nb_letter;
			continue;
		}
		if (f->format[a] == '%' && if_flag(f->format[a + 1])) {
			f->nb_format = check_format(f->format[a + 1]);
			a++;
		}
		f->nb_format == 11 ? a++ : a;
		if ((f->s_nb_letter = format_space(f, &a)) > 0)
			f->nb_letter += f->s_nb_letter;
		if ((f->s_nb_letter = format_nb(f, &a)) == 1) {
			f->nb_letter += f->s_nb_letter;
			continue;
		}
		else if ((f->s_nb_letter = format_nb(f, &a)) > 1)
			f->nb_letter += f->s_nb_letter;
		if ((f->s_nb_letter = format_nb_minus(f, &a, 0)) > 0) {
			f->nb_letter += f->s_nb_letter;
			continue;
		}
		if (f->nb_format != - 1 && f->nb_format != 12)
			f->nb_letter += (*f->tab_fonct[f->nb_format])(va_arg(f->arg, void *));
		else if (f->nb_format == 12) {
			f->nb_letter += my_flag(f, f->format[a + 1]);
			a++;
		}
		else
			f->nb_letter += my_putchar(f->format[a]);
	}
	return (f->nb_letter);
}

int	my_printf(const char *format, ...)
{
	t_flags	*flags;

	if ((flags = malloc(sizeof(*flags))) == NULL)
		return (84);
	if ((flags->format = malloc(sizeof(char) * my_strlen(format) + 1)) == NULL)
		return (84);
	flags->format = format;
	flags->nb_space = 0;
	flags->s_nb_letter = 0;
	flags->nb_format = 0;
	va_start(flags->arg, format);
	init_tab_fonct(flags->tab_fonct);
	flags->nb_letter = parse_format(flags);
	va_end(flags->arg);
	return (flags->nb_letter);
}
