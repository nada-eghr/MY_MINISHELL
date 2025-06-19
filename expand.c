/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naessgui <naessgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:53:48 by naessgui          #+#    #+#             */
/*   Updated: 2025/06/19 22:21:22 by naessgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"minishell.h"


char *get_value(char *str, t_env_list *env)
{
    t_env_list *tmp ;
    
    tmp = env;
    str++;
    while (tmp->next)
    {
        //  printf("key = %s \n", tmp->content.key);
        //  printf("token = %s \n", str);
        if (!ft_strcmp(str,tmp->content.key)){
            // printf("value = %s \n", tmp->content.value);
            return(tmp->content.value);
        }
        tmp = tmp->next;
    }
    return NULL;
    
}
t_token *expand_token(t_token *token , t_env_list *env)
{
    t_token *tmp;
    tmp = token;
    char *new_data;
    // while(env->next){
	// 	printf("key %s ->",env->content.key);
	// 	printf("value = %s \n", env->content.value);
	// 	env = env->next;
	// }
    while ( tmp )
    {
        if (tmp->type == TOKEN_ENV_VAR)
        {
            new_data = get_value(tmp->token , env);
            printf("new_data = %s\n",new_data);
            free(tmp->token);
            if (new_data)
                tmp->token = ft_strdup(new_data);
            else
                tmp->token = ft_strdup("hjjkdd");
            
        }
        tmp = tmp->next;
    }
    return (token);
}