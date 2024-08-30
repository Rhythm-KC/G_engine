#ifndef IRENDER_H
#define IRENDER_H

class IRender{
    public:
        virtual ~IRender() = default;

        virtual void Initialize() = 0;
        virtual void Cleanup() = 0;

        // Rendering operations
        virtual void BeginFrame() = 0;
        virtual void EndFrame() = 0;
    
        virtual void DrawTriangle(float vertices[9]) = 0;
};

#endif