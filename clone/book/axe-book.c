// axe-book.c ��������
inherit ITEM;

void create()
{
        set_name("������Ҫ", ({ "fufa miyao", "book","shu"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��ѧϰ�����������顣\n");
                set("unique", 1);
                set("treasure",1);                              
                set("value", 1000);
                set("material", "paper");
                set("skill", 
                ([
                        "name": "axe",          // name of the skill
                        "exp_required": 0,      // minimum combat experience required
                        "jing_cost":    10,     // jing cost every time study this
                        "difficulty":   20,     // the base int to learn this skill
                        "max_skill":    101      // the maximum level you can learn
                ]));
        }
}
