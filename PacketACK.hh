//Write an element every 3 seconds create such packet and assign 
//either 0 or 1 to the type field.
//author @Haoyuan 2/29/2016
#ifndef CLICK_PACKETACK_HH
#define CLICK_PACKETACK_HH

#include <click/element.hh>
#include <click/timer.hh>

CLICK_DECLS

class PacketACK : public Element{
public:
	PacketACK();
	~PacketACK();

	const char *class_name() const { return "PacketACK"; }
	const char *port_count() const { return "1/1"; }
	const char *processing() const { return AGNOSTIC; }
	
	int configure(Vector<String>&, ErrorHandler*);
	void push(int, Packet *);

private:

};

CLICK_ENDDECLS

#endif
