#include "libargp.h"
 
/*******************************************************************************
*
* argp_parse - parsing command line parameters
*
*/

int argp_parse (int argc, char **argv, const char *shortopts, argp_parse_cb callback)
{
    int i;
    int ch;
    int first_argument = argc;

    /* get the first argument */

    for (i = 1; i < argc; i++) {
        if (argv[i][0] != '-') {
            first_argument = i;
            break;
        }
    }

    /* parsing the long parameters */

    optind = 0;
    while (1) {
        ch = getopt (first_argument, argv, shortopts);
        if (ch == -1) {
            break;
        }

        /* call the user callback function */

        if (callback != NULL) {
            (void) callback (ch, optarg);
        }
    }

    return first_argument;
}
