/*
** disp.c for push_swap in /home/sebastien/travaux/push_swap
**
** Made by Sebastien Chapuis
** Login   <sebastien@epitech.net>
**
** Started on  Sun Dec 22 11:34:13 2013 Sebastien Chapuis
** Last update Sun Dec 22 11:56:25 2013 Sebastien Chapuis
*/

#include <unistd.h>
#include "push_swap.h"

static void	my_putchar(char c)
{
  write(1, &c, 1);
}

static void	my_putnbr(int nb)
{
  if (nb < 0)
  {
    my_putchar('-');
    nb = -(nb);
  }
  if (nb >= 10)
    my_putnbr(nb / 10);
  my_putchar((nb % 10) + '0');
}

static void	disp_root(t_list *root)
{
  t_list	*tmp;

  tmp = root->next;
  while (tmp != root)
  {
    my_putnbr(tmp->nb);
    if (tmp->next != root)
      my_putchar(' ');
    tmp = tmp->next;
  }
}
/* static void	disp_a(t_list *root_a) */
/* { */
/*   t_list	*tmp; */

/*   tmp = root_a->next; */
/*   while (tmp != root_a) */
/*   { */
/*     my_putnbr(tmp->nb); */
/*     if (tmp->next != root_a) */
/*       my_putchar(' '); */
/*     tmp = tmp->next; */
/*   } */
/* } */

/* static void	disp_b(t_list *root_b) */
/* { */
/*   t_list	*tmp; */

/*   tmp = root_b->next; */
/*   while (tmp != root_b) */
/*   { */
/*     my_putnbr(tmp->nb); */
/*     if (tmp->next != root_b) */
/*       my_putchar(' '); */
/*     tmp = tmp->next; */
/*   } */
/* } */

void		disp_list(t_list *root_a, t_list *root_b, int is_last)
{
  static int	is_first;

  my_putstr((is_first++ == 0) ? ("l_a ") : ("\nl_a "));
  disp_root(root_a);
  my_putstr("\n");
  my_putstr("l_b ");
  disp_root(root_b);
  my_putstr((is_last == 0) ? ("\n\n") : ("\n"));
}
