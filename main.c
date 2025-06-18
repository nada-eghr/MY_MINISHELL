/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naessgui <naessgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:27:48 by naessgui          #+#    #+#             */
/*   Updated: 2025/06/18 15:58:48 by naessgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>

int	main(void)
{
	// atexit(ll);
	while (1)
	{
		char *input = readline("minishell$ ");
		add_history(input);
		t_token *tokens = convert_to_node(input);
		if (!tokens)
		{
			free(tokens);
			continue;
		}
		if (check_error(&tokens) == 1)
		{
			// printf("minishell : syntax error"); /*free*/
			free_list(tokens);
			continue;
		}
		t_cmd *cmd = list_cmd(tokens);
		print_cmd(cmd);
		if (!tokens)
		{
			free(tokens);
			continue;
		}
		if (check_error(&tokens) == 1)
		{
			// printf("minishell : syntax error"); /*free*/
			free_list(tokens);
			exit(1);
			continue;
		}
		// t_cmd *cmd = convert_to_cmd(&tokens)
		//------------
		t_token *current = tokens;

		while (current)
		{
			printf("{token -> %s } ", current->token);
			printf("{type -> %d } ", current->type);
			current = current->next;
		}
		printf("\n");

		printlinkedlist(tokens);

		// Free memory if needed
		free_list(tokens);
	}
	return (0);
}
