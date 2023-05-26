#include "header.h"


/**
 * handle_sigint - handle SIGINT signal
 *
 * @sig: signal value
 */
void handle_sigint(int sig)
{
	print_str("\n");
	shell_prompt();
	(void) sig;
}

/**
 * handle_sigquit - Signal handler for SIGQUIT (Ctrl+\)
 * @sig: Signal number
 *
 * Return: Nothing
 */
void handle_sigquit(int sig)
{
	(void) sig;
	print_str("Quit (core dumped)\n");
	exit(EXIT_SUCCESS);
}

/**
 * handle_sigstp - Signal handler for SIGTSTP (Ctrl+Z)
 * @sig: Signal number
 *
 * Return: Nothing
 */
void handle_sigstp(int sig)
{
	(void) sig;
	print_str("\n");
	shell_prompt();
}

