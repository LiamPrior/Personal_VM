/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 20:25:25 by lprior            #+#    #+#             */
/*   Updated: 2018/05/19 20:44:40 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

STACK stack_new(int size)
{
    STACK s;
    s.top = 0;
    s.size = size;
    s.stack = (OBJECT *)malloc(sizeof(OBJECT) * size);
    return s;
}

int stack_push(STACK *s, OBJECT o)
{
    s->stack[s->top++] = o;
    return s->top;
}

OBJECT stack_pop(STACK *s)
{
    return (s->stack[--(s->top)]);
}

OBJECT stack_peep(STACK *s)
{
    return (s->stack[s->top - 1]);
}
