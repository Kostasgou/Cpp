#pragma once

#include <string>

class GameState
{
private:
	static GameState* m_unique_instance;

	const std::string m_asset_path = "assets\\";

	const float m_canvas_width = 20.0f;
	const float m_canvas_height = 10.0f;


	class Level* m_current_level = 0;
	class Player* m_player = 0;
	class block* m_block = 0;
	class Asteroids* m_asteroids = 0;
	class Life* m_life = 0;
	class AlienShip* m_alienship = 0;
	class PowerUpSp* m_powerupSp = 0;
	class PowerUpl* m_powerupL = 0;
	

	GameState();

protected:
	class Gameover* m_current_levell = 0;
	class win* m_current_levelll = 0;

public:
	float m_global_offset_x = 0.0f;
	float m_global_offset_y = 0.0f;

	bool m_debugging = false;

	int count = 3;

	const float Fisrttimer = 0.0f;


public:
	~GameState();
	static GameState* getInstance();

	bool init();
	void draw();
	void update(float dt);
	


	std::string getFullAssetPath(const std::string& asset);
	std::string getAssetDir();

	float getCanvasWidth() { return m_canvas_width; }
	float getCanvasHeight() { return m_canvas_height; }

	class Player* getPlayer() { return m_player; }

	class block* getblock() { return m_block; }

	class Asteroids* getAsteroids() { return m_asteroids; }

	class Life* getLife() { return m_life; }

	class Level* getcurrentlvel() { return m_current_level; }

	class PowerUpSp* getPowerUpsp() { return m_powerupSp;}

	class PowerUpl* getPowerUpL () { return m_powerupL; }

	class AlienShip* getAlienShip() { return m_alienship; }

	class win* getWinLevel() { return m_current_levelll; }

	void setCurrentLevel(Gameover* level) { m_current_levell = level; } 

	void setWinLevel(win* level) { m_current_levelll = level; }





	


};
