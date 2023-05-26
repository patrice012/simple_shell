#include "main.h"

/**
 * _help - displays help information for built-in commands
 * Return: 0 for success and 1 for failure
 */
int _help(void)
{
	print_str("\nALX Simple Shell\n\n");
	print_str("Usage: ./hsh for interactive mode\n\n");
	print_str("Usage: commands | ./hsh for non-interactive mode\n\n");
	print_str("Shell built-in commands:\n\n");
	print_str("help\t\tDisplay this help information\n\n");
	print_str("cd [dir]\tChange the current working directory\n\n");
	print_str("env\t\tDisplay the environment variables\n\n");
	print_str("setenv\t\tSet an environment variable\n\n");
	print_str("unsetenv\tUnset an environment variable\n\n");
	print_str("exit\t\tExit the shell\n\n");
	return (0);
}
