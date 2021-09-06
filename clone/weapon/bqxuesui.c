#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
        set_name(WHT"碎雪刀"NOR,({ "xue sui", "blade", "dao", "sui","xue" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 45000);
                set("rigidity", 3);
                set("material", "steel");
		  set("no_sell", 1);
                set("wield_neili", 10);
                set("wield_maxneili", 100);
                set("wield_str", 20);                
                set("long", "这种刀背厚刃薄，用百淬精钢打造，刃口锋利无比，可以轻而易举把一个人劈成两半。\n刀法纯熟的人，在下雪夭舞刀时，一刀劈出，能把轻飘飘落下来的雪花劈成两半，所以才有了这样的名称。\n"); 
                set("wield_msg", "$N“唰”的一声从腰间抽出一把寒光凛冽的雪亮钢刀。\n");
                set("unwield_msg", "$N小心翼翼的摸了摸$n的刃口，竟然没有丝毫损伤。于是放心的将$n插回腰间。\n");
        }
        init_blade(80);
        setup();
}
