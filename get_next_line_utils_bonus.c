/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuan <tyuan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 19:00:40 by tyuan             #+#    #+#             */
/*   Updated: 2020/06/05 12:01:37 by tyuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*cp;

	if (!(cp = malloc(sizeof(char) * (f_strlen(s1) + 1))))
		return (NULL);
	size = 0;
	while (s1 && s1[size])
	{
		cp[size] = s1[size];
		size++;
	}
	cp[size] = '\0';
	return (cp);
}

t_fdnl	*checkfd(t_fdnl *begin, int fd)
{
	while (begin)
	{
		if (fd == begin->ifd)
			return (begin);
		begin = begin->next;
	}
	return (NULL);
}

t_fdnl	*f_lstnew(int fd)
{
	t_fdnl	*new;

	if (!(new = malloc(sizeof(*new))))
		return (NULL);
	new->ifd = fd;
	new->iline = NULL;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_fdnl **alst, t_fdnl *new)
{
	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	while (alst && (*alst)->next)
		alst = &((*alst)->next);
	(*alst)->next = new;
}

void	del_istruct(t_fdnl **begin, t_fdnl **istruct)
{
	t_fdnl	*cur;
	t_fdnl	*next;

	if ((*begin)->ifd == (*istruct)->ifd)
	{
		*begin = (*istruct)->next;
		free(*istruct);
		return ;
	}
	next = *begin;
	while (next)
	{
		cur = next;
		next = cur->next;
		if (next->ifd == (*istruct)->ifd)
		{
			cur->next = (*istruct)->next;
			free(*istruct);
			return ;
		}
	}
}