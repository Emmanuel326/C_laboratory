//we are gonna learn enums today 
//enum is short for enumeration. it is useful if you want to make
//code speak in human terms and not numbers eg 0,1,2  acros outputs and systems
//we wil design a small **packet processing loop. the kind that runs inside a trading system or telemery
//we will avoid using int data type for differnet packets types.

//DEFINE an ENUM

//packet_type.h
#ifndef PACKET_TYPES_H
#define PACKET_TYPES_H

//packettype tells us what kind of packet we are dealing with
//each type is compiled down to a sinple integer(0,1,2,...)
//but is kees our code easy to read and debug
typedef enum
{
	PACKET_MARKET_DATA=0;
	PACKET_ORDER_SUBMISSION,
	PACKET_HEARTBEAT,
	PACKET_CONTROL
}PacketType;

//you can assign numbers eg =10 if you want to control for wire protocols
//but i prefer to use them  auto-incremental from one(1).

//USING THE ENUM

#include <stdio.h>
#include "packet_typed.h"

typedef struct
{
	PacketType type;
	double timestamp;
	char payload[256];

}Packet;


void process_packet(cont packet *packetptr)
{
	switch(packetptr)
	{
		case PACKET_MARKET_DATA:
			printf("[DATA] procesing market data\n");
			break;
		case PACKET_ORDER_SUBMISSION:
			printf("[ORDER] handling order submission\n");
			break;
		case PACKET_HEARTBEAT:
			printf("[PING] heartbeat received\n");
			break;
		case PACKET_CONTROL:
			printf("[CTRL] control message processed\n");
			break;
		default:
			printf("[WARN] uknown packet type: %d\n", packetptr->type);
			break;
	}
}


int main(void)
{
	Packet pkt1={PACKET_MARKET_DATA, 123456.453. "EUR/USD update"};
	process_packet(&pkt1);
	return 0;

}


//ADVANCED USAGE
