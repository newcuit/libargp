#include <stdio.h>
#include <stdlib.h>
#include "libargp.h"
 
static char help[] =                                                   \
    "Usage: test [OPTION...] COMMAND [OPTION...]"                      \
    "\n    -h                 Give this help list\n"                   \
    ;

static int parse_opt
    (
    int         ch,
    char *      arg
    )
    {
    if (ch == 'h')
        {
        printf ("%s", help);
        exit (0);
        }

    (void) arg;

    return 0;
    }

int main (int argc, char **argv)
{
    int ret = 0;
    int first_argument;

    if (argc <= 1) {
        printf ("%s", help);
        exit (-1);
    }

    /* parsing optional parameters */

    first_argument = argp_parse (argc, argv, "h", parse_opt);
    if (first_argument == argc) {
        return ret;
    }

    /* call the command */

    // argv[first_argument] is the COMMAND
    if (first_argument < argc) {
        printf ("first argument is: %s\n", argv[first_argument]);
    }

    /* parse of subcommand */

    // for (i = 0; i < COMMAND_CNT;i++) {
    //      argv[first_argument].handle(argc - first_argument, argv + first_argument);
    // } 

    return ret;
}
