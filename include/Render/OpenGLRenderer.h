#ifndef OPENGLRENDERER_H
#define OPENGLRENDERER_H

#include "Render/IRender.h"
#include <GLFW/glfw3.h>

class OpenGLRenderer : public IRender{
    public:
        OpenGLRenderer();
        ~OpenGLRenderer();
        void Initialize() override;
        void Cleanup() override;

        void BeginFrame() override;
        void EndFrame() override;
    
        void DrawTriangle(float vertices[9]) override;
    private:
        GLFWwindow* window;
};

static void error_callback(int err, const char* description);

#endif