#include "debug.h"
#include "communication_profile.h"
#include <stdlib.h>

communication_profile_t * new_profile(){
	communication_profile_t * profile = (communication_profile_t *)malloc(sizeof(communication_profile_t));
	if(profile){
		profile->receive_request = profile_receive_request;
		profile->derived_obj = profile;
	}
	return profile;
}

void delete_profile(communication_profile_t * profile){
	free(profile);
}

void profile_receive_request(char * data){
	DEBUG_OK("[Transparent] %s [Transparent]", data);
}