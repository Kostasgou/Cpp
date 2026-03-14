#include "level.h"
#include <sgg/graphics.h>
#include "player.h"
#include "block.h"
#include "util.h"
#include "box.h"
#include <iostream>
#include "asteroids.h"
#include "life.h"
#include "powerupSp.h"
#include "gameover.h"
#include "powerupL.h"
#include "alienship.h"
#include "win.h"





void Level::drawBlock(int i)
{
	GameObject* block = m_static_objects[i];
	block->draw();
}

void Level::drawAsteroids(int i) {
	GameObject* asteroids = m_dynamic_objects[i];
	asteroids->draw();
}

void Level::drawAlienShip(int i) {
	GameObject* alienships = alienship[i];
	alienships->draw();
}

void Level::drawPowerupSp(int i) {
	GameObject* powerup2 = powerupSp[i];
	powerup2->draw();
}

void Level::drawPowerupL(int i) {
	GameObject* powerup3 = powerupL[i];
	powerup3->draw();
}



void Level::checkCollisions()
{


	for (auto& blockk : m_static_objects)
	{


		float offset = 0.0f;
		Box* q = dynamic_cast<Box*>(blockk);

		if (offset = m_state->getPlayer()->intersectDown(*q))
		{
			printf("*");


			// add sound event
			if (m_state->getPlayer()->m_vy > 1.0f)
				graphics::playSound(m_state->getFullAssetPath("Metal2.wav"), 1.0f);



			break;
		}
	}

	for (auto& blockk : m_static_objects)
	{
		Box* q = dynamic_cast<Box*>(blockk);
		float offset = 0.0f;
		if (offset = m_state->getPlayer()->intersectSideways(*q))
		{
			m_state->getPlayer()->m_pos_x += offset;

			m_state->getPlayer()->m_vx = 0.0f;
			break;
		}

	}

	for (auto it = m_dynamic_objects.begin(); it != m_dynamic_objects.end(); )
	{
		Box* q = dynamic_cast<Box*>(*it);
		if (q && m_state->getPlayer()->intersectDown(*q))
		{
			point += 1;
			printf("Point: %d\n", point);
			// Check if the player has reached 10 points
			if (point == 10) { // Αν οι πόντοι φτάσουν στο 10
				m_state->count = 6; // Θέτουμε την τιμή του count στην κατάσταση win
				m_state->setWinLevel(new win("win")); // Δημιουργία αντικειμένου win
				m_state->getWinLevel()->init(); // Αρχικοποίηση του win level
				return;
			}


			// Play sound if required
			if (m_state->getPlayer()->m_vy > 1.0f)
				graphics::playSound(m_state->getFullAssetPath("Metal2.wav"), 1.0f);

			// Remove the collided object
			it = m_dynamic_objects.erase(it);
		}
		else
		{
			++it;
		}
	}


	// Έλεγχος σύγκρουσης από το πλάι (intersectSideways)
	for (auto it = m_dynamic_objects.begin(); it != m_dynamic_objects.end(); )
	{
		Box* q = dynamic_cast<Box*>(*it);
		float offset = 0.0f;
		if (q && (offset = m_state->getPlayer()->intersectSideways(*q)) != 0.0f)
		{
			point += 1;
			printf("Point: %d\n", point);

			// Check if the player has reached 10 points
			if (point == 10) { // Αν οι πόντοι φτάσουν στο 10
				m_state->count = 6; // Θέτουμε την τιμή του count στην κατάσταση win
				m_state->setWinLevel(new win("win")); // Δημιουργία αντικειμένου win
				m_state->getWinLevel()->init(); // Αρχικοποίηση του win level
				return;
			}
			// Μετακίνηση του παίκτη
			m_state->getPlayer()->m_pos_x += offset;
			m_state->getPlayer()->m_vx = 0.0f;

			// Διαγραφή του αντικειμένου
			it = m_dynamic_objects.erase(it);
		}
		else
		{
			++it;
		}
	}


	for (auto it = alienship.begin(); it != alienship.end(); )
	{
		Box* q = dynamic_cast<Box*>(*it);
		if (q && m_state->getPlayer()->intersectDown(*q))
		{


			// Παίξε ήχο αν απαιτείται
			if (m_state->getPlayer()->m_vy > 1.0f)
				graphics::playSound(m_state->getFullAssetPath("Metal2.wav"), 1.0f);
			loselife();

			// Διαγραφή του αντικειμένου
			it = alienship.erase(it);
		}
		else
		{
			++it;
		}
	}

	// Έλεγχος σύγκρουσης από το πλάι (intersectSideways)
	for (auto it = alienship.begin(); it != alienship.end(); )
	{
		Box* q = dynamic_cast<Box*>(*it);
		float offset = 0.0f;
		if (q && (offset = m_state->getPlayer()->intersectSideways(*q)) != 0.0f)
		{

			// Μετακίνηση του παίκτη
			m_state->getPlayer()->m_pos_x += offset;
			m_state->getPlayer()->m_vx = 0.0f;
			loselife();

			// Διαγραφή του αντικειμένου
			it = alienship.erase(it);
		}
		else
		{
			++it;
		}
	}



	for (auto it = powerupSp.begin(); it != powerupSp.end(); )
	{
		Box* q = dynamic_cast<Box*>(*it);
		if (q && m_state->getPlayer()->intersectDown(*q))
		{


			// Παίξε ήχο αν απαιτείται
			if (m_state->getPlayer()->m_vy > 1.0f)
				graphics::playSound(m_state->getFullAssetPath("Metal2.wav"), 1.0f);

			for (auto& aliens : alienship)
			{
				AlienShip* al = dynamic_cast<AlienShip*>(aliens);
				if (al)
				{
					al->m_speed *= 0.5f; // Reduce speed by 50%
					al->m_slow_down_timer = 10.0f; // Ρύθμισε τον χρονικό μετρητή
					
				}
			}

			// Διαγραφή του αντικειμένου
			it = powerupSp.erase(it);
		}
		else
		{
			++it;
		}
	}

	// Έλεγχος σύγκρουσης από το πλάι (intersectSideways)
	for (auto it = powerupSp.begin(); it != powerupSp.end(); )
	{
		Box* q = dynamic_cast<Box*>(*it);
		float offset = 0.0f;
		if (q && (offset = m_state->getPlayer()->intersectSideways(*q)) != 0.0f)
		{


			// Μετακίνηση του παίκτη
			m_state->getPlayer()->m_pos_x += offset;
			m_state->getPlayer()->m_vx = 0.0f;

			for (auto& aliens : alienship)
			{
				AlienShip* al = dynamic_cast<AlienShip*>(aliens);
				if (al)
				{
					al->m_speed *= 0.5f; // Reduce speed by 50%
					al->m_slow_down_timer = 10.0f; // Ρύθμισε τον χρονικό μετρητή
				}
			}

			// Διαγραφή του αντικειμένου
			it = powerupSp.erase(it);
		}
		else
		{
			++it;
		}
	}

	for (auto it = powerupL.begin(); it != powerupL.end(); )
	{
		Box* q = dynamic_cast<Box*>(*it);
		if (q && m_state->getPlayer()->intersectDown(*q))
		{


			// Παίξε ήχο αν απαιτείται
			if (m_state->getPlayer()->m_vy > 1.0f)
				graphics::playSound(m_state->getFullAssetPath("Metal2.wav"), 1.0f);

			// Increase player's life
			m_state->getPlayer()->increaseLife();

			// Διαγραφή του αντικειμένου
			it = powerupL.erase(it);
		}
		else
		{
			++it;
		}
	}

	// Έλεγχος σύγκρουσης από το πλάι (intersectSideways)
	for (auto it = powerupL.begin(); it != powerupL.end(); )
	{
		Box* q = dynamic_cast<Box*>(*it);
		float offset = 0.0f;
		if (q && (offset = m_state->getPlayer()->intersectSideways(*q)) != 0.0f)
		{


			// Μετακίνηση του παίκτη
			m_state->getPlayer()->m_pos_x += offset;
			m_state->getPlayer()->m_vx = 0.0f;

			// Increase player's life
			m_state->getPlayer()->increaseLife();

			// Διαγραφή του αντικειμένου
			it = powerupL.erase(it);
		}
		else
		{
			++it;
		}
	}








}

