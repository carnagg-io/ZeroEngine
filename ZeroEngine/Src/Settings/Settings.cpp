#include "Settings\Settings.h"

namespace ZEngine
{
    Settings* Settings::m_instance = nullptr;

    Settings::Settings()
    {
        m_uResX = 1920;
        m_uResY = 1080;
    }

    Settings::~Settings()
    {
    }

    Settings* Settings::instance()
    {
        if (m_instance == nullptr)
        {
            m_instance = new Settings();
        }
        return m_instance;
    }

    unsigned int Settings::resX()
    {
        return m_uResX;
    }

    unsigned int Settings::resY()
    {
        return m_uResY;
    }
}