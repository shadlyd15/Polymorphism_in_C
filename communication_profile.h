#ifndef COMMUNICATION_PROFILE_H
#define COMMUNICATION_PROFILE_H

typedef void (*fptr_receive_request)(char * data);

typedef struct communication_profile_t{
	void * derived_obj;
	fptr_receive_request receive_request;
}communication_profile_t;

communication_profile_t * new_profile();
void delete_profile(communication_profile_t * profile);
void profile_receive_request(char * data);

#endif // COMMUNICATION_PROFILE_H