//Define a custom packet with 2 header fields: 
//one of 1 Byte for the type and one of 4 Bytes expressing the length of the payload

typedef struct {
	u_char type;
//	u_char dest_addr;
//	u_char sour_addr;
	u_char cur_sequence;
	const char* payload;
} p_t;
