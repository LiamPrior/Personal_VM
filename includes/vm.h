/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 20:28:50 by lprior            #+#    #+#             */
/*   Updated: 2018/05/19 20:33:05 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <stdio.h>
# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct      OBJECT_t {
    uint8_t type;

    union
    {
        uint8_t     u8;
        int8_t      i8;
        uint32_t    u32;
        int32_t     i32;
        void        *ptr;
    };
}                   OBJECT;

typedef struct  STACK_t {
    int         top;
    int         size;
    OBJECT      *stack;
}               STACK;

typedef uint8_t * (*instruction)(uint8_t *, STACK *s);

/*
**operations.c
*/
uint8_t *op_nop(uint8_t *ip, STACK *s);
uint8_t *op_emit(uint8_t *ip, STACK *s);
uint8_t *op_push_char(uint8_t *ip, STACK *s);

/*
**error.c
*/
void usage(void);

/*
**stack.c
*/
OBJECT stack_peep(STACK *s);
OBJECT stack_pop(STACK *s);
int stack_push(STACK *s, OBJECT o);
STACK stack_new(int size);

/*
**open.c
*/
uint8_t *load_file(char *filename);

#endif
