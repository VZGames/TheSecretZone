#ifndef __Player_H__
#define __Player_H__

#include "../GameObject.h"
#include "../../Animation/Animation.h"
#include "../../Input/Input.h"

class Animation;

class Player : public GameObject
{
private:
    Animation *m_Animation;
    int m_CurrentRow = 1;

public:
    Player();
    Player(Properties *p_Props);
    ~Player();
    virtual void Render() override;
    virtual void Update(float p_DeltaTime) override;
    virtual void Clean() override;
};
#endif // __Player_H__
