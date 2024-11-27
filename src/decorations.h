#ifndef SCROLLER_DECORATIONS_H
#define SCROLLER_DECORATIONS_H

#include <hyprland/src/render/decorations/IHyprWindowDecoration.hpp>
#include <hyprland/src/render/Texture.hpp>

class Window;

class SelectionBorders : public IHyprWindowDecoration {
  public:
    SelectionBorders(Window *);
    virtual ~SelectionBorders();

    virtual SDecorationPositioningInfo getPositioningInfo();
    virtual void                       onPositioningReply(const SDecorationPositioningReply& reply);
    virtual void                       draw(PHLMONITOR, float const& a);
    virtual eDecorationType            getDecorationType();
    virtual void                       updateWindow(PHLWINDOW);
    virtual void                       damageEntire();
    virtual eDecorationLayer           getDecorationLayer();
    virtual uint64_t                   getDecorationFlags();
    virtual std::string                getDisplayName();

  private:
    const Window *window;

    SBoxExtents  m_seExtents;
    SBoxExtents  m_seReportedExtents;
    PHLWINDOWREF m_pWindow;
    Vector2D     m_vLastWindowPos;
    Vector2D     m_vLastWindowSize;
    CBox         m_bAssignedGeometry = {0};
    int          m_iLastBorderSize = -1;
    CBox         assignedBoxGlobal();
    bool         doesntWantBorders();
};

class JumpDecoration : public IHyprWindowDecoration {
  public:
    JumpDecoration(PHLWINDOW, int nchars, int number);
    virtual ~JumpDecoration();

    virtual SDecorationPositioningInfo getPositioningInfo();
    virtual void                       onPositioningReply(const SDecorationPositioningReply& reply);
    virtual void                       draw(PHLMONITOR, float const& a);
    virtual eDecorationType            getDecorationType();
    virtual void                       updateWindow(PHLWINDOW);
    virtual void                       damageEntire();
    virtual eDecorationLayer           getDecorationLayer();
    virtual uint64_t                   getDecorationFlags();
    virtual std::string                getDisplayName();

    int getNumber() const { return m_iNumber; }

  private:
    PHLWINDOWREF m_pWindow;
    CBox m_bAssignedGeometry = { 0 };
    CBox assignedBoxGlobal();

    int m_iChars;
    int m_iNumber;
    SP<CTexture> m_pTexture;
};

#endif  // SCROLLER_DECORATIONS_H