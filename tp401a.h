#ifndef TP401A_H
#define TP401A_H

class tp401a
{
  public:
	tp401a(int pin);
	//void tp401a.begin();
	int read();
	int lastRead();
	void reset();
	unsigned long averageRead();
  private:
	int _pin;
	int voltage;
	unsigned long avgVoltage;
	unsigned long totalVoltage;
	unsigned long counterRead;
	
};

#endif