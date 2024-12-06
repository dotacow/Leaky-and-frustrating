/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitely_lost.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 00:21:12 by abdsalah          #+#    #+#             */
/*   Updated: 2024/12/07 00:27:46 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bad_code.h"

void definitely_lost()
{
    char *ptr;

    ptr = malloc(12); // Allocate memory
    if (!ptr)
    { // Always check if malloc succeeded
        perror("malloc failed");
        return;
    }
    strcpy(ptr, "this is bad"); // Copy the string
    ptr[11] = '\0';            // Ensure null termination
    printf("%s\n", ptr);
    ptr = NULL; // Pointer overwritten, original memory lost
    // Memory originally allocated is now inaccessible
}

void indirectly_lost()
{
    char **ptr = malloc(sizeof(char *) * 3); // Allocate memory for array of pointers
    if (!ptr)
    {
        perror("malloc failed");
        return;
    }

    ptr[0] = malloc(10); // Allocate memory for first string
    ptr[1] = malloc(10); // Allocate memory for second string
    ptr[2] = NULL;
    if (ptr[0])
        strcpy(ptr[0], "Hello");
    if (ptr[1])
        strcpy(ptr[1], "World");
    while (*ptr) {
        printf("%s\n", *ptr);
        ptr++;
    }
    free(ptr); // Freeing the outer pointer causes inner allocations to be lost
}

void still_reachable()
{
    static char *ptr;

    ptr = malloc(10); // Allocate memory
    if (!ptr)
    {
        perror("malloc failed");
        return;
    }

    strcpy(ptr, "123456789"); // Use the allocated memory
    printf("%s\n", ptr);
    // Memory is not freed, but it is still accessible at program termination
}

int main(void)
{
    // definitely_lost();
    indirectly_lost();
    // still_reachable();
    return 0; // Memory not properly freed in examples above
}
