
#include <sgg/graphics.h>
#include "util.h"
#include "box.h"
#include "gameover.h"
#include <sstream>
#include <iostream>
#include <string>
using namespace std;

void Gameover::update(float dt)
{







	GameObject::update(dt);
}

void Gameover::draw()
{

	float w = m_state->getCanvasWidth();
	float h = m_state->getCanvasHeight();

	//draw background
	graphics::drawRect(w / 2, h / 2, w, h, m_brush_background);
	if (count_end == 0) {
		float lasttime = graphics::getGlobalTime();
		timerr = to_string((lasttime - m_state->Fisrttimer) / 1000.0f);
		count_end++;
	}
	graphics::setFont(mm_asset_path + "OpenSans-Regular.ttf");
	graphics::Brush m;
	string strr = "your time is   " + timerr + " seconds";
	graphics::drawText(w / 5.0f, h / 1.5f, 1.0f, strr, m);

}

void Gameover::init()
{
	m_brush_background.outline_opacity = 0.0f;
	m_brush_background.texture = m_state->getFullAssetPath("over.png");

}





Gameover::Gameover(const std::string& name)
	: GameObject(name)
{





}

Gameover::~Gameover()
{

}
