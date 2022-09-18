#ifndef LAYER_H
#define LAYER_H

class Layer
{
public:
    Layer() {}
    virtual void Update() = 0;
    virtual void Render() = 0;
};
#endif // LAYER_H
