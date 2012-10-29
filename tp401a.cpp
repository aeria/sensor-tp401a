#include <Arduino.h>
#include <tp401a.h>

tp401a::tp401a(int pin)
{
	_pin = pin;
	voltage = 0;
	counterRead = 0;
	totalVoltage = 0;
	avgVoltage = 0;
}
int tp401a::read()
{
	voltage = analogRead(_pin);
	totalVoltage += voltage;
	counterRead++;
	
	return voltage;
}
int tp401a::lastRead()
{
	return voltage;
}

unsigned long tp401a::averageRead()
{
  avgVoltage = totalVoltage / counterRead;
  return avgVoltage;
}

void tp401a::reset()
{
	avgVoltage = tp401a::lastRead();
	counterRead = 0;
	totalVoltage = 0;
}
