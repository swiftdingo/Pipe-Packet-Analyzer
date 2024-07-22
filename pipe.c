#include <stdio.h>
#include <windows.h>

#define MAXSIZE 256
	
int main(int argc, char *argv[]) {
	
	HANDLE hFile, serverPipe;
	CHAR Buf[MAXSIZE] = {0};
	DWORD nIn = 0;
	CHAR msg[MAXSIZE] = {0};
	DWORD bytesWritten = 0;
	
	hFile = CreateFileA("\\\\.\\Pipe\\slobs", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
	
	if (hFile != INVALID_HANDLE_VALUE)
	{
		printf("File open\n");
		
	}
		
	WriteFile(hFile, argv[1], sizeof(msg), &bytesWritten, NULL);
	
	if(ReadFile(hFile, Buf, MAXSIZE - 2, &nIn, NULL) == FALSE)
	{
		printf("Unable to read file.\n");
		CloseHandle(hFile);
		return 0;
	}
	
	if(nIn > 0 && nIn < MAXSIZE - 2)
		{
			printf("[+] %d bytes read from BUF\n", nIn);  
			printf("%s", &Buf);
			
		}
		else
			printf("No data to read from BUF\n");
	
	while(1)
	{
		//you have to keep calling the file if you want to open it 
		hFile = CreateFileA("\\\\.\\Pipe\\slobs", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
		
		printf("[+] payload = ");
		scanf("%s", &msg);
		printf("\n");
		printf("sending %s\n", msg);
		
		WriteFile(hFile, msg, sizeof(msg), &bytesWritten, NULL);
		
		printf("[+] reading file...\n");
		ReadFile(hFile, Buf, MAXSIZE - 2, &nIn, NULL);
		
		if(nIn > 0 && nIn < MAXSIZE - 2)
		{
			printf("[+] %d bytes read from BUF\n", nIn);  
			printf("%s", &Buf);
			
		}
		else
			printf("No data to read from BUF\n");
		
		Sleep(1000);
		nIn = 0;
	}
					
	CloseHandle(hFile);
	return 0;
	
}
