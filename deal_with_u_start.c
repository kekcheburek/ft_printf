/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_u_start.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 14:24:22 by ekiriche          #+#    #+#             */
/*   Updated: 2018/02/03 14:26:43 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	deal_with_u(t_format *chunk, va_list arg, int *count)
{
	if (ft_strcmp(chunk->length_flag, "none") == 0)
		deal_with_u1(chunk, arg, count);
	else if (ft_strcmp(chunk->length_flag, "ll") == 0 ||
			ft_strcmp(chunk->length_flag, "l") == 0 ||
			ft_strcmp(chunk->length_flag, "z") == 0 ||
			ft_strcmp(chunk->length_flag, "j") == 0 ||
			ft_strcmp(chunk->length_flag, "t") == 0)
		deal_with_u2(chunk, arg, count);
	else if (ft_strcmp(chunk->length_flag, "h") == 0)
		deal_with_u3(chunk, arg, count);
	else if (ft_strcmp(chunk->length_flag, "hh") == 0)
		deal_with_u4(chunk, arg, count);
}

void	deal_with_u1(t_format *chunk, va_list arg, int *count)
{
	unsigned int	i;

	i = va_arg(arg, unsigned int);
	counting(chunk, (long long int)i, count);
	if (ft_find_point0(chunk) && i == 0 && chunk->hash == 0)
	{
		case_point0(chunk);
		return ;
	}
	if (i < 0 && chunk->precision > chunk->field_width)
		*count += 1;
	step1_di_int(chunk, i);
}

void	deal_with_di2(t_format *chunk, va_list arg, int *count)
{
	long long int	li;

	li = va_arg(arg, long long int);
	counting(chunk, li, count);
	if (ft_find_point0(chunk) && li == 0)
	{
		case_point0(chunk);
		return ;
	}
	if (li < 0 && chunk->precision > chunk->field_width)
		*count += 1;
	step1_di_li(chunk, li);
}

void	deal_with_di3(t_format *chunk, va_list arg, int *count)
{
	short int	i;

	i = va_arg(arg, int);
	counting(chunk, (long long int)i, count);
	if (ft_find_point0(chunk) && i == 0)
	{
		case_point0(chunk);
		return ;
	}
	if (i < 0 && chunk->precision > chunk->field_width)
		*count += 1;
	step1_di_int(chunk, i);
}

void	deal_with_di4(t_format *chunk, va_list arg, int *count)
{
	signed char	i;

	i = va_arg(arg, int);
	counting(chunk, (long long int)i, count);
	if (ft_find_point0(chunk) && i == 0)
	{
		case_point0(chunk);
		return ;
	}
	if (i < 0 && chunk->precision > chunk->field_width)
		*count += 1;
	step1_di_int(chunk, i);
}
}
}
}
}
}
}
}
}
}