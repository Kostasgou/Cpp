#include "box.h"
#include "alienship.h"
#include "util.h"
#include <cmath>
#include "player.h"
void AlienShip::update(float dt)
{
    float delta_time = dt / 1000.0f;

    // Αν ο μετρητής είναι ενεργός, μείωσέ τον
    if (m_slow_down_timer > 0.0f)
    {
        m_slow_down_timer -= delta_time;
        if (m_slow_down_timer <= 0.0f)
        {
            // Επανέφερε την ταχύτητα στην αρχική τιμή
            m_speed = m_original_speed;
            
        }
    }

    float xDistance = abs(m_state->getPlayer()->m_pos_x - m_pos_x);
    float yDistance = abs(m_state->getPlayer()->m_pos_y - m_pos_y);



    float yy = m_state->getPlayer()->m_pos_y - m_pos_y;
    float xx = m_state->getPlayer()->m_pos_x - m_pos_x;

    float kk = sqrt(xx * xx + yy * yy);

    xx /= kk;
    yy /= kk;



    m_pos_y += yy * delta_time * delta_time * m_speed;
    GameObject::update(dt);








    GameObject::update(dt);


}

void AlienShip::draw()
{
    float x = m_pos_x + m_state->m_global_offset_x;
    float y = m_pos_y + m_state->m_global_offset_y;

    alienship_brush.texture = m_state->getFullAssetPath("aliens.png");

    graphics::drawRect(x, y, 1.8 * w_g, 1.8 * h_g, alienship_brush);

    if (m_state->m_debugging)
        graphics::drawRect(x, y, w_g, h_g, alienship_brush_debug);

}




void AlienShip::init()
{
    Box(m_pos_x, m_pos_y, w_g, h_g);
    alienship_brush.outline_opacity = 0.0f;
    alienship_brush_debug.fill_opacity = 0.1f;
    SETCOLOR(alienship_brush_debug.fill_color, 0.1f, 1.0f, 0.1f);
    SETCOLOR(alienship_brush_debug.outline_color, 0.3f, 1.0f, 0.2f);

}


