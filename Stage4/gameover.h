#pragma once


#include "gameobject.h"
#include <vector>
#include <list>
#include <string>
#include <sgg/graphics.h>
#include "player.h"
#include "block.h"
#include "alienship.h"


class Gameover : public GameObject
{
	graphics::Brush m_brush_background;

	const std::string mm_asset_path = "assets\\";
	const float m_block_size = 1.0f;

	const float Lasttime = 0.0f;
	graphics::Brush m_block_brush;
	graphics::Brush m_block_brush_debug;

	float m_center_x = 5.0f;
	float m_center_y = 5.0f;


public:
	void update(float dt) override;
	void draw() override;
	void init() override;

	int kk = 1;

	int count_end = 0;

	std::string timerr = "";

	Gameover(const std::string& name = "gameov");
	~Gameover() override;
};
