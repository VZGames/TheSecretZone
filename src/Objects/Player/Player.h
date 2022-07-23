#ifndef __Player_H__
#define __Player_H__

#include "../GameObject.h"
#include "../../Animation/Animation.h"
#include "../../Input/Input.h"
class Player : public GameObject
{
private:
    Animation *m_Animation;
    int m_CurrentRow = 1;

public:
    Player(Properties *p_Props);
    void Render() override;
    void Update(float p_DeltaTime) override;
    void Clean() override;
};
#endif // __Player_H__