void Level::update(float dt) {
	std::vector<GameObject*> newDynamicObjects;

	for (auto it = m_dynamic_objects.begin(); it != m_dynamic_objects.end();) {
		Box* q = dynamic_cast<Box*>(*it);
		if (q && q->m_pos_y >= 4.9f) {
			delete* it;
			it = m_dynamic_objects.erase(it); // Διαγραφή και ενημέρωση iterator
			newDynamicObjects.push_back(new Asteroids("", randomX(), -5.0f)); // Νέα αντικείμενα
		}
		else {
			++it; // Επόμενος iterator
		}
	}

	// Εισαγωγή νέων αντικειμένων
	m_dynamic_objects.insert(m_dynamic_objects.end(), newDynamicObjects.begin(), newDynamicObjects.end());


	std::vector<GameObject*> newAlienshipObjects;
	// Update and remove off-screen alien ships
	for (auto it = alienship.begin(); it != alienship.end(); ) {
		Box* q = dynamic_cast<Box*>(*it);
		if (q && q->m_pos_y >= 4.9f && q->m_pos_x >= -20.0f && q->m_pos_x <= 20.0f) {
			delete* it;
			it = alienship.erase(it);
			// Add a new alien ship
			newAlienshipObjects.push_back(new AlienShip("", randomX(), -5.0f));
		}
		else {
			++it;
		}
	}
	// Εισαγωγή νέων αντικειμένων
	alienship.insert(alienship.end(), newAlienshipObjects.begin(), newAlienshipObjects.end());




	std::vector<GameObject*> newPowerupSpObjects;
	// Update and remove off-screen special power-ups
	for (auto it = powerupSp.begin(); it != powerupSp.end(); ) {
		Box* q = dynamic_cast<Box*>(*it);
		if (q && q->m_pos_y >= 4.9f && q->m_pos_x >= -20.0f && q->m_pos_x <= 20.0f) {
			delete* it;
			it = powerupSp.erase(it);
			// Add a new special power-up
			newPowerupSpObjects.push_back(new PowerUpSp("", randomX(), -5.0f));
		}
		else {
			++it;
		}
	}
	powerupSp.insert(powerupSp.end(), newPowerupSpObjects.begin(), newPowerupSpObjects.end());


	std::vector<GameObject*> newPowerupLObjects;
	// Update and remove off-screen life power-ups
	for (auto it = powerupL.begin(); it != powerupL.end(); ) {
		Box* q = dynamic_cast<Box*>(*it);
		if (q && q->m_pos_y >= 4.9f && q->m_pos_x >= -20.0f && q->m_pos_x <= 20.0f) {
			delete* it;
			it = powerupL.erase(it);
			// Add a new life power-up
			newPowerupLObjects.push_back(new PowerUpl("", randomX(), -5.0f));
		}
		else {
			++it;
		}
	}
	powerupL.insert(powerupL.end(), newPowerupLObjects.begin(), newPowerupLObjects.end());



	for (auto& blockk : alienship)
	{
		if (m_state->getAlienShip()->isActive())
			blockk->update(dt);
	}


	for (auto& blockk : powerupSp)
	{
		if (m_state->getPowerUpsp()->isActive())
			blockk->update(dt);
	}

	for (auto& blockk : powerupL)
	{
		if (m_state->getPowerUpL()->isActive())
			blockk->update(dt);
	}


	for (auto& blockk : m_dynamic_objects)
	{
		if (m_state->getAsteroids()->isActive())
			blockk->update(dt);
	}



	checkCollisions();


	if (m_state->getPlayer()->isActive())
		m_state->getPlayer()->update(dt);

	Box* q = dynamic_cast<Box*>(m_dynamic_objects[0]);
	if (m_state->getPlayer()->intersect(*q)) {
		printf("true");
	}


	if (m_state->getPlayer()->isActive())
		m_state->getPlayer()->update(dt);


	if (m_state->getblock()->isActive())
		m_state->getblock()->update(dt);

	if (m_state->getLife()->isActive())
		m_state->getLife()->update(dt);

	if (m_state->getPlayer()->isActive())
		m_state->getPlayer()->update(dt);

	if (m_state->getAsteroids()->isActive())
		m_state->getAsteroids()->update(dt);



	if (m_state->getAlienShip()->isActive())
		m_state->getAlienShip()->update(dt);

	if (m_state->getPowerUpsp()->isActive())
		m_state->getPowerUpsp()->update(dt);

	if (m_state->getPowerUpL()->isActive())
		m_state->getPowerUpL()->update(dt);

	if (m_state->getPlayer()->isActive())
		m_state->getPlayer()->update(dt);

	for (auto p_gob : newDynamicObjects)
		if (p_gob) p_gob->init();


	for (auto p_gob : newAlienshipObjects)
		if (p_gob) p_gob->init();

	for (auto p_gob : newPowerupSpObjects)
		if (p_gob) p_gob->init();

	for (auto p_gob : newPowerupLObjects)
		if (p_gob) p_gob->init();


	GameObject::update(dt);
}


