
#ifndef main_view_controller_h
#define main_view_controller_h

#include <mono.h>
#include "scene.h"
#include "icon_view.h"

using namespace mono;
using namespace mono::ui;
using namespace mono::geo;

class IconRepeatVert : public View {
    
    const MonoIcon *icon;
    
public:
    
    Color front, back;
    
    IconRepeatVert(const Rect &rct, const MonoIcon &icon);
    
    void repaint();
    
};

class MainViewController : public Scene {
protected:
    
    bool celcius;
    int oldTemp;
    TextLabelView tempLbl;
    IconView bubleView, tempballView;
    IconRepeatVert warmThermView, coldThermView;
    
public:
    
    MainViewController();
    
    void setTemp(int t);
    
};

#endif /* main_view_controller_h */
