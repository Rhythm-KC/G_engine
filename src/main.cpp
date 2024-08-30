#include <iostream>
#include <memory.h>
#include <GLFW/glfw3.h>

#include "Test/adder.h"
#include "Render/IRender.h"
#include "Render/OpenGLRenderer.h"

int main(){
    int x = add(2, 5);
   std::cout << "hello world" << x << std::endl;
   std::unique_ptr<IRender> renderer = std::make_unique<OpenGLRenderer>();
   renderer->Initialize();
   return 0;
}