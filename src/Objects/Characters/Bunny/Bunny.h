#ifndef __BUNNY_H__
#define __BUNNY_H__

#include "../../GameObject.h"
class Bunny : public GameObject
{
private:
    Bunny();

    static Bunny *s_Instance;

public:
    void Render() override;
    void Update() override;
    void Clean() override;

    static Bunny *GetInstance() { return s_Instance = (s_Instance == nullptr) ? new Bunny() : s_Instance; }
};
#endif // __BUNNY_H__