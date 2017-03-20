/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdardakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:04:34 by mdardakh          #+#    #+#             */
/*   Updated: 2016/12/05 17:40:44 by mdardakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIECE_H
# define PIECE_H

char g_pieces[19][4][4] =
{
	{
		{'#', '#', '.', '.'},
		{'#', '#', '.', '.'},
		{'.', '.', '.', '.'},
		{'.', '.', '.', '.'}
	},
	{
		{'#', '#', '#', '#'},
		{'.', '.', '.', '.'},
		{'.', '.', '.', '.'},
		{'.', '.', '.', '.'}
	},
	{
		{'#', '.', '.', '.'},
		{'#', '.', '.', '.'},
		{'#', '.', '.', '.'},
		{'#', '.', '.', '.'}
	},
	{
		{'#', '.', '.', '.'},
		{'#', '.', '.', '.'},
		{'#', '#', '.', '.'},
		{'.', '.', '.', '.'}
	},
	{
		{'.', '.', '#', '.'},
		{'#', '#', '#', '.'},
		{'.', '.', '.', '.'},
		{'.', '.', '.', '.'}
	},
	{
		{'#', '#', '.', '.'},
		{'.', '#', '.', '.'},
		{'.', '#', '.', '.'},
		{'.', '.', '.', '.'}
	},
	{
		{'#', '#', '#', '.'},
		{'#', '.', '.', '.'},
		{'.', '.', '.', '.'},
		{'.', '.', '.', '.'}
	},
	{
		{'.', '#', '.', '.'},
		{'.', '#', '.', '.'},
		{'#', '#', '.', '.'},
		{'.', '.', '.', '.'}
	},
	{
		{'#', '#', '#', '.'},
		{'.', '.', '#', '.'},
		{'.', '.', '.', '.'},
		{'.', '.', '.', '.'}
	},
	{
		{'#', '#', '.', '.'},
		{'#', '.', '.', '.'},
		{'#', '.', '.', '.'},
		{'.', '.', '.', '.'}
	},
	{
		{'#', '.', '.', '.'},
		{'#', '#', '#', '.'},
		{'.', '.', '.', '.'},
		{'.', '.', '.', '.'}
	},
	{
		{'.', '#', '#', '.'},
		{'#', '#', '.', '.'},
		{'.', '.', '.', '.'},
		{'.', '.', '.', '.'}
	},
	{
		{'#', '.', '.', '.'},
		{'#', '#', '.', '.'},
		{'.', '#', '.', '.'},
		{'.', '.', '.', '.'}
	},
	{
		{'#', '#', '.', '.'},
		{'.', '#', '#', '.'},
		{'.', '.', '.', '.'},
		{'.', '.', '.', '.'}
	},
	{
		{'.', '#', '.', '.'},
		{'#', '#', '.', '.'},
		{'#', '.', '.', '.'},
		{'.', '.', '.', '.'}
	},
	{
		{'.', '#', '.', '.'},
		{'#', '#', '#', '.'},
		{'.', '.', '.', '.'},
		{'.', '.', '.', '.'}
	},
	{
		{'#', '.', '.', '.'},
		{'#', '#', '.', '.'},
		{'#', '.', '.', '.'},
		{'.', '.', '.', '.'}
	},
	{
		{'#', '#', '#', '.'},
		{'.', '#', '.', '.'},
		{'.', '.', '.', '.'},
		{'.', '.', '.', '.'}
	},
	{
		{'.', '#', '.', '.'},
		{'#', '#', '.', '.'},
		{'.', '#', '.', '.'},
		{'.', '.', '.', '.'}
	}
};
#endif
