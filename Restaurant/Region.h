#pragma once
#include "Generic_DS\LinkedList.h"
#include "Generic_DS\Heap_PriorityQueue.h"
#include "Generic_DS\Queue.h"
#include "Rest\Motorcycle.h"
#include "Rest\Order.h"
#include <iostream>
using namespace std;
class Restaurant;
class Region
{
	static int cnt;
	string name;
	Restaurant* pRest;
	Heap_PriorityQueue<Motorcycle> Motor[MOTO_CNT];
	Heap_PriorityQueue<Order> VIPOrder;
	Queue<Order*> FrozenOrder;
	LinkedList<Order*> NormalOrder;
	//Heap_PriorityQueue<Motorcycle> AssignedMotors;
	//Heap_PriorityQueue<Motorcycle> RestMotors;
	//Heap_PriorityQueue<Motorcycle> DamagedMotors;
	Heap_PriorityQueue<Motorcycle> MotorStatus[STATUS_CNT];
	Queue<Order*> DrawOrders;
	
public:
	Motorcycle* getMotor(MOTO_TYPE type);
	void setMotor(Motorcycle* M);
	int getMotornum(MOTO_TYPE type);
	Order* getVIPOrder() ;
	void setVIPOrder(Order* O);
	Order* getFrozenOrder() ;
	void setFrozenOrder(Order* O);
	Order* getNormalOrder() ;
	void setNormalOrder(Order* O);
	void setSMotor(Motorcycle* M);
	Motorcycle* getSMotor(STATUS_TYPE type);
	//seter and getter for both the list
	//search functions for the cancelation and Prompotion 
	bool VIPOrderIsEmpty() const;
	bool NormalOrderIsEmpty() const;
	bool FrozenOrderIsEmpty() const;
	bool MotorIsEmpty(MOTO_TYPE type) const;
	bool SMotorsEmpty(STATUS_TYPE type) const;
	bool ArrivedMotors(int TimeStep);
	bool CancelOrder(int id);
	bool PromoteOrder(int id,int money=0);
	void AutoPromote(int cTime,int pTime);
	//DrawFunctions
	Order* getVIPDraw(Order* O) ;
	void setVIPDraw(Order* O);
	Order* getFrozenDraw(Order* O) ;
	void setFrozenDraw(Order* O);
	Order* getDrawOrders(Order* O) ;
	void setDrawOrders(Order* O);
	bool VIPDrawIsEmpty() const;
	bool DrawOrdersIsEmpty() const;
	bool FrozenDrawIsEmpty() const;
	void SharingOrderstoDraw();
	///////////////////////////////
	string Print();

	Region(Restaurant* ptr);
	~Region();
};

