/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   faulty_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 01:44:57 by abdsalah          #+#    #+#             */
/*   Updated: 2024/12/07 01:45:42 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bad_code.h"

//strace -e signal=SIGUSR1 ./faulty_handler
void handle_signal(int sig)
{
    printf("Handling signal: %d\n", sig);
}

int main()
{
    struct sigaction sa;

    // Forget to initialize sigaction structure, introducing a bug
    sa.sa_handler = handle_signal;

    // Install the handler for SIGUSR1
    if (sigaction(SIGUSR1, &sa, NULL) == -1)
    {
        perror("sigaction failed");
        return 1;
    }

    printf("Send SIGUSR1 to PID: %d\n", getpid());

    while (1)
        pause(); // Wait for signals

    return 0;
}
/*
Send kill -SIGUSR1 <PID> to the process.
Observe strace to confirm whether rt_sigaction is called and if the handler behaves correctly.
Fix the issue by initializing the sa struct properly:
memset(&sa, 0, sizeof(sa));
sa.sa_handler = handle_signal;

*/