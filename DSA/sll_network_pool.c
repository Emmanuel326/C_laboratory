#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>

//Represent a single packet in memory.
//think of this as the payload description

struct PackectDescriptor
{
	uint32_t id;
	char source_ip[16];
	char dest_ip[16];
	uint16_t size;
};
//The above is the cargo container.
//each node will jold a complete packet snapshot

//2,The node
//each node holds one packet and points to the next node

struct PacketNode
{
	struct PacketDescriptor packet;
	struct PacketNode *next;
};

//analogy:- a node is like a freight car carrying one packet and knowing only one thing. "Who is next in line?"


//3.The train...the list itself

struct PacketList
{
	struct PacketNode *head;
	struct PacketNode *tail;// this is optional but good 
				// practice for o(1) appends
};

//4.INITIALIZATION
//initialize an empty packet list
//always call this before using the list


void initialize_list(struct PacketList *list)
{
	list->head=NULL;
	list->tail=NULL;
};

//5.ADD packet to front-O(1)
//this simulates a new incoming packet
//add a packet to the front of the list

void add_packet_to_front(struct PacketList *list, struct PacketDescriptor packet)
{
	struct PacketNode *new_node =malloc(sizeof(struct PackeNode));
	if(!new_node)
	{
		perror("Failed to allocate");
		exit(EXIT_FAILURE);
	}
	//fill the node
	new_node->packet=packet; //point to old first node
	new_node->next = list->head;
	list->head= new_node; //new_mode becomes the new head
	
	//if list was empty, tail also points to this new node
	if(list->tail==NULL)
		list->tail = new_node;
	//This is how most real-world systems handle new arriva . packet come in, get  attached to a queue and later processed by a consumer thread.
	
}

//6.Add packet to back. O(1) with tail;
//add a packet to the using tail

void add_packet_to_back(struct PacketList *list, struct PacketDescriptor packet)
{
	struct PacketNode *new_node=malloc(sizeof(struct PacketNode));
	if(!new_node)
	{
		perror("Error occured while allocating memory");
		return;
	}
	new_node->packet=packet;
	new_node->next=NULL;


	if(list->tail)
	{
		list->tail->next=new_node;
		list->tail=new_node;
	}
	else
	{
		//list was empty
		list->head=list->tail=new_node;
	}
	//notice how no loop is required. Thanks to the tail pointer. that is the O(1) beauty of this setup
}

//7.DISPLAY PACKETS FOR DEBUGGING?LOGGING.
void print_packets(const struct PacketList *list)
{
	const struct PacketNode *current=list->head;
	while (current)
	{
		printf("Packet ID: %u  | src: %s | Dst: %s | Size: %u bytes\n",
				current->packet.id,
				current->packet.source_ip,
				current->packet.dest_ip,
				current->packet.size);
		curreent=current->next;
	}
}

void free_list(struct PacketList *list)
{
	struct PacketNOde *current = list->head;
	while(current)
	{
		struct PacketNode *temp =current;
		current=current->next;
		free(temp);
	}
	list->head = list->tail=NULL;
}

//9.DEMO MAIN
int main(void)
{
	struct PacketList queue;
	initialize_list(&queue);

	struct PacketDescriptor pkt1={1, "192.168.1.1", "10.0.0.2", 512};
	struct PacketDescriptor pkt2={2, "192.168.1.2","10.0.0.3",256};
	struct PacketDescriptor pkt3={2,"192.168.1.3","10.0.0.4",1024};


	add_packet_to_back(&queue, pkt1);
	add-packet_to_back(&queue, pkt2);
	add_packet_to_back(&queue, pkt3);//new urgent packet
					 //
	print_packets(&queue);
	free(&queue);

	return 0;
}



