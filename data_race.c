/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_race.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsalah <abdsalah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 02:14:09 by abdsalah          #+#    #+#             */
/*   Updated: 2024/12/07 02:15:23 by abdsalah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bad_code.h"

int counter = 0;

void *increment() {
    for (int i = 0; i < 1000000; i++) {
        counter++; // Data race
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Counter: %d\n", counter);
    return 0;
}
