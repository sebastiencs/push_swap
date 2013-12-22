/*
** main.c for push_swap in /home/sebastien/travaux/push_swap
**
** Made by Sebastien Chapuis
** Login   <sebastien@epitech.net>
**
** Started on  Sat Dec 21 19:49:22 2013 Sebastien Chapuis
** Last update Sun Dec 22 12:07:53 2013 Sebastien Chapuis
*/

#include <stdlib.h>
#include "push_swap.h"

static int	search_min(t_list *root, int *min)
{
  t_list	*tmp;
  int		i;
  int		place;

  i = 0;
  tmp = root->next;
  *min = tmp->nb;
  place = 0;
  while (tmp != root)
  {
    if (tmp->nb < *min)
    {
      *min = tmp->nb;
      place = i;
    }
    i = i + 1;
    tmp = tmp->next;
  }
  return (place);
}

static int	put_all_in_a(t_list *root_a, t_list *root_b, int verbose)
{
  while (root_b->next != root_b)
  {
    if ((first_b_in_a(&root_a, &root_b)) == -1)
      return (-1);
    my_putstr((root_b->next != root_b) ? ("pa ") : ("pa"));
    if (verbose == 1)
      disp_list(root_a, root_b, (root_b->next != root_b) ? (0) : (1));
  }
  if (verbose == 0)
    write(1, "\n", 1);
  free_list(root_a);
  free_list(root_b);
  return (0);
}

static int	sort_a(t_list *root_a, t_list *root_b, int verbose)
{
  int		min_a;
  int		i;

  while (root_a->next != root_a)
  {
    i = search_min(root_a, &min_a);
    if (i >= (root_a->nb_elem / 2) && (root_a->nb_elem) != 1)
      while (i++ < root_a->nb_elem)
      {
	rotate_end(&root_a);
	(verbose == 1) ? (disp_list(root_a, root_b, 0)) : (0);
      }
    else
      while (i-- > 0)
      {
	rotate(&root_a);
	(verbose == 1) ? (disp_list(root_a, root_b, 0)) : (0);
      }
    if ((first_a_in_b(&root_a, &root_b)) == -1)
      return (-1);
    (verbose == 1) ? (disp_list(root_a, root_b, 0)) : (0);
  }
  return (0);
}

int		main(int argc, char **argv)
{
  t_list	*root_a;
  t_list	*root_b;
  int		verbose;
  int		i;

  i = 1;
  verbose = 0;
  if (usage(argc, argv) == 1)
    return (0);
  if ((init_roots(&root_a, &root_b)) == -1)
    return (-1);
  while (argv[i])
  {
    if (is_good_param(argv[i], &verbose) == -1)
      return (-1);
    if (argv[i][1] != 'v')
      if ((push_back(&root_a, my_atoi(argv[i]))) == -1)
	return (-1);
    i =  i + 1;
  }
  (verbose == 1) ? (disp_list(root_a, root_b, 0)) : (0);
  if ((sort_a(root_a, root_b, verbose)) == -1)
    return (-1);
  put_all_in_a(root_a, root_b, verbose);
  return (0);
}
