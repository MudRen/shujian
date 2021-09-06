//item xionghuang 雄黄

inherit FIRE_ITEM;
#include <ansi.h>

void create()
{
        set_name( HIY"雄黄"NOR, ({ "xiong huang" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
        set("long", "这是一块产于煌山之阳的雄黄石，杀诸蛇虺毒，解藜芦毒。\n");
                set("unit", "块");
                set("value", 1000);
        }
        setup();
}


