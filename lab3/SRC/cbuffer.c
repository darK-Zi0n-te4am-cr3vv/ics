/*
	cbuffer.c
*/


#include "cbuffer.h"

VOID InitPipe(Pipe *pipe)
{
	pipe->RdIndex = 0;
	pipe->WrIndex = 0;
}

BYTE ReadPipeB(Pipe *pipe)
{
	if (pipe)
}

VOID ReadPipe(Pipe *pipe, BYTE *buffer, SIZE len)
{

}

SIZE ReadPipeNonBlocking(Pipe *pipe, BYTE *buffer, SIZE len)
{

}

VOID WritePipe(Pipe *pipe, BYTE *buffer, SIZE len)
{
}

SIZE WritePipeNonBlocking(Pipe *pipe, BYTE *buffer, SIZE len)
{
}