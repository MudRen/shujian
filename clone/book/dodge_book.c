// yeqiuquanpu.c

#include <armor.h>

inherit ITEM;

void create()
{
        set_name("���в�����Ҫ", ({ "wuxing book", "gaiyao", "shu", "book" }));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "����һ���������в�����Ҫ���飬���ڽ��������ߵ��˶��������ӡ�\n");
                set("value", 500);
                set("material", "steel");
               // set("treasure", 1);
                set("skill", ([
                        "name": "wuxingbu",      // name of the skill
                        "exp_required": 0,  // minimum combat experience required
                        "jing_cost":    0,     // jing cost every time study this
                        "difficulty":   0,     // the base int to learn this skill
                        "max_skill":    81      // the maximum level you can learn
                ]) );
        }
}
