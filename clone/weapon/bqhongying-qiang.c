// hongying-qiang.c 红缨枪

#include <ansi.h>
#include <weapon.h>
inherit SPEAR;

void create()
{
        set_name(RED"红缨白蜡大枪"NOR , ({ "hongying qiang", "qiang", "spear","hongying" }));
       set_weight(1200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "此枪由白腊杆制成,长丈三有余，通体洁白如玉、坚而不硬、柔而不折。枪头由精钢打制，锐利无匹。\n");
                set("value", 70000);
                set("no_sell", 1);
                set("material", "steel");
                set("wield_msg", "$N轻轻一抖手中$n，只见枪尖突如闪电，在空中点出七朵梨花。\n");
                set("unwield_msg", "$N将手中$n一抖，斜斜抗在肩上。\n");
        }
        init_spear(80);
        setup();
}
