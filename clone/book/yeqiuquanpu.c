// yeqiuquanpu.c

#include <armor.h>

inherit ITEM;

void create()
{
        set_name("Ұ��ȭȭ��", ({ "yeqiuquan pu", "quanpu", "shu", "book" }));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "����һ��Ұ��ȭȭ��,���������¾���Ұ��ȭ��\n");
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
