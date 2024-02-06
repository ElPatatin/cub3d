/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prs_file_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:58:40 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/02/06 16:19:27 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "cub3d_parser_private.h"
#include "cub3d_errors.h"

// ===============================PROTOTYPES===================================
static int	prs_file_trash(char **data);
static int	prs_file_header(char **data, t_file_data *file_data);
static int	prs_file_body(char **data, t_file_data *file_data);
static void	free_file_mem(char **data, t_file_data *file_data,
				const char *err_msg, int sys_code);
// ============================================================================

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
    status = prs_file_body(data, file_data);
    if (status == 1)
		free_file_mem(data, file_data, ERR_BAD_MAP, SYS_BAD_MAP);
    else if (status == 2)
        free_file_mem(data, file_data, ERR_MEM, SYS_MEM);
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

static int    	prs_file_header(char **data, t_file_data *file_data)
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
    file_data->metadata = (char **)ft_calloc(size + 1, sizeof(char *));
    if (!file_data->metadata)
        return (2);
    i = -1;
    while (data[++i])
    {
		if (get_metadata(data[i], metadata, file_data))
			return (2);
    }
    return (0);
}

static int	prs_file_body(char **data, t_file_data *file_data)
{
	ssize_t	i;
	ssize_t	j;
	size_t	size;

	size = 0;
	i = ft_strcount(data);
	if (get_body_size(data, i, &size))
		return (1);
	file_data->body = (char **)ft_calloc(size + 1, sizeof(char *));
	if (!file_data->body)
		return (2);
	while (--i != 0 && size != 0)
	{
		j = -1;
		while (data[i][++j] == ' ')
			;
		if (data[i][j] == '1' || data[i][j] == '0')
		{
			file_data->body[--size] = ft_strdup(data[i]);
			if (!file_data->body[size])
				return (2);
		}
	}
	return (FALSE);
}

static void	free_file_mem(char **data, t_file_data *file_data,
				const char *err_msg, int sys_code)
{
	if (data)
		ft_memfree(data);
	if (file_data)
	{
		if (file_data->metadata)
			ft_memfree(file_data->metadata);
		if (file_data->body)
			ft_memfree(file_data->body);
	}
    terminate_error(err_msg, sys_code);
}

