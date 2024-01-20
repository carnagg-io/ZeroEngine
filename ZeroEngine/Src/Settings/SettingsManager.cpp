#include "Settings\SettingsManager.h"

namespace ZEngine
{
    SettingsManager* SettingsManager::m_instance = nullptr;

    SettingsManager::SettingsManager()
    {
    }

    SettingsManager::~SettingsManager()
    {
    }

    void SettingsManager::initialize()
    {
        m_instance = new SettingsManager();
        m_settingsGraphics = GraphicsSettings::instance();
    }

    SettingsManager* SettingsManager::instance()
    {
        if (m_instance == nullptr)
        {
            m_instance->initialize();
        }
        return m_instance;
    }

    GraphicsSettings* SettingsManager::graphics()
    {
        return m_settingsGraphics;
    }
}