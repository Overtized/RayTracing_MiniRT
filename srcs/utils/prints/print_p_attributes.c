/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p_attributes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchanlia <mchanlia@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:42:33 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/28 15:24:13 by mchanlia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	print_p_attributes(t_point point, char *var_name)
{
	printf(P_GREEN"\n--- PRINTING ATTRIBUTE OF %s ---\n", var_name);
	printf("Point X value :  %.2f\n", point.p.x);
	printf("Point Y value :  %.2f\n", point.p.y);
	printf("Point Z value :  %.2f\n", point.p.z);
	printf("Point W value :  %.2f\n", point.p.w);
	printf("Point Color value :  0x%06X ", point.color.hex);
	printf("\033[48;2;%d;%d;%dm   \033[0m\n",
		(int)point.color.r, (int)point.color.g, (int)point.color.b);
	printf("----------\n"P_RESET);
}

void	print_vec3(t_point v, char *name)
{
	printf("%s\tx : %.2f\ty : %.2f\tz : %.2f\n", name,
		v.p.x, v.p.y, v.p.z);
}
