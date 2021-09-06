// yeqiuquanpu.c

#include <armor.h>

inherit ITEM;

void create()
{
        set_name("野球拳拳谱", ({ "yeqiuquan pu", "quanpu", "shu", "book" }));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
                        "这是一本野球拳拳谱,天下无难事就怕野球拳。\n");
                set("value", 10);
                set("material", "steel");
                set("treasure", 1);
                set("skill", ([
                        "name": "yeqiu-quan",      // name of the skill
                        "exp_required": 0,  // minimum combat experience required
                        "jing_cost":    0,     // jing cost every time study this
                        "difficulty":   0,     // the base int to learn this skill
                        "max_skill":    220      // the maximum level you can learn
                ]) );
        }
}
