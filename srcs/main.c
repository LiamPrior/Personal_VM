/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 19:05:37 by lprior            #+#    #+#             */
/*   Updated: 2018/05/19 20:44:28 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int main(int argc, char **argv)
{
    uint8_t *code;
    STACK data;
    uint8_t *ip;
    instruction ops[256];
    
    if (argc != 2)
        usage();
    for (int i = 0; i < 256; i++)
        ops[i] = op_nop;
    ops['c'] = op_push_char;
    ops['e'] = op_emit;
    code = load_file(argv[1]);
    data = stack_new(1024);
    ip = code;
    while (*ip != 'h')
        ip = ops[*ip](ip, &data);
    return 0;
}