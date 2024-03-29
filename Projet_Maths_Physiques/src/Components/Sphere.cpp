#include "Components/Sphere.h"


Sphere::Sphere(unsigned int sectorCount, unsigned int stackCount): sectorCount_(sectorCount), stackCount_(stackCount)
{
    objectType_ = SphereMesh;
    float x, y, z, xy;                              // vertex position
    float nx, ny, nz, lengthInv = 1.0f;    // vertex normale
    float s, t;                                     // vertex texCoord

    float sectorStep = 2 * static_cast<float>(M_PI) / sectorCount_;
    float stackStep = static_cast<float>(M_PI) / stackCount_;
    float sectorAngle, stackAngle;

    for (unsigned int i = 0; i <= stackCount_; ++i)
    {
        stackAngle = static_cast<float>(M_PI) / 2 - i * stackStep;        // commence de pi/2 � -pi/2
        xy = cosf(stackAngle);             // cos(u)
        z = sinf(stackAngle);              // sin(u)

        // ajoute (sectorCount+1) vertices par latitude
        //les premier et dernier vertices ont la meme position et normale, mais des diff�rentes coordonn�es de texture
        for (unsigned int j = 0; j <= sectorCount_; ++j)
        {
            sectorAngle = j * sectorStep;           // on commence de 0 � 2pi

            // vertex position (x, y, z)
            x = xy * cosf(sectorAngle);           // r * cos(u) * cos(v)
            y = xy * sinf(sectorAngle);             // r * cos(u) * sin(v)

            // normale au vertex normalis�e (nx, ny, nz)
            nx = x * lengthInv;
            ny = y * lengthInv;
            nz = z * lengthInv;

            // coordonn�e de texture du vertex (s, t) entre [0, 1]
            s = (float)j / sectorCount;
            t = (float)i / stackCount;


            vertices_.push_back({x, y, z, nx, ny, nz, s, t});

       
            
        }
    }

    int k1, k2;
    for (unsigned int i = 0; i < stackCount_; ++i)
    {
        k1 = i * (sectorCount_ + 1);     // d�but de la latitude actuelle
        k2 = k1 + sectorCount_ + 1;      // d�but de la latitude suivante

        for (unsigned int j = 0; j < sectorCount_; ++j, ++k1, ++k2)
        {
            // 2 triangles par longitude en excluant la premi�re et derni�re latitude
            // k1 => k2 => k1+1
            if (i != 0)
            {
                indices_.push_back(k1);
                indices_.push_back(k2);
                indices_.push_back(k1 + 1);
            }

            // k1+1 => k2 => k2+1
            if (i != (stackCount - 1))
            {
                indices_.push_back(k1 + 1);
                indices_.push_back(k2);
                indices_.push_back(k2 + 1);
            }
        }
    }
}