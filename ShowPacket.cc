#include <click/config.h>
#include <click/args.hh>
#include <click/confparse.hh>
#include <click/error.hh>
#include <click/timer.hh>
#include "ShowPacket.hh"
#include "packetss.hh"

CLICK_DECLS

ShowPacket::ShowPacket() {}
ShowPacket::~ShowPacket() {}

int ShowPacket::configure(Vector<String> &, ErrorHandler *) {
	return 0;
}

void ShowPacket::push(int, Packet *p) {
	p_t *header = (p_t *)p->data();
	click_chatter("The packet header is: %d", header->type);
	click_chatter("The packet sequence is: %d", header->cur_sequence);
	output(0).push(p);
	return;
}

CLICK_ENDDECLS

EXPORT_ELEMENT(ShowPacket)