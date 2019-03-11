#ifndef HDLC_H
#define HDLC_H

#include <stdint.h>
#include "communication_profile.h"

typedef struct hdlc_profile_t{
	uint32_t port;
}hdlc_profile_t;

communication_profile_t * new_hdlc_profile(uint32_t port);
void delete_hdlc_profile(communication_profile_t * profile);
void hdlc_receive_request(char * data);

#endif // HDLC_H