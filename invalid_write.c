/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:51:53 by abdsalah          #+#    #+#             */
/*   Updated: 2024/12/06 20:07:14 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bad_code.h"

void	f(void)
{
	int	*x;

	x = malloc(10 * sizeof(int));
	x[10] = 0; // problem 1: heap block overrun
} // problem 2: memory leak -- x not freed

int	main(void)
{
	f();
	return (0);
}
