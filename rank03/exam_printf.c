/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam_printf2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:44:21 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/09/01 15:53:48 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdint.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	ft_tohex(unsigned long int n, unsigned long int base)
{
	int		count;
	char	*hexlow;

	count = 0;
	hexlow = "0123456789abcdef";
	if (n >= base)
	{
		count += ft_tohex(n / base, base);
		ft_putchar(hexlow[n % base]);
	}
	else
		ft_putchar(hexlow[n % base]);
	count++;
	return (count);
}

int	ft_putnbr(int num)
{
	int	count;

	count = 0;
	if (num < 0)
	{
		ft_putchar('-');
		count++;
	}
	else if (num == 0)
	{
		ft_putchar('0');
		count = 1;
	}
	else if (num > 9)
	{
		count += ft_putnbr(num / 10);
	}
	count += ft_putchar((num % 10) + '0');
	return (count);
}

int	print_format(va_list *ap, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(*ap, int));
	else if (c == 's')
		count += ft_putstr(va_arg(*ap, char *));
	else if (c == 'i')
		count += ft_putnbr(va_arg(*ap, int));
	else if (c == 'x')
		count += ft_tohex(va_arg(*ap, unsigned int), 16);
	return (count);
}

int	exam_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	if(!format)
		return (-1);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (-1);
			count += print_format(&ap, *format);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	return (count);
}

#include <stdio.h>

int	main(void)
{
	int				i;
	int				value;
	char			c;
	char			*s;
	unsigned int	x;

	i = 900;
	c = 'f';
	s  = "hello";
	x = 8759;

	value = exam_printf("hello %s, blabla %c beepboop %i boop %x\n", s, c, i, x);
	exam_printf("%i\n", value);
//	value = printf("hello %s, blabla %c beepboop %i boop %x\n", s, c, i, x);
//	printf("%i\n", value);
	return (0);
}
