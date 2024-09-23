get_filename_component(CURRENT_DIR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

add_library(${CURRENT_DIR_NAME} STATIC 
                                OpenGLRenderer.cpp 
                                Buffers/VertexBuffer.cpp 
                                Buffers/IndexBuffer.cpp 
                                Buffers/VertexBufferLayout.cpp
                                Buffers/VertexArray.cpp
                                Shaders/Shader.cpp
                                Textures/Texture.cpp)
target_include_directories(${CURRENT_DIR_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(${CURRENT_DIR_NAME} OpenGL::GL glfw glad stb_image)