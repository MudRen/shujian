#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"��������ѧ"NOR, ({ "jingmai book", "book", "shu" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 5000);
                set_weight(10);
                set("material", "paper");
                set("skill", ([
                        "name": "jingmai-xue",
                        "jing_cost":    10,
                        "difficulty":   25,
                        "min_skill":    0,
                        "max_skill":    40
                ]) );
        }
        setup();
}

