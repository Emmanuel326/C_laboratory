//sll_network_pool.c
//single-file human-readable, low-latency oriented singly-liked list
//preallocated object pool(no malloc in hot path)
//tail pointer for o(1) push back
//inline hot path
//clear human first naming convention.


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include<string.h>

//represent a single packet memory

struct PacketDescriptor
{
	unit32_t id;
	char source_ip[16];
	char dest_ip[16];
	unit16_t size;
};


//a node in the singly linked list

struct PacketNode
{
	struct PacketDescriptor packet; //the packet data
	struct PacketNode *next;
};

//the linked list itself
struct PacketList 
{
	struct PacketNode *head; //first node 
};


//initialise an empty list

void initialize_list(struct PacketList* list)
{
	list->head=NULL;
}
//
//
//add packet to the front(insert at beginning)
//this is a very common operation in networking- new packet arrive, add it to the list 
//
void add_packet_to_front(struct PackeList * list, struct PacketDescripror packet)
{
	//allocate memory for new node
	struct PacketNode* new_node=malloc(sizeof(struct PacketNode));
	if(!new_node)
	{
		perror("mem allocation failed\n");
		return;
	}
	//fill node
	new_node->packet=packet;
	new_node->next = list->head;// new node point to old first node
				    
	list->head = new_node;//now new node i sthe first node
}

//a  new packet comes in and we attch it to the current queue





