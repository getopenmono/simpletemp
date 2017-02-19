
#include "main_view_controller.h"
#include "buble.h"
#include "tempball.h"
#include "therm-warm.h"
#include "therm-cold.h"

#include <Fonts/FreeSans18pt7b.h>

const display::Color OrangeColor(241, 196, 15);

MainViewController::MainViewController() :
    tempLbl(Rect(10, 50, 120, 92), "20.0 C"),
    bubleView(Point(10,50), mono::display::buble),
    tempballView(Point(138,160), tempball),
    warmThermView(Rect(148, 110, 10, 50), thermWarm),
    coldThermView(Rect(148, 25, 10, 110-25), thermCold)
{
    celcius = true;
    oldTemp = 0;
    
    setBackground(CloudsColor);
    
    tempLbl.setText(display::WhiteColor);
    tempLbl.setBackground(MidnightBlueColor);
    tempLbl.setAlignment(TextLabelView::ALIGN_CENTER);
    tempLbl.setFont(FreeSans18pt7b);
    
    bubleView.setForeground(MidnightBlueColor);
    bubleView.setBackground(BackgroundColor());
    
    tempballView.setForeground(OrangeColor);
    tempballView.setBackground(BackgroundColor());

    warmThermView.front = OrangeColor;
    warmThermView.back = BackgroundColor();
    
    coldThermView.front = BelizeHoleColor;
    coldThermView.back = BackgroundColor();
    
    addView(tempballView);
    addView(warmThermView);
    addView(coldThermView);
    
    addView(bubleView);
    addView(tempLbl);
    
}


void MainViewController::setTemp(int t)
{
    if (t == oldTemp)
        return;

    if (celcius)
    {
        int integer = t / 1000;
        int decimal = (t - integer*1000) / 100;
        tempLbl.setText(String::Format("%d.%d C", integer, decimal));
    }
    
    // change thermometer proportions
    int a = 135/45;
    int b = 5000*a;
    int len = (t*a + b) / 1000;
    class Size s(10, 135-len);
    
    coldThermView.setSize(s);
    warmThermView.setRect(Rect(warmThermView.ViewRect().X(),
                               coldThermView.ViewRect().Y2(),
                               10,
                               len));
    
    coldThermView.scheduleRepaint();
    warmThermView.scheduleRepaint();
    
    oldTemp = t;
}

// MARK: Icon Repeater class

IconRepeatVert::IconRepeatVert(const Rect &rct, const MonoIcon &icn) : View(rct)
{
    icon = &icn;
}

void IconRepeatVert::repaint()
{
    int times = viewRect.Height() / icon->height;
    IconView view(viewRect, *icon);
    view.setForeground(front);
    view.setBackground(back);
    
    for(int t=0; t<times; t++)
    {
        Point p(viewRect.X(), viewRect.Y() + t*icon->height);
        view.setPosition(p);
        view.repaint();
    }
}