void Level::loselife() {
	m_state->getPlayer()->life -= 1;

	if (m_state->getPlayer()->life == 0) {
		m_state->getPlayer()->setActive(false);
		m_state->getLife()->setActive(false);

		// Δημιουργία αντικειμένου Gameover
		m_state->count = 4;
		Gameover* gameoverScreen = new Gameover("gameover");
		gameoverScreen->init();
		m_state->setCurrentLevel(gameoverScreen);
		return;
	}
}

void Level::draw()
{



	float w = m_state->getCanvasWidth();
	float h = m_state->getCanvasHeight();

	float offset_x = m_state->m_global_offset_x / 2.0f + w / 2.0f;
	float offset_y = m_state->m_global_offset_y / 2.0f + h / 2.0f;

	//draw background
	graphics::drawRect(offset_x, offset_y, 3.0f * w, 3.0f * h, m_brush_background);





	for (int i = 0; i < m_static_objects.size(); i++)
	{
		drawBlock(i);


	}


	for (int i = 0; i < m_dynamic_objects.size(); i++)
	{
		drawAsteroids(i);



	}
	for (int i = 0; i < alienship.size(); i++)
	{
		drawAlienShip(i);



	}


	for (int i = 0; i < powerupSp.size(); i++)
	{
		drawPowerupSp(i);


	}

	for (int i = 0; i < powerupL.size(); i++)
	{
		drawPowerupL(i);


	}



	if (m_state->getPlayer()->isActive())
		m_state->getPlayer()->draw();
	if (m_state->getLife()->isActive())
		m_state->getLife()->draw();




}


