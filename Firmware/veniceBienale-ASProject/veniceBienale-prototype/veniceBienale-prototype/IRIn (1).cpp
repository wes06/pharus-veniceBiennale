/*
* IRIn.cpp
*
* Created: 3/24/2018 3:17:10 PM
* Author: wes
*/

#include <Arduino.h>
#include "IRIn.h"


IRIn::IRIn(int _inputPin)
{
	inputPin = _inputPin;
	pinMode(inputPin, INPUT);
	this->fillArray(0);
}


IRIn::IRIn(int _inputPin, int _delay)
{
	inputPin = _inputPin;
	pinMode(inputPin, INPUT);
	this->fillArray(_delay);
}


void IRIn::fillArray(int _delay)
{
	for (int i = 0; i < sampleCount; i++)
	{
		readings[i] = analogRead(inputPin);
		if(delay!=0) delay(_delay);
	}
}

void IRIn::addReading()
{
	readings[sampleBeingUpdated] = analogRead(inputPin);
	sampleBeingUpdated++;
	if(sampleBeingUpdated >= sampleCount) sampleBeingUpdated = 0;
}

int IRIn::getAverage()
{
	readingsSum = 0;
	for (int i = 0; i < sampleCount; i++)
	{
		readingsSum += readings[i];
	}
	readingsAvg = readingsSum/sampleCount;
	
	return readingsAvg;
}

// void IRIn::setTriggerVal(int _triggerVal)
// {
// 	triggerVal = _triggerVal;
// }
// 
// void IRIn::setTriggerBool(bool _triggerBool)
// {
// 	triggerBool = _triggerBool;
// }

// void IRIn::setDebounceLength(int _debounceLength)
// {
// 	debounceLength = _debounceLength;
// }
// 
// bool IRIn::debouncedInput(){
// 	bool _debouncedInput = false;
// 	if ((getAverage() > triggerVal)==triggerBool && newTrigger)
// 	{
// 		debounceTime = millis();
// 		newTrigger = false;
// 	}
// 	
// 	if((getAverage() > triggerVal)==triggerBool && (millis() - debounceTime > debounceLength)){
// 		_debouncedInput = true;
// 	}
// 	
// 	if((getAverage() <= triggerVal)==triggerBool){
// 		newTrigger = true;
// 		_debouncedInput = false;
// 	}
// 	return _debouncedInput;
// }
// 
