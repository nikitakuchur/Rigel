#ifndef RIGEL_TEXTURE_RECTANGLE_H
#define RIGEL_TEXTURE_RECTANGLE_H

#include <string>

namespace rigel {
    class TextureRectangle {
    private:
        unsigned int m_textureId;
        std::string m_path; // File path
        unsigned char *m_localBuffer; // Local storage for the texture
        int m_width; // Width of the texture
        int m_height; // Height of the texture
        int m_bpp; // Bits per pixel

    public:
        TextureRectangle(const std::string &path);
        ~TextureRectangle();

        void bind(unsigned int slot = 0) const;
        void unbind() const;

        inline int getWidth() const { return m_width; }

        inline int getHeight() const { return m_height; }
    };
}

#endif //RIGEL_TEXTURE_RECTANGLE_H
