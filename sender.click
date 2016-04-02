//this is veth2 connected router, it send the packets to veth1
require(library	/home/comnetsii/elements/routerport.click);

//define($in_mac 26:37:9e:1b:73:1b); //veth1_mac
//define($out_mac ea:56:e0:b1:b0:05); //veth2_mac
//define($dev veth1);

rp::RouterPort(DEV $dev, IN_MAC $in_mac, OUT_MAC $out_mac);

Idle -> rp -> PacketGen(DATA "hello") -> rp;
		  
//Idle -> rp -> ShowPacket -> Discard;