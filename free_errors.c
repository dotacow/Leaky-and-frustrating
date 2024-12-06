/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:51:44 by abdsalah          #+#    #+#             */
/*   Updated: 2024/12/07 00:50:32 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bad_code.h"

void double_free()
{
    char *ptr = malloc(20); // Allocate memory
    if (!ptr)
    {
        perror("malloc failed");
        return;
    }

    free(ptr); // Free the memory
    free(ptr); // Double free - undefined behavior
}

void invalid_free()
{
    int num = 5; // Local variable
    free(&num);  // Invalid free - `num` is not dynamically allocated
}

void never_allocated_free()
{
    char *ptr;  // Uninitialized pointer
    free(ptr);  // Freeing memory that was never allocated
}

void free_part_of_block()
{
    char *ptr = malloc(20); // Allocate memory
    if (!ptr)
    {
        perror("malloc failed");
        return;
    }

    ptr[5] = 'A'; // Use part of the memory block
    free(ptr + 5); // Free part of the allocated memory (incorrect)
}

void use_after_free()
{
    char *ptr = malloc(20); // Allocate memory
    if (!ptr)
    {
        perror("malloc failed");
        return;
    }

    free(ptr);  // Free the memory
    *ptr = 'A'; // Accessing memory after it's freed - undefined behavior
}

void free_null_pointer()
{
    char *ptr = NULL;  // Pointer is NULL
    free(ptr);  // Safe but not needed
}

int main(void)
{
    free_null_pointer();
    free_part_of_block();
    use_after_free();
    invalid_free();
    never_allocated_free();
    double_free();
    return 0;
}