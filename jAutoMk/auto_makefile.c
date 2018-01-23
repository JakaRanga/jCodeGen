/*
** auto_makefile.c for my_automakefile in /home/jakaranga/delivery/AutoMakefile
** 
** Made by JakaRanga
** Login   <jeremy.bouton@epitech.eu>
** 
** Started on  Wed Mar 22 10:51:52 2017 JakaRanga
** Last update Mon Aug 21 15:12:57 2017 JakaRanga
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <dirent.h>

int	dot_h(char**);
int	my_strlen(char*);
int	my_strcmp(char*, char*);
char	*my_strcat(char*, char*);
char	*get_next_line(int);
char	**my_str_to_wordtab(char*, char);

void	put_error(int err)
{
  if (err == 1)
    printf("\033[31;40mError of malloc\033[00m\n");
  if (err == 2)
    printf("\033[31;40mError of open\033[00m\n");
}

char	*name_file(char *name)
{
  char	*res;
  int	i;
  int	a;

  i = -1;
  a = -1;
  while (name[++i] != '\0')
    if (name[i] == '/')
      a = i;
  if ((res = malloc(sizeof(char) * (my_strlen(name) - a + 1))) == NULL)
    return (put_error(2), NULL);
  i = 0;
  while (name[++a] != '\0')
    {
      res[i] = name[a];
      i++;
    }
  res[i] = '\0';
  return (res);
}

char	*add_libs(char *s, int *libs)
{
  if (libs[0] == 1 || libs[1] == 1 || libs[2] == 1)
    {
      if ((s = my_strcat(s, "LDFLAGS\t=\t-L./libs ")) == NULL)
	return (NULL);
      if (libs[0] == 1)
	{
	  if ((s = my_strcat(s, "-lptf ")) == NULL)
	    return (NULL);
	}
      if (libs[1] == 1)
	{
	  if ((s = my_strcat(s, "-lmy ")) == NULL)
	    return (NULL);
	}
      if (libs[2] == 1)
	{
	  if ((s = my_strcat(s, "-lgnl ")) == NULL)
	    return (NULL);
	}
      if ((s = my_strcat(s, "\n\n")) == NULL)
	return (NULL);
    }
  return (s);
}

int	auto_gen(char **av, int *libs, int mod)
{
  char	*s;
  int	fd;
  int	i;

  i = 1;
  open("Makefile", O_CREAT, S_IRWXU);
  if ((fd = open("Makefile", O_WRONLY)) == -1)
    return (put_error(2), 84);
  if ((s = malloc(sizeof(char) * 1)) == NULL)
    return (put_error(1), 84);
  s[0] = '\0';
  if ((s = my_strcat(s, "SRCS\t=\t")) == NULL)
    return (put_error(1), 84);
  while (av[++i] != NULL)
    {
      if ((s = my_strcat(s, av[i])) == NULL)
	return (put_error(1), 84);
      if (av[i + 1] != NULL)
	if ((s = my_strcat(s, "\t\t\\\n\t\t")) == NULL)
	  return (put_error(1), 84);
    }
  if (mod == 0)
    if ((s = my_strcat(s, "\n\nOBJS\t=\t$(SRCS:.c=.o)\n\n")) == NULL)
      return (put_error(1), 84);
  if (mod == 1)
    if ((s = my_strcat(s, "\n\nOBJS\t=\t$(SRCS:.cpp=.o)\n\n")) == NULL)
      return (put_error(1), 84);
  if ((s = my_strcat(s, "NAME\t=\t")) == NULL)
    return (put_error(1), 84);
  if ((s = my_strcat(s, av[1])) == NULL)
    return (put_error(1), 84);
  if (mod == 0)
    if ((s = my_strcat(s, "\n\nCC\t=\tgcc\n\n")) == NULL)
      return (put_error(1), 84);
  if (mod == 1)
    if ((s = my_strcat(s, "\n\nCC\t=\tg++\n\n")) == NULL)
      return (put_error(1), 84);    
  if (libs[3] == 1)
    if ((s = my_strcat(s, "CFLAGS\t=\t-Wall -Wextra -Werror\n\n")) == NULL)
      return (put_error(1), 84);
  if (mod == 0)
    if ((s = add_libs(s, libs)) == NULL)
      return (put_error(1), 84);
  if ((s = my_strcat(s, "$(NAME):\t$(OBJS)\n\t\t$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)\n\n")) == NULL)
    return (put_error(1), 84);
  if ((s = my_strcat(s, "all:\t\t$(NAME)\n\n")) == NULL)
    return (put_error(1), 84);
  if ((s = my_strcat(s, "re:\t\tfclean all\n\n")) == NULL)
    return (put_error(1), 84);
  if ((s = my_strcat(s, "clean:\n\t\trm -f $(OBJS)\n\n")) == NULL)
    return (put_error(1), 84);
  if ((s = my_strcat(s, "fclean:\t\tclean\n\t\trm -f $(NAME)\n\n")) == NULL)
    return (put_error(1), 84);
  if ((s = my_strcat(s, ".PHONY:\t\tall clean fclean re\n")) == NULL)
    return (put_error(1), 84);
  i = my_strlen(s);
  write(fd, s, i);
  free(s);
  return (printf("\033[32;40mMakefile created, just put your header in and add your own libs!\nMade by Jeremy BOUTON (Jaka)\033[00m\n"), 0);
}

int	is_name(char *s)
{
  int	i;

  i = -1;
  while (s[++i] != '\0')
    if (s[i] == '.' && s[i + 1] == 'c')
      return (84);
  return (0);
}

char	*get_name(char **env)
{
  int	i;
  int	j;
  int	line;
  char	*name;

  i = -1;
  line = -1;
  while (env[++i] != NULL)
    {
      if (env[i][0] == 'U' && env[i][1] == 'S' && env[i][2] == 'E' && env[i][3] == 'R')
	line = i;
    }
  if (line == -1)
    return ("USER");
  if ((name = malloc(sizeof(char) * my_strlen(env[line]))) == NULL)
    return (put_error(1), "USER");
  i = 5;
  j = 0;
  while (env[line][i] != '\0')
    {
      name[j] = env[line][i];
      j++;
      i++;
    }
  name[j] = '\0';
  return (name);
}

int	main(int ac, char **av, char **env)
{
  int	mod;
  char	*s;
  int	*libs;
  char	*tmp;

  mod = 0;
  if ((tmp = get_name(env)) == NULL)
    return (84);
  printf("\033[35;40mHello %s!\033[00m\n", tmp);
  free(tmp);
  if ((s = name_file(av[0])) == NULL)
    return (put_error(2), 84);
  if (ac < 3 || is_name(av[1]) == 84)
    return (printf("\033[32;40mUsage: ./%s [binary name] [files]\nMade by Jeremy BOUTON (Jaka)\033[00m\n", s), free(s), 0);
  else
    printf("Would is Make a C or C++ program ?\n");
  if ((s = get_next_line(0)) == NULL)
    return (put_error(2), 84);
  if (my_strcmp(s, "C++") == 0 || my_strcmp(s, "c++") == 0 || my_strcmp(s, "cpp") == 0)
    mod = 1;
  if ((libs = malloc(sizeof(int) * 4)) == NULL)
    return (84);
  libs[0] = 0, libs[1] = 0, libs[2] = 0, libs[3] = 0;
  printf("\033[34;01mWould you add libs?  (y / n)\033[00m\n");
  if (my_strcmp(get_next_line(0), "n") != 0)
    {
      if (mod == 0)
	{
	  printf("libptf.a (my_printf) ?\n (y / n)\n");
	  if (my_strcmp(get_next_line(0), "n") == 0)
	    libs[0] = -1;
	  else
	    libs[0] = 1;
	  printf("libmy.a ?\n (y / n)\n");
	  if (my_strcmp(get_next_line(0), "n") == 0)
	    libs[1] = -1;
	  else
	    libs[1] = 1;      
	  printf("libgnl.a ?\n (y / n)\n");
	  if (my_strcmp(get_next_line(0), "n") == 0)
	    libs[2] = -1;
	  else
	    libs[2] = 1;
	}
    }
  printf("Flags -Wall -Wextra -Werror ?\n (y / n)\n");
  if (my_strcmp(get_next_line(0), "n") == 0)
    libs[3] = -1;
  else
    libs[3] = 1;
  if (auto_gen(av, libs, mod) == 84)
    return (84);
  free(libs);
  return (0);
}
