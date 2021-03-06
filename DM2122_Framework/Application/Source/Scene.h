#ifndef SCENE_H
#define SCENE_H

#include "Camera4.h"
#include "MatrixStack.h"
#include "Mesh.h"
#include "UIManager.h"

class GameObjectManager;
class EnvironmentManager;
class monsterManager;
class Player;

class Scene
{
public:
	enum GEOMETRY_TYPE
	{
		GEO_TRIANGLE_1 = 0,
		GEO_TRIANGLE_2,
		GEO_AXES,
		GEO_QUAD,
		GEO_CUBE,
		GEO_CIRCLE,
		GEO_RING,
		GEO_HEMISPHERE,
		GEO_SPHERE,
		GEO_CYLINDER,
		GEO_CONE,
		GEO_LIGHTBALL,
		GEO_ROOM,
		GEO_ROOMDOOR,
		GEO_TUTORIALDOOR,
		GEO_ROOMWINDOW,
		GEO_TEXT,
		GEO_TEXTBOX,
		GEO_SPACE,
		GEO_SUN,
		GEO_MOON,

		GEO_COAL,
		GEO_IRON,
		GEO_COBALT,

		GEO_BLASTER,
		GEO_LASERPROJ,

		GEO_CHEST,
		GEO_ALIENPROBE,
		GEO_BEHOLDER,
		GEO_STIMPAK,
		//GEO_PORTAL,

		GEO_LEFT,
		GEO_RIGHT,
		GEO_TOP,
		GEO_BOTTOM,
		GEO_FRONT,
		GEO_BACK,

		GEO_HEALTHSTAMINAOXYGENBACKGROUND,
		GEO_HEALTHBAR,
		GEO_OXYGENBAR,
		GEO_STAMINABAR,

		GEO_CROSSHAIR,

		GEO_UPGRADER,
		GEO_TRADER,
		GEO_FURNACE,

		GEO_UPGRADEUI,
		GEO_TRADINGUI,
		GEO_FURNACEUI,
		GEO_LOADING,
		GEO_RETURN,
		GEO_TRANSPORT,

		GEO_GROUND,

		TEXT,
		NUM_GEOMETRY,
	};

	enum UNIFROM_TYPE
	{
		U_MVP = 0,
		U_MODELVIEW,
		U_MODELVIEW_INVERSE_TRANSPOSE,
		U_MATERIAL_AMBIENT,
		U_MATERIAL_DIFFUSE,
		U_MATERIAL_SPECULAR,
		U_MATERIAL_SHININESS,
		U_LIGHT0_POSITION,
		U_LIGHT0_COLOR,
		U_LIGHT0_POWER,
		U_LIGHT0_KC,
		U_LIGHT0_KL,
		U_LIGHT0_KQ,
		U_LIGHTENABLED,
		U_LIGHT0_TYPE,
		U_LIGHT0_SPOTDIRECTION,
		U_LIGHT0_COSCUTOFF,
		U_LIGHT0_COSINNER,
		U_LIGHT0_EXPONENT,
		U_LIGHT1_POSITION,
		U_LIGHT1_COLOR,
		U_LIGHT1_POWER,
		U_LIGHT1_KC,
		U_LIGHT1_KL,
		U_LIGHT1_KQ,
		U_LIGHT1_TYPE,
		U_LIGHT1_SPOTDIRECTION,
		U_LIGHT1_COSCUTOFF,
		U_LIGHT1_COSINNER,
		U_LIGHT1_EXPONENT,
		U_COLOR_TEXTURE_ENABLED,
		U_COLOR_TEXTURE,
		U_NUMLIGHTS,
		U_TEXT_ENABLED,
		U_TEXT_COLOR,
		U_TOTAL,

	};

	Scene() {}
	~Scene() {}

	virtual void Init() = 0;
	virtual void Update(double dt) = 0;
	virtual void Render() = 0;
	virtual void Exit() = 0;

	Camera4 camera;
	MS modelStack, viewStack, projectionStack;

	float dt_;

	bool interact = false;

	unsigned m_vertexArrayID;
	unsigned m_programID;
	unsigned m_parameters[U_TOTAL];

	Mesh* meshList[NUM_GEOMETRY];
	void RenderMesh(Mesh *mesh, bool enableLight);

	void RenderText(Mesh* mesh, std::string text, Color color);

	static GameObjectManager _gameObjectMananger;
	static UIManager _UIManager;
	static EnvironmentManager _environmentManager;
	static monsterManager _monsterManager;
	static Player _player;

	unsigned monsterCount = 0;

private:
	
};

#endif