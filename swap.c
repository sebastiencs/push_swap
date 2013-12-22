/*
** swap.c for push_swap in /home/sebastien/travaux/push_swap
**
** Made by Sebastien Chapuis
** Login   <sebastien@epitech.net>
**
** Started on  Sat Dec 21 21:07:11 2013 Sebastien Chapuis
** Last update Sun Dec 22 12:08:46 2013 Sebastien Chapuis
*/

#include <stdlib.h>
#include "push_swap.h"

int		first_b_in_a(t_list **root_a, t_list **root_b)
{
  t_list	*tmp;

  if ((push_front(root_a, (*root_b)->next->nb)) == -1)
    return (-1);
  tmp = (*root_b)->next;
  (*root_b)->next = (*root_b)->next->next;
  (*root_b)->nb_elem = (*root_b)->nb_elem - 1;
  free(tmp);
  return (0);
}

int		first_a_in_b(t_list **root_a, t_list **root_b)
{
  t_list	*tmp;

  if ((push_front(root_b, (*root_a)->next->nb)) == -1)
    return (-1);
  tmp = (*root_a)->next;
  (*root_a)->next = (*root_a)->next->next;
  (*root_a)->nb_elem = (*root_a)->nb_elem - 1;
  free(tmp);
  write(1, "pb ", 3);
  return (0);
}

void	rotate(t_list **root)
{
  (*root)->prec->next = (*root)->next;
  (*root)->next->prec = (*root)->prec;
  (*root)->prec = (*root)->next;
  (*root)->next = (*root)->prec->next;
  (*root)->prec->next = (*root);
  (*root)->next->prec = (*root);
  write(1, "ra ", 3);
}

void	rotate_end(t_list **root)
{
  (*root)->prec->next = (*root)->next;
  (*root)->next->prec = (*root)->prec;
  (*root)->next = (*root)->prec;
  (*root)->prec = (*root)->prec->prec;
  (*root)->prec->next = (*root);
  (*root)->next->prec = (*root);
  write(1, "rra ", 4);
}
