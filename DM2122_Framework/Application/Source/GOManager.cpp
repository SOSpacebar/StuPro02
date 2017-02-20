#include "GOManager.h"
#include <algorithm>  

GameObjectManager::GameObjectManager()
{

}

GameObjectManager::~GameObjectManager()
{
	for_each(_gameObjects.begin(), _gameObjects.end(), GameObjectDeallocator());
}

void GameObjectManager::add(objectType type, GameObject* gameObject)
{
	_gameObjects.insert(std::pair<objectType, GameObject*>(type, gameObject));
}

void GameObjectManager::remove(GameObject* gameObject)
{
	std::multimap<objectType, GameObject*> &temp = _gameObjects;

	for (auto &it = temp.begin(); it != temp.end(); it++)
	{
		if (it->second == gameObject)
		{
			it = _gameObjects.erase(it);
			delete gameObject;
			return;
		}
	}
}

void GameObjectManager::update(Camera4& cam)
{
	std::multimap<objectType, GameObject*>::iterator objIt = _gameObjects.begin();

	static Vector3 prevPosition = cam.position;
	static Vector3 prevTarget = cam.target;

	for (objIt; objIt != _gameObjects.end(); objIt++)
	{
		GameObject* temp = objIt->second;

		//Check For Player Collision
		if (!temp->anyInteraction())
		{
			Vector3 lastHitPos;
			if (temp->getCollider().checkHit(cam.getCollider(), &lastHitPos))
			{
				std::cout << temp->getName(); //Check what collider its hitting
				lastHitPos.Normalize();
				cam.position = lastHitPos;

				cam.position = prevPosition;
				cam.target = prevTarget;
			}

			else
			{
				prevPosition = cam.position;
				prevTarget = cam.target;
			}
		}
	}
}

GameObject* GameObjectManager::get(GameObject* gameObject)
{
	std::multimap<objectType, GameObject*> &temp = _gameObjects;

	for (auto &it = temp.begin(); it != temp.end(); it++)
	{
		if (it->second == gameObject)
		{
			return it->second;
		}
	}

	return NULL;
}

int GameObjectManager::GetObjectCount() const
{
	return _gameObjects.size();
}

void GameObjectManager::renderGameObjects()
{
	for (auto &i : _gameObjects)
	{
		i.second->render();
	}
}