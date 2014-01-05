/*
** push_swap.h for push_swap in /home/sebastien/travaux/push_swap
**
** Made by Sebastien Chapuis
** Login   <sebastien@epitech.net>
**
** Started on  Sat Dec 21 19:51:36 2013 Sebastien Chapuis
** Last update Sun Jan  5 21:32:35 2014 Sebastien Chapuis
*/

typedef struct	s_list
{
  int		nb;
  int		nb_elem;
  struct s_list	*prec;
  struct s_list	*next;
}		t_list;

int	push_back(t_list **list, int nb);
int	push_front(t_list **list, int nb);
int	my_atoi(char *str);
void	swap_two_first(t_list **root, char c);
void	my_putstr(char *str);
int	first_b_in_a(t_list **root_a, t_list **root_b);
int	first_a_in_b(t_list **root_a, t_list **root_b, int verbose,
		     int reverse);
void	swap_two(t_list **root_a, t_list **root_b);
void	rotate(t_list **root, int verbose);
void	rotate_end(t_list **root, int verbose);
int	init_roots(t_list **root_a, t_list **root_b);
void	disp_list(t_list *root_a, t_list *root_b, int is_last, int reverse);
void	free_list(t_list *root);
int	is_sort(t_list *root, int reverse);
int	is_good_param(char *str, int *verbose, int *reverse);
