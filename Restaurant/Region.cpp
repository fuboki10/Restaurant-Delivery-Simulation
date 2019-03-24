#include "Region.h"


Region::Region()
{
	NormOrd = FrozOrd =	VIPOrd = NormMoto = VIPMoto = FrozMoto = 0;
	
}

Motorcycle* Region::getVIPMotor() 
{
	Motorcycle*M=VIPMotor.peek();
	if(VIPMotor.remove()) VIPMoto--;
	return M;
}
Motorcycle* Region::getFrozenMotor() 
{
	Motorcycle*M=FrozenMotor.peek();
	if(FrozenMotor.remove()) FrozMoto--;
	return M;
}
Motorcycle* Region::getNormalMotor() 
{
	Motorcycle*M=NormalMotor.peek();
	if(NormalMotor.remove()) NormMoto--;
	return M;
}
Order* Region::getVIPOrder() 
{
	Order*O=VIPOrder.peek();
	if(VIPOrder.remove()) VIPOrd--;
	return O;
}
Order* Region::getFrozenOrder() 
{
	Order* ptr = FrozenOrder.removeBegin();
	if(ptr) FrozOrd--;
	return ptr;
}
Order* Region::getNormalOrder() 
{
	Order* ptr = NormalOrder.removeBegin();
	if(ptr) NormOrd--;
	return ptr;
}
void Region::setVIPMotor(Motorcycle* V)
{
	if(VIPMotor.add(V)) VIPMoto++;
}
void Region::setFrozenMotor(Motorcycle* F)
{
	if(FrozenMotor.add(F)) FrozMoto++;
}
void Region::setNormalMotor(Motorcycle* N)
{
	if(NormalMotor.add(N)) NormMoto++;
}
void Region::setVIPOrder( Order* O)
{
	if(VIPOrder.add(O)) VIPOrd++;
}
void Region::setFrozenOrder(Order* O)
{
	if(FrozenOrder.add(O)) FrozOrd++;
}
void Region::setNormalOrder(Order* O)
{
	if(NormalOrder.add(O)) NormOrd++;
}
bool Region::VIPOrderIsEmpty()
{
	return VIPOrder.isEmpty();
}
bool Region::NormalOrderIsEmpty()
{
	return NormalOrder.isEmpty();
}
bool Region::FrozenOrderIsEmpty()
{
	return FrozenOrder.isEmpty();
}
bool Region::CancelOrder(int id)
{
	
	return NormalOrder.removeID(id);
}

//Draw functions
Order* Region::getVIPDraw(Order* O) 
{
	 VIPDraw.dequeue(O);
	 return O;
}
Order* Region::getFrozenDraw(Order* O) 
{
	FrozenDraw.dequeue(O);
	 return O;
}
Order* Region::getNormalDraw(Order* O) 
{
	NormalDraw.dequeue(O);
	 return O;
}
void Region::setVIPDraw( Order* O)
{
	VIPDraw.enqueue(O);
}
void Region::setFrozenDraw(Order* O)
{
	FrozenDraw.enqueue(O);
}
void Region::setNormalDraw(Order* O)
{
	NormalDraw.enqueue(O);
}
bool Region::VIPDrawIsEmpty()
{
	return VIPDraw.isEmpty();
}
bool Region::NormalDrawIsEmpty()
{
	return NormalDraw.isEmpty();
}
bool Region::FrozenDrawIsEmpty()
{
	return FrozenDraw.isEmpty();
}
////////////////////////////////////////////////////
Region::~Region()
{
}
