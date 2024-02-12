/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deg_to_rad.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:34:56 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/12 12:36:30 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
//#define M_PI   3.14159265358979323846264338327950288

#define INV_180 0.00555555
#define DEG_TO_RAD 0.0174533

//float degToRad(int a) { return a * M_PI * INV_180;}

float degToRad(int a)
{
	return ((float)a * M_PI * INV_180);
}

