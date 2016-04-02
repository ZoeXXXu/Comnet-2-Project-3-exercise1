//Write an element shows the packet content
//author @Haoyuan 3/1/2016
#ifndef CLICK_SHOWPACKET_HH
#define CLICK_SHOWPACKET_HH

#include <click/element.hh>

CLICK_DECLS

class ShowPacket : public Element{
public:
	ShowPacket();
	~ShowPacket();

	const char *class_name() const { return "ShowPacket"; }
	const char *port_count() const { return "1/1"; }
	const char *processing() const { return PUSH; }
	
	int configure(Vector<String>&, ErrorHandler*);
	void push(int, Packet *);
};

CLICK_ENDDECLS

#endif
