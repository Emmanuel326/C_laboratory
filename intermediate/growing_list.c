#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char ipAddress[40];
	int portNumber;
	int isConnected;
}NetworkClient;

//for each of the above network client struct represents one co//nnection - who where and whether they are connected
	
void printAllClients(NetworkClient, *clientList, int totslClients)
{
	printf("\n--- Active Client List ---");
	for(int i=0;i<totalClients; i++)
	{
		printf("Client %d: %s:%d - %s\n",i+1
				clientList[i].ipAdress,
				clientList[i].portNumber,
				clientList[i].isConnected ? "CONNECTED" : "DISCONNECTED");

	}
}

int main(void)
{
	NetworkClient *clientList=NULL;
	int totalclients=0;
	char addmore='y';

	while(addmore=='y'|| addmore=='Y')
	{
		NetworkClient newclient;

		puts("Enter client ip address:");
		scanf("%s", &newClient.ipAdress);

		puts("Enter client's port number:");
		scanf("%s",&newClient.portNUmber);

		newClient.isConnected=1;//mark the new client as connected by defult

		//expand the array by one more slot
		NetworkClient *temporaryList=realloc(clientList,(totalClients + 1)* sizeof(int));
		if(!temporaryList)
		{
			perror("Failed to realloc");
			free(clientList);
			exit(EXIT_FAILURE);

		}
		clientList=temporaryList;
		clientList[totalClients] = newClient;
		totalClients++;
		puts("Add another client? (y/n):" );
	}
	printAllClients(clientList, totalClients);

	free(clientList);
	clientList=NULL;

	return 0;

}
