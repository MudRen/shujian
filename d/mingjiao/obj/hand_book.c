// hand_book.c

inherit ITEM;

void create()
{
        set_name("ӥצ�ַ�", ({ "yingzhua shoufa", "shoufa", "book" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ�����������ַ�Ҫ����鼮��\n");
                set("value", 100);
                set("material", "paper");
                set("unique", 1);
                set("treasure",1);
                set("skill", ([
                        "name":"hand",       // name of the skill
                        "exp_required": 1000, // minimum combat experience required
                                              // to learn this skill.
                        "jing_cost": 20,      // jing cost every time study this
                        "difficulty": 20,     // the base int to learn this skill
                                              // modify is jing_cost's (difficulty - int)*5%
                        "max_skill": 30       // the maximum level you can learn
                                              // from this object.
                ]));
        }
}

