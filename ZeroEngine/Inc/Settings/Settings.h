#ifndef SETTINGS_H
#define SETTINGS_H

namespace ZEngine
{
    class Settings
    {
    private:
        unsigned int m_uResX;
        unsigned int m_uResY;

    protected:
        Settings();
        ~Settings();

        static Settings* m_instance;

    public:
        Settings(Settings& ref) = delete;
        void operator = (const Settings&) = delete;

        static Settings* instance();

        unsigned int resX();
        unsigned int resY();
    };
}

#endif // SETTINGS_H