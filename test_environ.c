#include <stdio.h>
#include <string.h>

extern char **environ;

int _strlen(const char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

int _strncmp(const char *str1, const char *str2, size_t n) {
    for (size_t i = 0; i < n; i++) {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
    }
    return 0;
}

char *_getenv(char *var) {
    int idx, len;

    if (var == NULL)
        return NULL;

    len = _strlen(var);

    if (environ != NULL) {
        for (idx = 0; environ[idx]; idx++) {
            if (_strncmp(var, environ[idx], len) == 0 && environ[idx][len] == '=') {
                return (environ[idx] + len + 1);
            }
        }
    }

    return NULL;
}

int main() {
	int i;
    	char *path = _getenv("PATH");
  	for (i = 0; environ[i]; i++)
    		printf("%s\n", environ[i]);
   	 if (path != NULL) {
        	printf("Value of PATH: %s\n", path);
    	} else {
        	printf("PATH environment variable not found\n");
    	}
    	return 0;
}

