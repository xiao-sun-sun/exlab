// tcp.h

#ifndef _TCP_H_
#define _TCP_H_

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")

#include "http.h"

#define RECV_BUFFER_LENGTH (4096)
#define BACKLOG_LENGTH (256)

#ifdef __cpluscplus
extern "C" {
#endif

void sig_handler(int sig);
int tcp();

#ifdef __cpluscplus
}
#endif

#endif // _TCP_H_
