#ifndef APPLICATION_H
#define APPLICATION_H

#include "Render/OpenGL/OpenGLRenderer.h"

class APPLICATION{
    public:
        
        virtual ~APPLICATION() = default;

       void addOpenGLRender(const OpenGLRenderer &Rendrer); 

        void Run();
    
    private:
       OpenGLRenderer m_OpenGLRender;
        
};

#endif