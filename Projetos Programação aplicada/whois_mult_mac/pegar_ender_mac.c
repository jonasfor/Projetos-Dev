#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/ioctl.h>
#include<net/if.h>  //para usar ifreq
#include<unistd.h>  //para usar a função close

int main(int argc, char** argv)
{
	int meu_socket;
	struct ifreq ifr;
	char *iface = "eth0";
	unsigned char *mac;

	meu_socket= socket(AF_INET, SOCK_DGRAM, 0);
	
	ifr.ifr_addr.sa_family = AF_INET;
	strncpy(ifr.ifr_name, iface, IFNAMSIZ-1);

	ioctl(meu_socket, SIOCGIFHWADDR, &ifr);

	close(meu_socket);
	
	mac = (unsigned char *)ifr.ifr_hwaddr.sa_data;

	printf("Mac : %.2x:%.2x:%.2x:%.2x:%.2x:%.2x\n", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
	return 0;
}
