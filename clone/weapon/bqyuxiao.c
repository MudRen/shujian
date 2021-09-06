// yuxiao.c 玉箫

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
        set_name(HIG"玉箫"NOR, ({ "yu xiao", "xiao" }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("long", "这是一只由上好的翠玉精心磨制而成的玉箫，通身碧绿，近吹口处有几点朱斑，殷红如血。\n");
                set("value", 42000);
                set("no_sell", 1);
                set("material", "steel");
                set("wield_msg", "$N伸手轻轻一招，一支$n已出现在$N手中。\n");
                set("unwield_msg", "$N一声清啸，将手中的$n插回腰间。\n");
        }
        init_sword(80);
        setup();
}
