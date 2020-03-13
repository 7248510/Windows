#include <winsock2.h>
#include <iphlpapi.h>
#include <stdio.h>
#include <windows.h>
#pragma comment(lib, "IPHLPAPI.lib")
//Switch networks(Sec <> Programming)
int main()
{
	//Declaring a pointers
	FIXED_INFO * pFixedInfo;
	IP_ADDR_STRING * pIPAddr;
	ULONG ulOutBufLen;
	DWORD dwRetVal;
	//char test[132];
	//char domainoutput[] = "The computer doesn't have a domain name."; 
	//char test[132];
	/* From the tutorial on strings
	typedef wchar_t WCHAR;
	wchar_t *str = L"hello";
	*/
	//typedef char domainoutput;
	//char 
	//From docs, Allocating memory to the structures
	pFixedInfo = (FIXED_INFO *) malloc(sizeof(FIXED_INFO));
	ulOutBufLen = sizeof (FIXED_INFO);
	if (GetNetworkParams(pFixedInfo, &ulOutBufLen) == ERROR_BUFFER_OVERFLOW){
		free(pFixedInfo);
		pFixedInfo = (FIXED_INFO *) malloc(ulOutBufLen);
		if (pFixedInfo == NULL) {
			printf("Error allocating memory needed to call GetNetworkParams\n");
		}
	}
	if (dwRetVal = GetNetworkParams(pFixedInfo, &ulOutBufLen) != NO_ERROR) {
		printf("GetNetworkParams failed with error %d\n", dwRetVal);
		if (pFixedInfo) {
		free(pFixedInfo);
		}
	}
	//strncpy(test,pFixedInfo->DomainName, 132);
	//pFixedInfo->DomainName;
	/*
	if (test == NULL){
		printf("There is no domain name.");		
	}
	*/
	printf("\tHost Name: %s\n", pFixedInfo->HostName);
	//printf("\tDomain Name: %s\n", pFixedInfo->DomainName);
	
	//Clear/free the memory
	if (pFixedInfo){
			free(pFixedInfo);
			pFixedInfo = NULL;
	}
	
	return 0;
}