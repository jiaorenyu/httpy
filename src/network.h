#ifndef __NETWORK_H_
#define __NETWORK_H_

int init_socket(int, const struct sockaddr *, socklen_t, int);
int init_server(int);
void serve(int);
#endif
