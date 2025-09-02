/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam_printf2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 10:31:35 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/09/02 11:28:38 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdarg.h>
#include <unistd.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		return (ft_putstr("-2147483648"));
	}
	if (nb == 0)
		return (ft_putchar('0'));
	if (nb < 0)
	{
		ft_putchar('-');
		count++;
		nb = -nb;
	}
	if (nb > 9)
	{
		count += ft_putnbr(nb / 10);
	}
	ft_putchar(nb % 10 + '0');
	count++;
	return (count);
}

int	ft_tohex(unsigned long int n, unsigned long int base)
{
	int		count;
	char	*hex;

	count = 0;
	hex = "0123456789abcdef";
	if (n >= base)
	{
		count += ft_tohex(n / base, base);
		ft_putchar(hex[n % base]);
	}
	else
		ft_putchar(hex[n % base]);
	count++;
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
		count += ft_tohex(va_arg(*ap, unsigned long int), 16);
	else
		return (-1);
	return (count);
}

int	ft_printf(const char *format, ...)
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
	int				i;
	char			c;
	char			*s;
	unsigned int	x;
	int				value;

	i = 4567;
	c = 'd';
	s = "hello world";
	x = 7485;
	value = ft_printf("blaa %i, bla %c, bla %s, blabla %x\n", i, c, s, x);
	ft_printf("%i\n", value);
	value = printf("blaa %i, bla %c, bla %s, blabla %x\n", i, c, s, x);
	printf("%i\n", value);
	return (0);
}
