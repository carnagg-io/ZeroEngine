#include "Settings\GraphicsSettings.h"

namespace ZEngine
{
    GraphicsSettings* GraphicsSettings::m_instance = nullptr;

    GraphicsSettings::GraphicsSettings()
    {
        m_uResX = 1920;
        m_uResY = 1080;
    }

    GraphicsSettings::~GraphicsSettings()
    {
    }

    GraphicsSettings* GraphicsSettings::instance()
    {
        if (m_instance == nullptr)
        {
            m_instance = new GraphicsSettings();
        }
        return m_instance;
    }

    unsigned int GraphicsSettings::resX()
    {
        return m_uResX;
    }

    unsigned int GraphicsSettings::resY()
    {
        return m_uResY;
    }
}