/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 01:04:32 by abdsalah          #+#    #+#             */
/*   Updated: 2024/12/07 01:05:55 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bad_code.h"

// This example demonstrates a program that sets up handlers for signals
// like SIGINT and SIGTERM. You can use strace to verify if the signals are caught or ignored.
void handle_signal(int sig)
{
    if (sig == SIGINT)
        printf("Caught SIGINT (Ctrl+C), exiting gracefully.\n");
    else if (sig == SIGTERM)
        printf("Caught SIGTERM, shutting down.\n");
    exit(0);
}

int main()
{
    // Set up signal handlers
    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);

    printf("Signal handler set up. PID: %d\n", getpid());
    printf("Press Ctrl+C or send SIGTERM to terminate.\n");

    while (1)
        pause(); // Wait for signals

    return 0;
}
/*
Use kill -SIGINT <PID> or kill -SIGTERM <PID> in another terminal to send signals.
Observe strace output to verify signal delivery.
*/