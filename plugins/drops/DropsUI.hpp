// TODO Add license

#include "DistrhoPluginInfo.h"
#include "DistrhoUI.hpp"
#include "NanoVG.hpp"
#include "Window.hpp"
#include <sndfile.hh>
#include <vector>
#include "TextButton.hpp"
#include "ScrollBar.hpp"
#include "artwork.hpp"

START_NAMESPACE_DISTRHO

// -----------------------------------------------------------------------------------------------------------

class DropsUI : public UI,
                public TextButton::Callback,
                public ScrollBar::Callback
{
public:
    DropsUI();

protected:
    void parameterChanged(uint32_t index, float value) override;
    void onNanoDisplay() override;
    void uiFileBrowserSelected(const char *filename) override;
    void stateChanged(const char *key, const char *value) override;
    bool onMouse(const MouseEvent &ev) override;
    bool onScroll(const ScrollEvent &) override;
    bool onMotion(const MotionEvent &) override;
    void textButtonClicked(TextButton *textButton) override;
    void scrollBarClicked(ScrollBar *scrollBar, bool dragging) override;

private:
    template <class T>
    const T &clamp(const T &x, const T &upper, const T &lower)
    {
        return std::min(upper, std::max(x, lower));
    }

    ScopedPointer<TextButton> fFileOpenButton;
    ScopedPointer<ScrollBar> fScrollBarHandle, fLoopStart, fLoopEnd, fSampleIn, fSampleOut, fScrollBarLeft, fScrollBarRight;
    NanoImage imgLoopStart, imgLoopEnd;
    void initWidgets();
    int loadSample(const char *fp);
    void drawWaveform();
    void drawMinimap();
    void drawLoopMarkers();
    void drawInOutMarkers();
    void scrollWaveform( bool leftright);
    void setMarkers();
    void setScrollbarWidgets();
    bool scrollbarDragging, loopstartDragging, loopendDragging, sampleInDragging, sampleOutDragging;
    bool sampleLoaded;
    char *filepath;
    sf_count_t sampleLength;
    int sampleChannels;
    int file_samplerate;
    // sample
    sf_count_t sampleIn, sampleOut, sampleLoopStart, sampleLoopEnd;

    std::vector<signed char> waveForm;
    std::vector<char> miniMap;
    sf_count_t viewStart;
    sf_count_t viewEnd;
    float viewZoom;
    float viewMaxZoom;
    int mouseX, mouseY;
    Rectangle<int> display;

    static constexpr unsigned int display_left = 32;
    static constexpr unsigned int display_top = 100;
    static constexpr unsigned int display_width = 1000 - 64 ;
    static constexpr unsigned int display_right = display_left + display_width;
    static constexpr unsigned int display_height = 190;
    static constexpr unsigned int display_bottom = display_top + display_height;
    static constexpr unsigned int display_center = (display_bottom - display_top) / 2 + display_top;
    static constexpr unsigned int minimap_height = 35;
    static constexpr unsigned int scrollbarHandle_id = 900;
    static constexpr unsigned int scrollbarLeft_id = 901;
    static constexpr unsigned int scrollbarRight_id = 902;
    
    static constexpr unsigned int sample_inout_font_size = 12;

    DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DropsUI)
};

END_NAMESPACE_DISTRHO