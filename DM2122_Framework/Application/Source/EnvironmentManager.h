#ifndef ENVIRONMENTMANAGER_H
#define ENVIRONMENTMANAGER_H

#include "Veins.h"
#include <time.h>
#include <stdlib.h>
#include <vector>

class EnvironmentManager
{
public:
	EnvironmentManager();
	~EnvironmentManager();

	enum ENVIRONMENT_TYPE {
		T_COAL = 0,
		T_IRON,
		T_COBALT,
		T_NUMTYPE
	};

	void initRandPos(ENVIRONMENT_TYPE oreType);//gets the ore type and initialize the pos values of it
	void add(GameObject* gameobject);//add the position into the gameobject

	static	std::vector<Vector3>orePos;


private:


	std::vector<GameObject*> VecEnvObj;// stores environment objs to pass into GOmmanager
	const int CMap = 150; //size of map
	int numOres; //number of ores to render
	int RandX;//random x value
	int RandZ;//random z value
	std::vector<int>RandXVec;//stores random x values
	std::vector<int>RandZVec;//stores random y values






};
#endif // !1