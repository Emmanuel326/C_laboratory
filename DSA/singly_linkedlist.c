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


//a node in the sinly linked list




