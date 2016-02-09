/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 16:39:36 by pivanovi          #+#    #+#             */
/*   Updated: 2014/03/11 16:39:37 by pivanovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# define BUFFSIZE 1024

char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strcdup(const char *str, const char c);
int			ft_strclen(const char *str, const char c);
int			*fill_tab_i(int *tab, int val, int len);
int			get_next_line(int fd, char **line);
int			ft_strcmp(char *str1, char *str2);
char		**ft_strsplit(char *str, char c);
void		ft_zfill(char *thing, int len);
int			nb_this_arg(char *str, char c);
void		ft_putendl(const char *str);
void		ft_putstr(const char *str);
int			ft_strlen(const char *str);
int			ft_atoi(const char *str);
void		ft_putchar(const char c);
char		*del_space(char *str);
void		free_tab(char **tab);
int			nb_args(char *str);
void		ft_putnbr2(int n);
void		ft_putnbr(int n);

#endif
