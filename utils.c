/*
** utils.c for push_swap in /home/sebastien/travaux/push_swap
**
** Made by Sebastien Chapuis
** Login   <sebastien@epitech.net>
**
** Started on  Sat Dec 21 21:19:58 2013 Sebastien Chapuis
** Last update Sun Jan  5 20:52:20 2014 Sebastien Chapuis
*/

#include <unistd.h>

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return ;
  while (str[i])
    write(1, &str[i++], 1);
}

int	my_atoi(char *str)
{
  int	i;
  int	negativ;
  int	number;

  i = 0;
  negativ = 0;
  number = 0;
  while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
         || (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
    i++;
  if (str[i] == 45)
    negativ = 1;
  if ((str[i] == 45) || (str[i] == 43))
    i++;
  while (str[i] >= 48 && str[i] <= 57)
  {
    number *= 10;
    number += ((int)str[i] - 48);
    i++;
  }
  if (negativ == 1)
    return (-number);
  else
    return (number);
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] || s2[i])
  {
    if (s1[i] == '\0' && s2[i] == '\0')
      return (0);
    if (s1[i] == '\0' || s2[i] == '\0')
      return (s1[i] - s2[i]);
    if (s1[i] != s2[i])
      return (s1[i] - s2[i]);
    i = i + 1;
  }
  return (0);
}

int	is_good_param(char *str, int *verbose, int *reverse)
{
  int	i;

  i = 0;
  if (str && str[0] == '-' && str[1] == 'v' && str[2] == 0)
  {
    *verbose = 1;
    return (0);
  }
  if (str && str[0] == '-' && str[1] == 'r' && str[2] == 0)
  {
    *reverse = 1;
    return (0);
  }
  while (str[i])
  {
    if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '-'))
    {
      my_putstr("Please enter numeric value: '");
      my_putstr(str);
      my_putstr("'\n");
      return (-1);
    }
    i = i + 1;
  }
  return (0);
}

int	usage(int argc, char **argv)
{
  int	i;
  int	is_help;

  i = 1;
  is_help = 0;
  while (i < argc)
  {
    if (my_strcmp(argv[i], "--help") == 0)
      is_help = 1;
    i = i + 1;
  }
  if (argc == 1)
    is_help = 1;
  if (is_help == 0)
    return (0);
  my_putstr("usage: ./push_swap [OPTION]... [NB1 NB2...]\n\n");
  my_putstr("\t-r      reverse sort\n");
  my_putstr("\t-v      print state of list each step\n");
  my_putstr("\t--help  print this message\n");
  return (1);
}
