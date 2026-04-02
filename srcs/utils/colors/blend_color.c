/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blend_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxence <maxence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 17:23:45 by maxence           #+#    #+#             */
/*   Updated: 2026/03/26 17:24:24 by maxence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	blend_color(float *fraction, t_color *ca, t_color *cb)
{
	return (sum_two_colors(
			multiply_color(*ca, 1 - *fraction),
			multiply_color(*cb, *fraction)
		));
}
