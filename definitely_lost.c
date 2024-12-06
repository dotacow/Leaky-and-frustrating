/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitely_lost.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 20:31:00 by abdsalah          #+#    #+#             */
/*   Updated: 2024/12/06 20:38:11 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bad_code.h"
    
int main() {
    char *ptr;

    ptr = malloc(12); // Allocate memory
    if (!ptr) {       // Always check if malloc succeeded
        perror("malloc failed");
        return 1;
    }
    strcpy(ptr, "this is bad"); // Copy the string
    ptr[11] = '\0';                  // Ensure null termination

    printf("%s\n", ptr);

    ptr = NULL; // Pointer overwritten, original memory lost
    return 0;   // Memory not freed
}
