#include "box.h"
#include "asteroids.h"
#include "util.h"
#include <cmath>
#include "player.h"

void Asteroids::update(float dt)
{
    float delta_time = dt / 1000.0f;

    

    float yy = m_state->getPlayer()->m_pos_y - m_pos_y;
    float xx = m_state->getPlayer()->m_pos_x - m_pos_x;

    float kk = sqrt(xx * xx + yy * yy);

    xx /= kk;
    yy /= kk;

    m_pos_y += yy * delta_time * delta_time * 200; // Χρησιμοποίησε την τρέχουσα ταχύτητα
    GameObject::update(dt);
}

void Asteroids::draw()
{
    float x = m_pos_x + m_state->m_global_offset_x;
    float y = m_pos_y + m_state->m_global_offset_y;

    Asteroids_brush.texture = m_state->getFullAssetPath("asteroid1.png");

    graphics::drawRect(x, y, 1.8 * w_g, 1.8 * h_g, Asteroids_brush);

    if (m_state->m_debugging)
        graphics::drawRect(x, y, w_g, h_g, Asteroids_brush_debug);

}




void Asteroids::init()
{
    Box(m_pos_x, m_pos_y, w_g, h_g);
    Asteroids_brush.outline_opacity = 0.0f;
    Asteroids_brush_debug.fill_opacity = 0.1f;
    SETCOLOR(Asteroids_brush_debug.fill_color, 0.1f, 1.0f, 0.1f);
    SETCOLOR(Asteroids_brush_debug.outline_color, 0.3f, 1.0f, 0.2f);

}




