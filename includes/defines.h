/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxence <maxence@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 18:53:02 by mchanlia          #+#    #+#             */
/*   Updated: 2026/03/30 10:38:06 by maxence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define _USE_MATH_DEFINES
# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif
// # --------------------------------------------------- #
// # 					TERM-COLORS						 #
// # --------------------------------------------------- #

# define P_RESET		"\033[1;0m"
# define P_BOLD			"\033[1;1m"
# define P_DIM			"\033[1;2m"
# define P_RED			"\033[1;31m"
# define P_GREEN		"\033[1;32m"
# define P_YELLOW		"\033[1;33m"
# define P_BLUE			"\033[1;34m"
# define P_MAGENTA		"\033[1;35m"
# define P_CYAN			"\033[1;36m"
# define P_WHITE		"\033[1;38m"
# define P_BEIGE		"\033[1;38;5;229m"
# define P_BROWN		"\033[0;38;5;94m"
# define P_DARK_BLUE	"\033[0;38;5;17m"
# define P_DARK_GREY	"\033[0;38;5;238m"
# define P_CLEAR_SCREEN	"\1\033[2J\033[1;1H\2"

// # --------------------------------------------------- #
// # 					KEY-HOOKS						 #
// # --------------------------------------------------- #

# define ESCAPE_CROSS	0x0011
# define ESCAPE			0xff1b
# define W				0x0077
# define S				0x0073
# define A				0x0061
# define D				0x0064
# define Q				0x0071
# define E				0x0065
# define T				0x0074
# define G				0x0067
# define R				0x0072
# define F				0x0066
# define C				0x0063
# define P				0x0070
# define Y				0x0079
# define H				0x0068

# define ISO_ANGLE	0.523599
# define MOVE_STEP	20
# define SCALE_STEP	0.4
# define Z_STEP		0.01
# define ANGLE_STEP	0.1

// # define HEIGHT_MAX	500
// # define WIDTH_MAX	500
// # define DEPTH_MAX	500
// # define LEFT			0xff51
// # define UP				0xff52
// # define RIGHT			0xff53
// # define DOWN			0xff54
// # define I				0x0069
// # define O				0x006f
// # define M				0x006d
// # define U				0x0075
// # define X				0x0078
// # define Z				0x007a

# define P_EPS	0.0001

// refraction indices
# define VACUUM 1
# define AIR 1.00029
# define WATER 1.333
# define GLASS 1.52
# define DIAMOND 2.417

enum
{
	WINDOW_X = 1500,
	WINDOW_Y = 750,
	DEFAULT_WHITE = 0xFFFFFF,
	BLACK = 0x000000,
	BLUE = 0x0000FF,
	GREEN = 0x00FF00,
	RED = 0xFF0000,
	YELLOW = 0xFFFF00,
	TEAL = 0x008080,
	NAVY = 0x000080,
	PURPLE = 0x800080
};

#endif
