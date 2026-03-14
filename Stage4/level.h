#pragma once

#include "gameobject.h"
#include <vector>
#include <list>
#include <string>
#include <sgg/graphics.h>
#include "player.h"
#include "block.h"
#include "powerupSp.h"
#include "powerupL.h"
#include "asteroids.h"
#include "alienship.h"


class Level : public GameObject
{
	graphics::Brush m_brush_background;

	std::vector<GameObject*> m_static_objects;
	std::vector<GameObject*> m_dynamic_objects;
	std::vector<GameObject*> alienship;
	std::vector<GameObject*> powerups;
	std::vector<GameObject*> powerupSp;
	std::vector<GameObject*> powerupL;






	const float m_block_size = 1.0f;
	graphics::Brush m_block_brush;
	graphics::Brush m_block_brush_debug;

	float m_center_x = 5.0f;
	float m_center_y = 5.0f;
	bool gameover = false;
	Asteroids* ast = 0;
	AlienShip* kll = 0;
	PowerUpSp* ps = 0;
	PowerUpl* pl = 0;


	int point = 0;
	int life = 4;



public:


	// dedicated method to draw a block
	void drawBlock(int i);

	void drawAsteroids(int i);

	void drawAlienShip(int i);


	void drawPowerupSp(int i);

	void drawPowerupL(int i);

	// detect collisions
	void checkCollisions();


public:
	void update(float dt) override;
	void draw() override;
	void init() override;
	void loselife();
	float randomX();
	float randomY();
	int kk = 1;
	int count = 0;


	Level(const std::string& name = "Level0");
	~Level() override;
};
