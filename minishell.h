/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoizmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 22:29:23 by zoizmer           #+#    #+#             */
/*   Updated: 2021/12/05 22:29:25 by zoizmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include "libft/libft.h"

# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <signal.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>
//mine
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <errno.h>
# include <fcntl.h>
# include <string.h>
//endmine;
int				g_ret;

typedef struct s_cmd
{
	char			*cmd;
	char			**args;
	struct s_red	*redirections;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_red
{
	char			type;
	char			*arg;
	struct s_red	*next;
}	t_red;

typedef struct s_node {
	char			*name;
	char			*val;
	struct s_node	*next;
}	t_node;

typedef struct {
	int		i;
	char	*ret;
	char	*name;
	char	*val;
	char	*val2;
}	s_rp;

typedef struct s_fr {
	void		*name;
	struct s_fr	*next;
}	t_fr;

int		scan(char *str);
int		parse_and_exec(char *buf, t_node	*node);
t_cmd	*alloc_cmd_s(void);
t_red	*alloc_red_s(void);
int		end_of_delimiter(char *str);
void	subarg(int *r, int i, char *str, t_red *red);
int		sizelen(char *str, int ret, int i, int trig);
char	**splitargs(char	*str);
void	data_proc(t_cmd	*strct, t_node	*node);
char	*env_val(char	*name, t_node	*node);
void	free_null(void	*buff);
void	free_strct(t_cmd	*strct, t_red	*tmp, t_red	*tmp2, t_cmd	*tmp3);
void	free_node(t_node	*node);
char	*get_arg(char	*str, int	*r);
char	**copy_env(char	**env);
void	test_add(t_node	**head, char	*name, char	*val);
void	init_struct(char	**envp, t_node	**head);
char	*ft_strjoin1(char	*s1, char const	*s2);
void	*ft_memcpy1(void *dest, const void *src, size_t n);
char	*get_name(char	*str);
void	print_strct(t_cmd	*strct);
void	rm_quotes(t_cmd *srtct);
void	protection(t_cmd *node);
int		sizeoftab(char	**tab);
void	get_line(t_node *node);
//mine;
int		simple_non_builtin_cmd(t_cmd *strct);
int		ft_strcmp(char *s1, char *s2);
int		non_builtin_cmd(t_cmd *strct);
int		redirection_handler(t_cmd *strct);
void	builtins(t_cmd *strct, t_node *node);
void	excute_last_command(t_cmd *strct, t_node *env);
int		ft_excution(t_cmd *strct, t_node *node);
int		my_pwd(char **args, t_node *node);
int		my_env(char **args, t_node *node);
int		my_export(char **args, t_node *node);
int		my_unset(char **args, t_node *node);
int		my_echo(char **args, t_node *node);
int		my_exit(char **args, t_node *node);
int		my_cd(char **args, t_node *node);
char	*ft_get_path(char *bin, t_node *env);
int		ft_isdigit(int c);
int		is_num(char *str);
int		count_args(char **args);
char	*cut_equal(char *str);
int		check_cd_errors(char **args);
char	*add_char_beggin(char *str, char c, int f);
char	*add_char_end(char *str, char c, int f);
int		add_node(char *args, t_node *node);
int		node_exist(char *args, t_node *node, int i, t_node *new_node);
int		open_out_files(char type, char *arg);
char	**list_to_env(t_node *node);
char	*ft_strjoin_free(char *k, char *val);
t_node	*search_for_env(t_node	*tmp1, char *env);
char	*chage_derictory(char args[1], char *str);
void	ft_export_errors(char *identifier);
int		isvalid_var_unset(char *str);
int		isvalid_var_export(char *str);
void	ft_export_errors(char *identifier);
void	ft_unset_errors(char *identifier);
void	my_free_node(t_node *node);

#endif
