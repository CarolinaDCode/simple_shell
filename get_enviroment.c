#include "simpleshell.h"

/**
 *
 *
 *
 */

char *get_enviroment(char **env, char *comd)
{
	int i, c, len;
	char **new_env = NULL;
	char array_path[5];
	char *path_char, **path_dir;

	/*new_env = malloc(sizeof(char *) * (i + 1));

	if (new_env == NULL)
	perror("Error");*/

	for (i = 0; env[i] != NULL; i++)
	{
		for(c = 0; c < 4; c++)
			array_path[c] = env[i][c];

		if(_strcmp(array_path, "PATH") == 0 )
		{

			for (c = c + 1; env[i][c] != '\0'; c++)
				len++;
			path_char = malloc(sizeof(char) * len + 1);

			for (c = 5; env[i][c] != '\0'; c++)
				path_char[c-5] = env[i][c];

			path_char[c-5] = '\0';
			break;
		}
	}

	new_env = brokentoken(path_char, ":");
	return(get_dir_concat(new_env, comd));
}

/**
 *
 *
 *
 */
char *get_dir_concat(char **new_env, char* comd)
{
	char *dir_concat;
	int i;

        for (i = 0; new_env != NULL; i++)
        {
                dir_concat = _strdup(new_env[i]);
                dir_concat = _strcat(dir_concat, "/");
                dir_concat = _strcat(dir_concat, comd);
                if(access(dir_concat, X_OK) == 0)
                {
                        return(dir_concat);
                }
        }

}
