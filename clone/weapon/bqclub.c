// weapon: tiegun.c
// Jay 3/18/96

#include <weapon.h>
#include <ansi.h>


inherit CLUB;

void create()
{
        set_name(HIC"齐眉棍"NOR, ({ "tiegun", "gun" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是一根以白蜡杆制成，粗有盈把的齐眉棍。自十三棍僧救唐王之后，少林棍名扬天下，话说枪挑一条线，棍打一大片,棍号称百兵之首。\n");
                set("value", 50000);
                set("material", "iron");
                set("wield_msg", "$N跨了个马步，抖了抖手中的$n。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        init_club(50);
        setup();
}

