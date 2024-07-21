#include <stdio.h>
#include <windows.h>

#define MAXSIZE 256
	
int main() {
	
	/*HANDLE serverPipe = CreateNamedPipe(
    L"\\\\.\\pipe\\mojo.external_task_manager_8396",	// name of our pipe, must be in the form of \\.\pipe\<NAME>
    PIPE_ACCESS_DUPLEX, // open mode, specifying a duplex pipe so server and client can send and receive data
    PIPE_TYPE_MESSAGE,	// MESSAGE mode to send/receive messages in discrete units (instead of a byte stream)
    1,			// number of instanced for this pipe, 1 is enough for our use case
    2048,		// output buffer size
    2048,		// input buffer size
    0,			// default timeout value, equal to 50 milliseconds
    NULL		// use default security attributes
	);*/
	
	HANDLE hFile;
	CHAR Buf[MAXSIZE] = {0};
	DWORD nIn = 0;
	

	hFile = CreateFileA("\\\\.\\Pipe\\slobs", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
	
	if (hFile == INVALID_HANDLE_VALUE)
	{
		printf("\n File open error\n");
	}
	
	if (ReadFile(hFile, Buf, MAXSIZE - 2, &nIn, NULL) == FALSE)
	{
		printf("Unable to read file.\n");
		CloseHandle(hFile);
		return 0;
	}
	else
		while(1)
		if(nIn > 0 && nIn < MAXSIZE - 2)
		{
			printf("[+] %d bytes read from BUF\n", nIn);  
		}
		else if (nIn == 0)
		{
			printf("No data to read from BUF\n");
		}
	
	WriteFile(hFile, message, messageLength, &bytesWritten, NULL);
		
	printf("%s", &Buf);

	CloseHandle(hFile);
	

	return 0;
	
}
