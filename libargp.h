#ifndef __argparse_h
#define __argparse_hh

#include <unistd.h>

#ifdef __cplusplus
extern "C" {
#endif

/* defines */

typedef int (*argp_parse_cb) (int, char *);

/* parsing command line parameters */

int argp_parse (int argc, char ** argv, const char * shortopts, argp_parse_cb callback);

#ifdef __cplusplus
}
#endif

#endif /* __argparse_h */
