// SEQUENCE_QUEUE.cpp: implementation of the SEQUENCE_QUEUE class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "进制转换.h"
#include "SEQUENCE_QUEUE.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SEQUENCE_QUEUE::SEQUENCE_QUEUE()
{

}

SEQUENCE_QUEUE::~SEQUENCE_QUEUE()
{

}

void SEQUENCE_QUEUE::Init()
{
	this->front=rear=0;				//设置空队
}


bool SEQUENCE_QUEUE::TestFull()
{
	bool v=false;
	if(front==(rear+1)%MAXSIZE)
		v=true;						//队满
	return v;
}


bool SEQUENCE_QUEUE::TestEmpty()
{
	bool	v=false;
	if(front==rear)
		v=true;						//队空
	return v;
}

void SEQUENCE_QUEUE::InQueue(ELEMTYPE *pe)
{
	queue[rear]=*pe;
	rear=(rear+1)%MAXSIZE;
}


void SEQUENCE_QUEUE::OutQueue(ELEMTYPE *pe)
{
	*pe=queue[front];
	front=(front+1)%MAXSIZE;
}

void SEQUENCE_QUEUE::Change(CString &pobj, double v, int obj_redix)
{
	int	i;	char m;
	for(i=1;i<11 && v>1e-10;i++)			//只做十位
	{
		v*=obj_redix;
		m=v;
		v-=m;
		if(m>9)
			m+=7;
		m+='0';
		InQueue(&m);
	}
	pobj="";
	while(!TestEmpty())
	{
		this->OutQueue(&m);
		pobj+=m;
	}
}
