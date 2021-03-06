#ifndef PLAYER_H
#define PLAYER_H

#include "Characters.h"

class Player : public Characters
{
public:
	Player();
	~Player();

	static Player* getInstance();

	void damagePlayer(double);

	void setplayerstat(double, double, double);//health,oxygen,stamina

	virtual void setDefault();

	void updateOxygen(double);
	void setMaxOxygen(double);
	int getOxygen();
	int getMaxOxygen();

	void update(double);

	bool isRunning;
	bool inBase;

	float getOxygenbar();
	float getHealthBar();
	float getStaminabar();

private:
	bool lackOfOxygen;

	static Player* playerInstance;

	double currentOxygenValue;
	double maxOxygenValue;
	float recoverStamina;

};

#endif