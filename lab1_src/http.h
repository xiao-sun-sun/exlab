// http.h

#ifndef _HTTP_H_
#define _HTTP_H_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <direct.h>

#ifdef __cpluscplus
extern "C" {
#endif

char *http_process(char *request);

#ifdef __cpluscplus
}
#endif

#endif // _HTTP_H_
