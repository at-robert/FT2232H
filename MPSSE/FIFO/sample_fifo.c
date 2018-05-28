#include <windows.h>
#include <stdio.h>
#include "ftd2xx.h"

int main(int argc, char* argv[])
{
	FT_HANDLE fthandle1;
	FT_STATUS status;
	status = FT_Open(0, &fthandle1);

	if(status != FT_OK)
	{
		printf("open device status not ok %d\n", status);
		return 0;
	}

	status = FT_SetTimeouts(fthandle1,500,500);

	if(status != FT_OK)
		printf("timeout A status not ok %d\n", status);

	DWORD RxBytes;
	DWORD TxBytes;
	DWORD EventDword;

	status = FT_GetStatus(fthandle1, &RxBytes, &TxBytes, &EventDword);
	printf("bytes in RX queue %d\n", RxBytes);
	printf("\n");

	UCHAR data_in[65536]; // declare a large buffer for incoming data
	DWORD r_data_len = RxBytes;
	DWORD data_read;

	memset(data_in,0,1028);
	status = FT_Read(fthandle1, data_in, r_data_len, &data_read);

	if(status != FT_OK)
		printf("status not ok %d\n", status);
	else {
		printf("bytes read %d\n", data_read);
		printf("data read %x\n", data_in[0]);
		printf("data read %x\n", data_in[1]);
		printf("data read %x\n", data_in[2]);
		printf("data read %x\n", data_in[3]);
	}
	
	getchar();
	status = FT_Close(fthandle1);
	return 0;
}