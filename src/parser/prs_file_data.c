/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_file_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:58:40 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/05 13:19:56 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_parser_private.h"
#include "cub3d_errors.h"

static int	prs_file_trash(char **data);
static int	prs_file_header(char **data, t_file_data *file_data);
// static int	prs_file_body(char **data, t_file_data *file_data);
static void	free_file_mem(char **data, t_file_data *file_data,
				char *err_msg, int sys_code);

int prs_file_data(char **data, t_file_data *file_data)
{
    int status;

	if (prs_file_trash(data))
		free_file_mem(data, NULL, ERR_INV_DTA, SYS_INV_DTA);
    status = prs_file_header(data, file_data);
    if (status == 1)
        free_file_mem(data, file_data, ERR_HDR_MIS, SYS_HDR_MIS);
    else if (status == 2)
        free_file_mem(data, file_data, ERR_MEM, SYS_MEM);
    else if (status == 3)
        free_file_mem(data, file_data, ERR_HDR_DUP, SYS_HDR_DUP);
    // status = prs_file_body(data, file_data);
    // if (status == 1)
    //     ;
    // else if (status == 2)
    //     free_file_mem(data, file_data, ERR_MEM, SYS_MEM);
    return (status);
}

static int	prs_file_trash(char **data)
{
	ssize_t	i;
	ssize_t	j;

	i = -1;
	while (data[++i])
	{
		if (check_metadata(data[i]))
		   	continue;
		else if (data[i][0] == '\0' || data[i] == NULL)
			continue;
		else
		{
			j = -1;
			while (data[i][++j] == ' ')
				;
			if (data[i][j] == '1' || data[i][j] == '0')
				continue;
		}
		return (TRUE);
	}
	return (FALSE);
}

static int    prs_file_header(char **data, t_file_data *file_data)
{
    ssize_t	i;
    ssize_t	size;
    char	*metadata[MIN_HEADER + 1];

    built_valid_metadata(metadata);
	if (duplicated_metadata(data, metadata))
		return (3);
    size = get_metadata_size(data, metadata);
    if (size < 0)
        return (1);
    file_data->metadate = (char **)ft_calloc(size + 1, sizeof(char *));
    if (!file_data->metadate)
        return (2);
    i = -1;
    while (data[++i])
    {
		if (get_metadata(data[i], metadata, file_data))
			return (2);
    }
    return (0);
}

// static int	prs_file_body(char **data, t_file_data *file_data)
// {
// 	UNUSED(data);
// 	UNUSED(file_data);
// 	return (FALSE);
// }

static void	free_file_mem(char **data, t_file_data *file_data,
				char *err_msg, int sys_code)
{
	if (data)
		ft_memfree(data);
	if (file_data)
	{
		if (file_data->metadate)
			ft_memfree(file_data->metadate);
		if (file_data->body)
			ft_memfree(file_data->body);
	}
    terminate_error(err_msg, sys_code);
}

