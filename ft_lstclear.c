/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 02:20:01 by dgiurgev          #+#    #+#             */
/*   Updated: 2023/10/29 16:56:45 by dgiurgev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/// @brief
/// @param lst
/// @param del
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next_lst;

	*next_lst = *lst;
	while (next_lst->next != NULL)
	{
		*next_lst = lst->next;
		del(lst-> content);
		free(lst);
	}
	del(lst-> content);
	free(lst);
	lst = NULL;
	return (lst);
}
