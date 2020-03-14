#include <winsock2.h>
#include <iphlpapi.h>
#include <stdio.h>
#include <windows.h>
#pragma comment(lib, "IPHLPAPI.lib")
#pragma comment(lib, "Ws2_32.lib")
//IPHelper requires administrator privileges
//cl manage.c && manage.exe
//void addrtable();
//void manage();
int main()
{
	ULONG NTEContext = 0;
	ULONG NTEInstance = 0;
	UINT iaIPAddress;
	UINT iaIPMask;
	DWORD dwRetVal;
	MIB_IPADDRTABLE *pIPAddrTable;
	DWORD dwSize = 0;
	iaIPAddress = inet_addr("10.0.2.2");
	iaIPMask = inet_addr("255.0.0.0");
	pIPAddrTable = (MIB_IPADDRTABLE*) malloc(sizeof(MIB_IPADDRTABLE));
	if (GetIpAddrTable(pIPAddrTable, &dwSize, 0) == ERROR_INSUFFICIENT_BUFFER) {
		free(pIPAddrTable);
		pIPAddrTable = (MIB_IPADDRTABLE *) malloc(dwSize);
	}
	if ((dwRetVal = GetIpAddrTable(pIPAddrTable, &dwSize, 0)) != NO_ERROR) {
		printf("GetIPAddrTable call failed with %d\n", dwRetVal);
	}
	//table[x] x = adapter#
	dwRetVal = AddIPAddress(iaIPAddress, iaIPMask, pIPAddrTable->table[0].dwIndex, &NTEContext, &NTEInstance);
	if (dwRetVal != NO_ERROR) {
		printf("AddIPAddress call failed with %d\n", dwRetVal);
	}
	if (dwRetVal = 5010) {
			printf("The error code 5010 means the IP address is already assigned to the interface");
		}
	if (pIPAddrTable)
        free(pIPAddrTable);
	//printf(iaIPAddress);
}
/*
void addrtable()
{
	/*
	GetIpAddrTable Function
		IPHLPAPI_DLL_LINKAGE DWORD GetIpAddrTable(
		PMIB_IPADDRTABLE pIpAddrTable,
		PULONG           pdwSize,
		BOOL             bOrder
	);	varibles below
	
	MIB_IPADDRTABLE *pIPAddrTable;
	DWORD dwSize = 0;
	DWORD dwRetVal;
	//Allocating memory to the structure
	pIPAddrTable = (MIB_IPADDRTABLE*) malloc(sizeof(MIB_IPADDRTABLE));
	//Calling(Initially calling) GetIPAddrTable
	if (GetIpAddrTable(pIPAddrTable, &dwSize, 0) == ERROR_INSUFFICIENT_BUFFER) {
		free(pIPAddrTable);
		pIPAddrTable = (MIB_IPADDRTABLE *) malloc(dwSize);
	}
	//Making a second call with general error checking and return the DWORD varible
	if ((dwRetVal = GetIpAddrTable(pIPAddrTable, &dwSize, 0)) != NO_ERROR) {
		printf("GetIPAddrTable call failed with %d\n", dwRetVal);
	}
	printf("IP Address:         %ld\n", pIPAddrTable->table[0].dwAddr);
	printf("IP Mask:            %ld\n", pIPAddrTable->table[0].dwMask);
	printf("IF Index:           %ld\n", pIPAddrTable->table[0].dwIndex);
	printf("Broadcast Addr:     %ld\n", pIPAddrTable->table[0].dwBCastAddr);
	printf("Re-assembly size:   %ld\n", pIPAddrTable->table[0].dwReasmSize);
	if (pIPAddrTable)
		free(pIPAddrTable);
}
*/
/*
void manage()
{
	ULONG NTEContext = 0;
	ULONG NTEInstance = 0;
	UINT iaIPAddress;
	UINT iaIPMask;
	DWORD dwRetVal;
	MIB_IPADDRTABLE *pIPAddrTable;
	DWORD dwSize = 0;
	iaIPAddress = inet_addr("10.0.1.6");
	iaIPMask = inet_addr("255.0.0.0");
	pIPAddrTable = (MIB_IPADDRTABLE*) malloc(sizeof(MIB_IPADDRTABLE));
	dwRetVal = AddIPAddress(iaIPAddress, iaIPMask, pIPAddrTable->table[0].dwIndex, &NTEContext, &NTEInstance);
	if (dwRetVal != NO_ERROR) {
		printf("AddIPAddress call failed with %d\n", dwRetVal);
	}
	
}
*/