/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.C                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <yseguin@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:52:56 by yseguin           #+#    #+#             */
/*   Updated: 2024/11/04 13:55:26 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/////////////////////////////////////////////////////////////////////////////
// Checks if a character is a digit
int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
