/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_problems.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:51:40 by abdsalah          #+#    #+#             */
/*   Updated: 2024/12/07 00:39:01 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bad_code.h"

void open_fd_leak()
{
    int fd = open("test.txt", O_RDONLY); // Open file descriptor
    if (fd == -1)
    {
        perror("open failed");
        return;
    }
    // File descriptor is not closed
    // Leak: FD remains open
}


void double_close()
{
    int fd = open("test.txt", O_RDONLY); // Open file descriptor
    if (fd == -1)
    {
        perror("open failed");
        return;
    }
    close(fd); // Close file descriptor
    close(fd); // Double close - undefined behavior
}

void invalid_fd()
{
    int fd = -1; // Invalid file descriptor
    write(fd, "Hello", 5); // Attempting to write - error
}


void use_after_close()
{
    int fd = open("test.txt", O_WRONLY | O_CREAT, 0644);
    if (fd == -1)
    {
        perror("open failed");
        return;
    }
    close(fd); // Close the file descriptor
    write(fd, "This is bad", 11); // Writing after close - error
}

int main(void)
{
    // use_after_close();
    // invalid_fd();
    // double_close();
    // open_fd_leak();
    return (0);
}