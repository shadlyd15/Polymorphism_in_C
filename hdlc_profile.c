#include "hdlc_profile.h"
#include "debug.h"
#include <stdlib.h>

communication_profile_t * new_hdlc_profile(uint32_t port){
	hdlc_profile_t * hdlc = (hdlc_profile_t*)malloc(sizeof(hdlc_profile_t));
	communication_profile_t * profile = new_profile();
	if(hdlc && profile){
		hdlc->port = port;
		profile->derived_obj = hdlc;
		profile->receive_request = hdlc_receive_request;
	}
	return profile;
}

void delete_hdlc_profile(communication_profile_t * profile){
	free(profile->derived_obj);
	free(profile);
}

void hdlc_receive_request(char * data){
	DEBUG_OK("<HDLC Header> %s </HDLC Footer>" , data);
}