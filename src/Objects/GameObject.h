#ifndef __GAME_OBJECT_H__
#define __GAME_OBJECT_H__

class GameObject
{
protected:
    /* data */
public:
    GameObject() {}
    virtual void Render() = 0;
    virtual void Update() = 0;
    virtual void Clean() = 0;
};

#endif // __GAME_OBJECT_H__