#include <windows.h>
#include <stdio.h>
#include "ftd2xx.h"

int main(int argc, char* argv[])
{
    FT_HANDLE fthandle;
    FT_STATUS status;
    status = FT_Open(0, &fthandle);

    if(status != FT_OK)
    {
        printf("open status not ok %d\n", status);
        return 0;
    }

    status = FT_ResetDevice(fthandle);

    if(status != FT_OK)
        printf("reset status not ok %d\n", status);

    DWORD data_out = 0xAA;
    DWORD data_written;
    INT loop;

    UCHAR data_buf[16] = {0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55};

    for (loop=1;loop<1000000;loop++)
    {
        status = FT_Write(fthandle, &data_buf, 16, &data_written);
        printf("loop number %d\n", loop);
    }

    if(status != FT_OK)
        printf("status not ok %d\n", status);
    else
        printf("output data \n");
        
    status = FT_Close(fthandle);
    return 0;
}