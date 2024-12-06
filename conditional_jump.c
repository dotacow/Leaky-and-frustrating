/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditional_jump.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:51:32 by abdsalah          #+#    #+#             */
/*   Updated: 2024/12/06 20:03:33 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bad_code.h"

typedef struct s_data {
    char *str1;
    char *str2;
} t_data;

void f(t_data data)
{
     // Use uninitialized members in a conditional statement
    if (data.str1) { // Conditional jump based on uninitialized value
        printf("str1 is not NULL\n");
    } else {
        printf("str1 is NULL\n");
    }

     if (data.str2) { // Conditional jump based on uninitialized value
        printf("str2 is not NULL\n");
    } else {
        printf("str2 is NULL\n");
    }
}

int main() {
    t_data data; // Struct declared but not initialized

    f(data);
    return 0;
}
