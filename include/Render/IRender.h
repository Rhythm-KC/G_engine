#ifndef IRENDER_H
#define IRENDER_H

class IRender 
{
    public:
        ~IRender() = default;

        virtual void Initialize() = 0;
        virtual void render() = 0;

};

#endif