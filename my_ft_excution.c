#include "minishell.h"


int non_builtin_cmd(t_cmd *strct)
{
	if(ft_strncmp(strct->cmd ,"exit",4) || ft_strncmp(strct->cmd, "export", 6)\
	 || ft_strncmp(strct->cmd, "env", 3) || ft_strncmp(strct->cmd, "pwd", 3) ||\
	ft_strncmp(strct->cmd, "cd", 2) || ft_strncmp(strct->cmd, "unset", 5) ||\
	 ft_strncmp(strct->cmd, "echo", 4))
		return(0);
	else
		return(1);
}

void redirection_handler(t_cmd *strct)
{
	int num_red;
	t_red *tmp;
	//int *fd;
	
	num_red = 0;
	tmp = strct->redirections;
	while(strct->redirections->next != NULL)
	{
		num_red++;
		tmp = tmp->next;
	}
	while(num_red-- > 1)
	{
		open(strct->redirections->arg,O_RDONLY);
	}
	
}

void builtins(t_cmd *strct,t_node *node)
{
	char *builtins_names[7] =  {"cd","pwd","env","export","unset","echo","exit"};// norme 
	int (*builtins_functions[7]) (char **,t_node *) = {&my_cd,&my_pwd,&my_env, &my_export, &my_unset, &my_echo, &my_exit};
	int i;

	i = 0;
	while(i < 7)
	{
		if(*builtins_names[i] == strct->cmd)
		{
			builtins_functions[i](strct->args, node);
		}
		i++;
	}
}

void ft_excution(t_cmd *strct, t_node *node,char **env)
{
	 int pid;
	// int i;
	int fd[2];

	// if (simple_non_builtin_cmd())
	// 	execute_non_builtin();
	// while (strct->next)
	// {
	// 	int fd[2];
	// 	pipe(fd);

	// 	int id = fork();
	// 	if (id == 0)
	// 	{
	// 		dup2(); //
	// 		ft_redirection();
	// 		check_builtin(); // if (cmd == echo) echo(args)  || cmd == ...) 
	// 		non_builtin(); //execve
	// 	}
	// 	final_cmd();
	// 	strct = strct->next;
	
	//}
	if(non_builtin_cmd(strct) && strct->next == NULL)
	{
		redirection_handler(strct);//not defined yet;
		execve(strct->cmd,strct->args,env);
	}
	while(strct->next != NULL)
	{
		redirection_handler(strct);
		int fd_out = open(name, O_CREAT | O_RDONLY | O_TRUNC);
		int fd_int = open(name, O_CREAT | O_RDONLY | O_TRUNC);

		if(pipe(fd) < 0)
			return(1);
		if(pid = fork() < 0)
			return(1);
		if(pid == 0)
		{
			if(fd_out != -1)
				dup2(fd_out, 1);
			if(fd_out == -1)
				close(fd_out);
			if()
				dup2(fd_int, 0);
			if()

			//pipes should be treated here somehow;
			if(non_builtin_cmd(strct) && strct->next == NULL)
			{
				redirection_handler(strct);//not defined yet;
				execve(strct->cmd,strct->args,env);//should i search for the path of the command;
				exit(0);
			}
			else
				builtins(strct,node);
		}
}

while(cmd)
{
	int fd[2];
	int f = -1;
	pipe(fd);
	fork;
	if(pid == 0)
	{
		if(ila makanch how akhir comd)
			dup2(fd[1],1);
		if (f != -1)
			dup2(f, 0);
		close(fd[0]);
		exuction;
	}
	else
	[
		f = fd[0];
		close(fd[1]);
	]
}