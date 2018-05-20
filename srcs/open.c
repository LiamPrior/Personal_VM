/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 20:26:58 by lprior            #+#    #+#             */
/*   Updated: 2018/05/19 21:03:57 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

uint8_t *load_file(char *filename)
{
    FILE *f;
    uint8_t *code = NULL;
    struct stat st;

    if ((f = fopen(filename, "r")))
    {
        fstat(fileno(f), &st);
        code = (uint8_t *)malloc(st.st_size);
        fread((void*)code, 1, st.st_size, f);
    }
    else
    {
        printf("Error: Invalid file\n");
        usage();
    }
    return (code);
}