#include <click/config.h>
#include <click/args.hh>
#include <click/confparse.hh>
#include <click/error.hh>
#include <click/timer.hh>
#include "PacketGen.hh"
#include "packetss.hh"

CLICK_DECLS

PacketGen::PacketGen() : _timer(this), ACK(1), cur_loop(0) {}
PacketGen::~PacketGen() {}

int PacketGen::configure(Vector<String> &conf, ErrorHandler *errh) {
	if (cp_va_kparse(conf, this, errh,
						"DATA", cpkP+cpkM, cpString, &payloadData,
						cpEnd) < 0) return -1;
	_timer.initialize(this);
	_timer.schedule_after_msec(100);
	return 0;
}

int PacketGen::initialize(ErrorHandler *) {
	_timer.initialize(this);
	_timer.schedule_after_sec(1);
	return 0;
}

void PacketGen::run_timer(Timer *) {
	//This function is called when the timer fires
//	Timestamp now = Timestamp::now();
//	click_chatter("%s: %{timestamp}: timer fired!\n", declaration().c_str(), &now);

	if(ACK == 1){
		click_chatter("sequence %d packet sending", cur_loop + 1);
		cur_loop++;
		this->sendRequest();//change parameter as ACK received?
		ACK = 0;
		_timer.reschedule_after_sec(2);
	}
	
	else if(ACK == 0){
		click_chatter("sequence %d ACK not received, send it again\n", cur_loop);
		this->sendRequest();
		_timer.reschedule_after_sec(2);
	}
}

void PacketGen::sendRequest() {
//	click_chatter("Sending data! ");
	WritablePacket *packet = Packet::make(0, 0, sizeof(p_t) + payloadData.length(), 0);
	p_t *header = (p_t *)packet->data();
	header->type = 0;
	header->cur_sequence = cur_loop;
	header->payload = "hello";
	output(0).push(packet);
}

void PacketGen::push(int , Packet *p) {
	p_t *header = (p_t *)p->data();
	if(header->type == 1 && header->cur_sequence == cur_loop){
		click_chatter("Packet received and correct! ");
		ACK = 1;
	}
	return;
}

CLICK_ENDDECLS

EXPORT_ELEMENT(PacketGen)