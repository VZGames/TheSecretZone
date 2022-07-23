#ifndef __Player_H__
#define __Player_H__

#include "../GameObject.h"
class Player : public GameObject
{
private:
    Player(Properties *p_Props);

public:
    void Render() override;
    void Update() override;
    void Clean() override;
};
#endif // __Player_H__