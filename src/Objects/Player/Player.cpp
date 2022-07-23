#include "Player.h"
Player::Player(Properties *p_Props)
    : GameObject(p_Props)
{
    m_Animation = new Animation();
    m_Animation->SetProps(p_Props->m_TexTureID, 1, 2, 200);
}

void Player::Render()
{
    m_Animation->Draw(m_Transform->m_Position, m_Properties->m_Width, m_Properties->m_Height);
}

void Player::Update(float p_DeltaTime)
{
    m_Animation->SetProps(m_Properties->m_TexTureID, m_CurrentRow, 2, 160);

    if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_A))
    {
        m_CurrentRow = 3;
        m_Animation->SetProps(m_Properties->m_TexTureID, 3, 4, 160);
        m_Transform->TranslateX(BACKWARD);
    }
    if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_D))
    {
        m_CurrentRow = 4;
        m_Animation->SetProps(m_Properties->m_TexTureID, 4, 4, 160);
        m_Transform->TranslateX(FORWARD);
    }
    if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_W))
    {
        m_CurrentRow = 2;
        m_Animation->SetProps(m_Properties->m_TexTureID, 2, 4, 160);
        m_Transform->TranslateY(UPWARD);
    }
    if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_S))
    {
        m_CurrentRow = 1;
        m_Animation->SetProps(m_Properties->m_TexTureID, 1, 4, 160);
        m_Transform->TranslateY(DOWNWARD);
    }

    m_Animation->Update();
}

void Player::Clean()
{
}
