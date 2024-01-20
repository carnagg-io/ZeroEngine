#ifndef GRAPHICSSETTINGS_H
#define GRAPHICSSETTINGS_H

namespace ZEngine
{
    class GraphicsSettings
    {
    private:
        unsigned int m_uResX;
        unsigned int m_uResY;

    protected:
        GraphicsSettings();
        ~GraphicsSettings();

        static GraphicsSettings* m_instance;

    public:
        GraphicsSettings(GraphicsSettings& ref) = delete;
        void operator = (const GraphicsSettings&) = delete;

        static GraphicsSettings* instance();

        unsigned int resX();
        unsigned int resY();
    };
}

#endif // GRAPHICSSETTINGS_H