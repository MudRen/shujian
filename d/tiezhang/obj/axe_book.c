//axe_book.c ������Ҫ
inherit ITEM;

void create()
{
        set_name("������Ҫ", ({ "fufa gaiyao", "gaiyao","shu","book"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����츫�������Ÿ�Ҫ��\n");
                set("unique", 1);
                set("treasure",1);                              
                set("value", 1000);
                set("material", "paper");
                set("skill", 
                ([
                        "name": "axe",          // name of the skill
                        "exp_required": 0,      // minimum combat experience required
                        "jing_cost":    20,     // jing cost every time study this
                        "difficulty":   10,     // the base int to learn this skill
                        "max_skill":    30      // the maximum level you can learn
                ]));
        }
}
