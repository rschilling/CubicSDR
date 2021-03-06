#pragma once

#include "wx/glcanvas.h"
#include "wx/timer.h"

#include "MouseTracker.h"
#include <string>

class InteractiveCanvas: public wxGLCanvas {
public:
    InteractiveCanvas(wxWindow *parent, int *dispAttrs);
    ~InteractiveCanvas();

    long long getFrequencyAt(float x);
    long long getFrequencyAt(float x, long long iqCenterFreq, long long iqBandwidth);
    
    virtual void setView(long long center_freq_in, int bandwidth_in);
    virtual void disableView();
    bool getViewState();

    void setCenterFrequency(long long center_freq_in);
    long long getCenterFrequency();

    void setBandwidth(unsigned int bandwidth_in);
    unsigned int getBandwidth();

    MouseTracker *getMouseTracker();
    bool isMouseInView();
    bool isMouseDown();
    
    bool isAltDown();
    bool isCtrlDown();
    bool isShiftDown();

protected:
    void OnKeyDown(wxKeyEvent& event);
    void OnKeyUp(wxKeyEvent& event);

    void OnMouseMoved(wxMouseEvent& event);
    void OnMouseWheelMoved(wxMouseEvent& event);
    void OnMouseDown(wxMouseEvent& event);
    void OnMouseReleased(wxMouseEvent& event);
    void OnMouseRightDown(wxMouseEvent& event);
    void OnMouseRightReleased(wxMouseEvent& event);
    void OnMouseEnterWindow(wxMouseEvent& event);
    void OnMouseLeftWindow(wxMouseEvent& event);

    void setStatusText(std::string statusText);
    void setStatusText(std::string statusText, int value);

    wxWindow *parent;
    MouseTracker mouseTracker;

    bool shiftDown;
    bool altDown;
    bool ctrlDown;

    long long centerFreq;
    unsigned int bandwidth;
    unsigned int lastBandwidth;

    bool isView;
	std::string lastToolTip;
};

