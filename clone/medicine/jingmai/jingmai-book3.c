#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"�߼�����ѧ"NOR, ({ "jingmai book", "book", "shu" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 100000);
                set_weight(10);
                set("material", "paper");
                set("skill", ([
                        "name": "jingmai-xue",
                        "jing_cost":    20,
                        "difficulty":   25,
                        "min_skill":    80,
                        "max_skill":    120
                ]) );
        }
        setup();
}

