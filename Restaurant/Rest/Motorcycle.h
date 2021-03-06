#ifndef __MOTORCYCLE_H_
#define __MOTORCYCLE_H_


#include "..\Defs.h"
#include <exception>
#include <cstdlib>
#include <iostream>

#pragma once
class Motorcycle	
{
	static int count;
	int ID;
	MOTO_TYPE type;	//for each order type there is a corresponding motorcycle type 
	int speed;		//meters it can move in one clock tick (in one timestep)
	REGION	region;	//region of the motorcycle
	int ArriveTime; //arrive time of the motorcycle
	int RestTime;
	bool Damaged;
	STATUS_TYPE status;
public:
	Motorcycle();
	Motorcycle(MOTO_TYPE type, int spd, REGION reg);
	int GetID() const;
	void SetType(MOTO_TYPE type);
	void SetArriveTime(int ArriveTime);
	int GetArriveTime() const;
	void SetRestTime(int RestTime);
	int GetRestTime() const;
	MOTO_TYPE GetType() const;
	void SetSpeed(int spd);
	int GetSpeed() const;
	void SetRegion(REGION reg);
	REGION GetRegion() const;
	void SetStatus(STATUS_TYPE s);
	STATUS_TYPE GetStatus() const;
	void SetDamaged(bool dmg);
	bool GetDamaged() const;
	friend bool operator> (const Motorcycle& moto, const Motorcycle& moto2);
	friend bool operator< (const Motorcycle& moto, const Motorcycle& moto2);
	virtual ~Motorcycle();
};

#endif