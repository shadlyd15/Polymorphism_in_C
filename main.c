#include "debug.h"
#include "tcp_profile.h"
#include "hdlc_profile.h"
#include "communication_profile.h"

void generic_receive_ready(communication_profile_t * profile, char * data){
	profile->receive_request(data);
}

int main(int argc, char const *argv[]){
	DEBUG_OK("Test Started");
	communication_profile_t * tcp_profile = new_tcp_profile("192.168.1.112");
	communication_profile_t * hdlc_profile = new_hdlc_profile(80);

	tcp_profile->receive_request("DLMS Packet");
	hdlc_profile->receive_request("DLMS Packet");

	hdlc_profile_t * hdlc = hdlc_profile->derived_obj;
	DEBUG_OK("HDLC Port : %d", hdlc->port);

	tcp_profile_t * tcp = tcp_profile->derived_obj;
	DEBUG_OK("TCP Host : %s", tcp->host);

	generic_receive_ready(tcp_profile, "Packet");
	generic_receive_ready(hdlc_profile, "Packet");
	return 0;
}
