/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_overflow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:52:01 by abdsalah          #+#    #+#             */
/*   Updated: 2024/12/06 20:11:05 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bad_code.h"

int f()
{
    int x;

    x = 1;
    if (x == -1)
        return (1);
    return (x + f());
}
int main(void)
{
    f();
}