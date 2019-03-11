#ifndef TCP_PROFILE_H
#define TCP_PROFILE_H

#include <stdint.h>
#include "communication_profile.h"

typedef struct tcp_profile_t{
	uint8_t host[64];
}tcp_profile_t;

communication_profile_t * new_tcp_profile(char * host);
void delete_tcp_profile(communication_profile_t * profile);
void tcp_receive_request(char * data);

#endif // TCP_PROFILE_H