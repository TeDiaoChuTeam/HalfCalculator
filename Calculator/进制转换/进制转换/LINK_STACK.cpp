// LINK_STACK.cpp: implementation of the LINK_STACK class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "进制转换.h"
#include "LINK_STACK.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

LINK_STACK::LINK_STACK()
{

}

LINK_STACK::~LINK_STACK()
{

}

void LINK_STACK::Init()
{
	h.next=NULL;
}

void LINK_STACK::Push(ELEMTYPE *pe)
{
	NODE *s;
	s=(NODE *)malloc(sizeof(NODE));
	s->e=*pe;
	s->next=h.next;
	h.next=s;
}


bool LINK_STACK::Empty()
{//返回true栈空，否则，栈满
	bool val=true;
	if(h.next)
		val=false;
	return val;
}

bool LINK_STACK::Pop(ELEMTYPE *pe)
{
	bool	val=false;
	NODE *s;	
	s=h.next;
	h.next=s->next;
	*pe=s->e;
	free(s);
	return val;
}

void LINK_STACK::Change(CString &pobj, int val,int obj_redix)
{
	char ch;
	pobj="0";
	if(val)
	{
		pobj="";
		IntToStringPush(val, obj_redix);
		while(!Empty())
		{
			Pop(&ch);
			pobj+=ch;
		}
	}
}



void LINK_STACK::IntToStringPush(int n, int redix)
{
	char m;
	while(n)
	{
		m=n%redix;
		n/=redix;
		if(m>9)
			m+=7;
		m+='0';
		Push(&m);
	}
}
