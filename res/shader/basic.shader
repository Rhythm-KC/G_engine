#shader vertex
#version 410 core
layout(location = 0) in vec4 position;
layout(location = 1) in vec2 texCoord;
out vec2 v_texCoord;
void main()
{
gl_Position = position;
v_texCoord = texCoord;
}

#shader fragment
#version 410 core
layout(location = 0) out vec4 color;

in vec2 v_texCoord;
uniform sampler2D u_Texture;
void main()
{
vec4 texcolor = texture(u_Texture, v_texCoord);
color = texcolor;

}