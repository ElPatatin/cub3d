/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:16:44 by alajara-          #+#    #+#             */
/*   Updated: 2024/02/01 17:19:05 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// Al
int parse(char **raw_info) // TODO: return struct with main information.
{
	if (prs_map(&raw_info))
		return (2);
	if (prs_txt(raw_info))
		return (3);
	if (prs_clr(raw_info))
		return (4);
}
