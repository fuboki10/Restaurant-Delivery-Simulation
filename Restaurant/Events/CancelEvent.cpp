#include "CancelEvent.h"
#include "..\Rest\Restaurant.h"

CancelEvent::CancelEvent(Restaurant* pR) : Event(pR)
{
}

void CancelEvent::ReadEvent(ifstream& fin)
{
	fin>>EventTime>>OrderID;
}
void CancelEvent::Execute()
{
	cout<<"lol"<<endl;
}

CancelEvent::~CancelEvent(void)
{
	
}
