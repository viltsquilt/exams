/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:46:28 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/08/25 15:04:42 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>

int	ft_putchar(char c)
{
	return(write(1, &c, 1));
}

int	ft_putstr(char	*s)
{
	int	i;

	if (!s)
		return (write(1, "(null)", 6));
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	to_hex(unsigned long int n, unsigned long int base)
{
	int		numlen;
	char	*hex;

	hex = "0123456789abcdef";
	numlen = 0;
	if (n >= base)
	{
		numlen += to_hex(n / base, base);
		ft_putchar(hex[n % base]);
	}
	else
		ft_putchar(hex[n % base]);
	numlen++;
	return (numlen);
}

int	print_format(va_list *ap, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(*ap, int));
	else if (c == 's')
		count += ft_putstr(va_arg(*ap, char *));
	else if (c == 'x')
		count += to_hex(va_arg(*ap, unsigned int), 16);
	else
		return (-1);
	return (count);
}

int	exam_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	if (!format)
		return (-1);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (va_end(ap), -1);
			count += print_format(&ap, *format);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(ap);
	return (count);
}

#include <stdio.h>

int	main(void)
{
	char	*word;
	char	c;
	int		hex;
	int		value;

	word = "Viltsu";
	c = 'A';
	hex = 7776853;
	value = exam_printf("My name is %s %c and this is a random hex: %x\n", word, c, hex);
//	value = printf("My name is %s %c and this is a random hex: %x\n", word, c, hex);
	printf("%i\n", value);
	return (0);
}
