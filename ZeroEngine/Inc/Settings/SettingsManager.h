#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H

#include "Settings\GraphicsSettings.h"

namespace ZEngine
{
    class SettingsManager
    {
    private:
        void initialize();

    protected:
        SettingsManager();
        ~SettingsManager();

        static SettingsManager* m_instance;
        static GraphicsSettings* m_settingsGraphics;

    public:
        SettingsManager(SettingsManager& ref) = delete;
        void operator = (const SettingsManager&) = delete;

        static SettingsManager* instance();
        static GraphicsSettings* graphics();
    };
}

#endif // SETTINGSMANAGER_H