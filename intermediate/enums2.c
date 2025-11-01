//in ULL level systems you often want enums to map directly 
//to hardware/protocol IDs or specific codes
//do you know what that means?? 
//you will assign explicit values instead of relying on auto-incremented ones.


//Explicit Enum Values

typedef enum
{
	PACKET_MARKET_DATA =10;
	PACKET_ORDER_SUBMISSION =20;
	PACKET_HEARTBEAT =30;
	PACKET_CONTROL =40;
}PacketType;

//2. GROUPED OF HIERARCHIAL ENUMS
//in real systems enums represent categories of operations

typedef enum
{
	PACKET_MARKET_DATA = 100;
	PACKET_TRADE_UPDATE = 101;
	PACKET_ORDER_SUBMISSION = 200;
	PACKET_ORDER_CANCEL = 201;
	PACKET_HEARTBEAT = 300;
	PACKET_CONTROL = 400

}PacketType;

//1xx -> market data mess
//2xx -> order-related mess
//3xx -> heartbeats 
//4xx -> control/system packets
//
//this makes debugging and packet tracing much easier and saner

//3.Enum to string mapping(For logging)
cont char *packet_type_to_string(PacketType type)
{
	switch(type)
	{
		case PACKET_MARKET_DATA: return "MARKET_DATA";
		case PACKET_TRADE_UPDATE: return "TRADE_UPDATE";
		case PACKET_ORDER_SUBMISSION: return "ORDER_SUBMISSION";
		case PACKET_ORDER_CANCEL: return "ORDE_CANCEL";
		case PACKET_HEARTBEAT: return "HEARTBEAT";
		case PACKET_CONTROL:  return "CONTROL";
		default:              return "UNKNOWN";


	}
}






