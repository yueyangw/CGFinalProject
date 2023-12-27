#version 330 core
out vec4 FragColor;

in vec2 TexCoord;

uniform sampler2D texture1;    // 主纹理
uniform sampler2D noiseTexture; // 噪声纹理
uniform float time;

void main()
{
    // 从噪声纹理中获取噪声值
    vec3 noise = texture(noiseTexture, TexCoord).rgb;

    // 使用噪声值和时间来扰动纹理坐标
    float xFlow = TexCoord.x + noise.r * sin(time) * 0.02;
    float yFlow = TexCoord.y + noise.r * cos(time) * 0.02;

    vec2 uv = vec2(xFlow, yFlow);

    // 纹理采样并输出颜色
    vec3 color = texture(texture1, uv).rgb;
    FragColor = vec4(color, 1.0);
}