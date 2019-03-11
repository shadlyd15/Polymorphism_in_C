#include "tcp_profile.h"
#include "debug.h"
#include <stdlib.h>
#include <string.h>

communication_profile_t * new_tcp_profile(char * host){
	tcp_profile_t * tcp = (tcp_profile_t*)malloc(sizeof(tcp_profile_t));
	communication_profile_t * profile = new_profile();
	if(tcp && profile){
		memcpy(tcp->host, host, strlen(host));
		profile->derived_obj = tcp;
		profile->receive_request = tcp_receive_request;
	}
	return profile;
}

void delete_tcp_profile(communication_profile_t * profile){
	free(profile->derived_obj);
	free(profile);
}

void tcp_receive_request(char * data){
	DEBUG_OK("<TCP Header> %s </TCP Footer>" , data);
}