//this is veth1 connected router, it read and send the packets to veth2
require(library	/home/comnetsii/elements/routerport.click);

//define($in_mac ba:cd:dc:fc:82:cf); //veth2_mac
//define($out_mac 82:9c:86:8e:89:6c); //veth1_mac
//define($dev veth2);

rp::RouterPort(DEV $dev, IN_MAC $in_mac, OUT_MAC $out_mac);

Idle -> rp -> ShowPacket -> PacketACK -> rp;
