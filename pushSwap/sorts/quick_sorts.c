/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseguin <youvataque@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:34:47 by yseguin           #+#    #+#             */
/*   Updated: 2024/12/16 13:03:55 by yseguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

///////////////////////////////////////////////////////////////////////////////
// swap two value position in memory
void	swap_val(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

///////////////////////////////////////////////////////////////////////////////
// split tab in two part using pivot
int	partition(int array[], int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = array[high];
	i = (low - 1);
	j = low;
	while (j < high)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap_val(&array[i], &array[j]);
		}
		j++;
	}
	swap_val(&array[i + 1], &array[high]);
	return (i + 1);
}

///////////////////////////////////////////////////////////////////////////////
// sort a tab of int
void	quick_sort(int array[], int low, int high)
{
	int	pivot;

	if (low < high)
	{
		pivot = partition(array, low, high);
		quick_sort(array, low, pivot - 1);
		quick_sort(array, pivot + 1, high);
	}
}