float Level::randomX() {
	return static_cast<float>(rand() % 40 - 20); // Random X between -20 and 20
}
float Level::randomY() {
	return static_cast<float>(rand() % 25 + 5); // Random Y between 5 and 30
}

void Level::init()
{

	for (int i = 0; i < 100; i++) {

		m_static_objects.push_back(new block("", -20, i));
		m_static_objects.push_back(new block("", 20, i));

	}

	for (int i = 1; i < 20; i++) {
		m_dynamic_objects.push_back(new Asteroids("", -40, 2));
		ast = new Asteroids("", randomX(), randomY());
		m_dynamic_objects.push_back(ast);
	}


	for (int i = 1; i < 10; i++) {
		alienship.push_back(new AlienShip("", -40, 2));
		kll = new AlienShip("", randomX(), randomY());
		alienship.push_back(kll);
	}


	for (int i = 30; i < 40; i++) {
		powerupSp.push_back(new PowerUpSp("", -40, 2));
		ps = new PowerUpSp("", randomX(), randomY());
		powerupSp.push_back(ps);
	}
	for (int i = 40; i < 50; i++) {
		powerupL.push_back(new PowerUpl("", -40, 2));
		pl = new PowerUpl("", randomX(), randomY());
		powerupL.push_back(pl);
	}









	// Stage 1
	for (auto p_gob : m_static_objects)
		if (p_gob) p_gob->init();

	for (auto p_gob : m_dynamic_objects)
		if (p_gob) p_gob->init();


	for (auto p_gob : alienship)
		if (p_gob) p_gob->init();



	for (auto p_gob : powerupSp)
		if (p_gob) p_gob->init();

	for (auto p_gob : powerupL)
		if (p_gob) p_gob->init();







}

Level::Level(const std::string& name)
	: GameObject(name)
{

	m_brush_background.outline_opacity = 0.0f;
	m_brush_background.texture = m_state->getFullAssetPath("background.png");




}

Level::~Level()
{
	for (auto p_go : m_static_objects)
		delete p_go;

	for (auto p_go : m_dynamic_objects)
		delete p_go;

}
