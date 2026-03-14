#pragma once
#include "gameobject.h"
#include <sgg\graphics.h>
#include "gamestate.h"
#include "box.h"
#include "util.h"


class Life : public Box, public GameObject {

public:
	graphics::Brush life_brush;
	graphics::Brush life_brush_debug;
	Life(std::string name = "block", float x = 5.0f, float y = 5.0f) : GameObject(name) {
		this->m_pos_x = x;
		this->m_pos_y = y;

	}

	void update(float dt)
	{
		m_pos_x = m_state->getPlayer()->m_pos_x - 8;
		m_pos_y = m_state->getPlayer()->m_pos_y - 4;

		GameObject::update(dt);
	}

	void init()
	{
		Box(m_pos_x, m_pos_y, 2.0f, 0.75f);
		life_brush.outline_opacity = 0.0f;
		life_brush_debug.fill_opacity = 0.1f;
		SETCOLOR(life_brush_debug.fill_color, 0.1f, 1.0f, 0.1f);
		SETCOLOR(life_brush_debug.outline_color, 0.3f, 1.0f, 0.2f);
	}

	void draw()
	{
		float x = m_pos_x + m_state->m_global_offset_x;
	    float y = m_pos_y + m_state->m_global_offset_y;
	    
		if (m_state->getPlayer()->life == 4)
			life_brush.texture = m_state->getFullAssetPath("4.png");
		else if (m_state->getPlayer()->life == 3)
			life_brush.texture = m_state->getFullAssetPath("3.png");
		else if (m_state->getPlayer()->life == 2)
			life_brush.texture = m_state->getFullAssetPath("2.png");
		else if (m_state->getPlayer()->life == 1)
			life_brush.texture = m_state->getFullAssetPath("1.png");
		graphics::drawRect(x, y, 2.2f, 0.75f, life_brush);
		if (m_state->m_debugging)
			graphics::drawRect(x, y, 2.2f, 0.75f, life_brush_debug);
	}


};
