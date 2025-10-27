#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//example: network packet queue
////i will simulate network interface queue--- a linked list of packets waiting to be prcessed.

//represent a single netwrok packet in the queue

typedef struct
{
	char sourceIP[16];
	char destinationIP[16];
	int payloadBytes;
	struct NetworkPacket* nextpacket;

}NetworkPacket;

//represents the entire packet queue

typedef struct PacketQueue
{
	struct NetworkPacket * firstpacket;
	struct NetworkPacket *lastpacket;
}

//3. Packet initialization

 struct packetQueue *createQueue()
{
	struct packetQueue *queue=malloc(sizeof(struct packetQueue));
	if(!queue)
	{
		perror("Error occured");
		exit(EXIT_FAILURE);
	}

	queue->firstPacket =NULL;
	queue->lastpacket  =NULL;
	return queue;
}

//4.I create a packet now

struct NetworkPacket* createPacket(const char *source, cont char *destination, int payloadBytes)
{
	if(!packet)
	{
		perror()
	}
}
