#include <click/config.h>
#include <click/args.hh>
#include <click/confparse.hh>
#include <click/error.hh>
#include <click/timer.hh>
#include "PacketACK.hh"
#include "packetss.hh"

CLICK_DECLS

PacketACK::PacketACK() {}
PacketACK::~PacketACK() {}

int PacketACK::configure(Vector<String> &, ErrorHandler *) {
	return 0;
}

void PacketACK::push(int, Packet *p) {
	p_t *h = (p_t *)p->data();
	if(h->type == 0){
		WritablePacket *packet = Packet::make(0, 0, sizeof(p_t), 0);
		p_t *header = (p_t *)packet->data();
		header->type = 1;
		header->cur_sequence = h->cur_sequence;
		output(0).push(packet);
		return;
	}
}

CLICK_ENDDECLS

EXPORT_ELEMENT(PacketACK)