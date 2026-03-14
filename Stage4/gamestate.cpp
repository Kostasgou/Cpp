#include "gamestate.h"
#include "level.h"
#include "player.h"
#include "block.h"
#include <thread>
#include <chrono>
#include "alienship.h"
#include "powerupSp.h"
#include "powerupL.h"
#include "life.h"
#include "gameover.h"
#include "asteroids.h"
#include "win.h"

using namespace std::chrono_literals;

GameState::GameState()
{


}

GameState::~GameState()
{

	if (count == 4) {
		m_current_levell = new Gameover("1.lvl");
		m_current_levell->init();
	}

	if (count == 6) {
		m_current_levelll = new win("7.lvl");
		m_current_levelll->init();

	}
	
	
}

GameState* GameState::getInstance()
{
	if (!m_unique_instance)
	{
		m_unique_instance = new GameState();
	}
	return m_unique_instance;
}

bool GameState::init()
{
	m_current_level = new Level("1.lvl");
	m_current_level->init();
	
	m_player = new Player("Player");
	m_player->init();

	m_block = new block("block");
	m_block->init();

	m_asteroids = new Asteroids("block");
	m_asteroids->init();

	m_life = new Life("block");
	m_life->init();

	m_alienship = new AlienShip("aliens");
	m_alienship->init();


	m_powerupSp = new PowerUpSp("power");
	m_powerupSp->init();

	m_powerupL = new PowerUpl("power");
	m_powerupL->init();




	

	float Fisrttimer = graphics::getGlobalTime();

	graphics::preloadBitmaps(getAssetDir());
	graphics::setFont(m_asset_path + "OpenSans-Regular.ttf");
	graphics::playSound(m_asset_path + "song.mp3", 1.0f, true);


	

	return true;
}

void GameState::draw()
{
	if (count == 3) {
		float width = getCanvasWidth();
		float height = getCanvasHeight();
		graphics::Brush m;
		m.texture = getFullAssetPath("sta.png");
		m.outline_opacity = 0.0f;
		graphics::drawRect(getCanvasWidth() / 2, getCanvasHeight() / 2, width, height, m);
	}
	
		
	if(count==5) {
		m_current_level->draw();
	}

	if (count == 4) {
		if (m_current_levell) {
			m_current_levell->draw();
		}
		return;
	}

	if (count == 6) {
		if (m_current_levelll) {
			m_current_levelll->draw();
		}
		return;
	}

	
	
	
}

void GameState::update(float dt)
{
	// Skip an update if a long delay is detected 
	// to avoid messing up the collision simulation
	if (dt > 500) // ms
		return;
	
	// Avoid too quick updates
	float sleep_time = std::max(17.0f - dt, 0.0f);
	if (sleep_time > 0.0f)
	{
		std::this_thread::sleep_for(std::chrono::duration<float, std::milli>(sleep_time));
	}

	if (count == 3) {
		if (graphics::getKeyState(graphics::SCANCODE_SPACE)) {
			count = 5;
		}
	}

	
		
	if(count==5) {
		m_current_level->update(dt);

		m_debugging = graphics::getKeyState(graphics::SCANCODE_0);
	}


	if (count == 4) {
		if (m_current_levell) {
			m_current_levell->update(dt);
			m_current_levell->draw();
		}
	}

	if (count == 6) {
		if (m_current_levelll) {
			m_current_levelll->update(dt);
			m_current_levelll->draw();
		}
	}

}

std::string GameState::getFullAssetPath(const std::string& asset)
{
	return m_asset_path + asset;
}

std::string GameState::getAssetDir()
{
	return m_asset_path;
}

GameState* GameState::m_unique_instance = nullptr;