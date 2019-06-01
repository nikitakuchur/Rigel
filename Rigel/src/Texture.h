#pragma once

#include <string>

class Texture
{
private:
    unsigned int m_textureId;
    std::string m_path; // File path
    unsigned char* m_localBuffer; // Local storage for the texture
    int m_width; // Width of the texture
    int m_height; // Height of the texture
    int m_bpp; // Bits per pixel

public:
    Texture(const std::string& path);
    ~Texture();

    void bind(unsigned int slot = 0) const;
    void unbind() const;

    inline int getWidth() const { return m_width; }
    inline int getHeight() const { return m_height; }
};