// hookbook

inherit ITEM;

void create()
{
        set_name("��������", ({ "hook book", "book" }));
        set_weight(200);
        set("unit", "��");
        set("long", "����һ��������������滭���˸��ֳ��е����ơ�\n");
	set("unique", 1);
        set("treasure",1);
        set("value", 3000);
        set("material", "paper");
        set("skill", ([
                        "name": "hook",    // name of the skill
                        "exp_required": 5000,   // minimum combat experience required
                        "jing_cost": 10+random(15),// jing cost every time study this
                        "difficulty":   20, // the base int to learn this skill
                        "max_skill":    100     // the maximum level you can learn
                      ]) );
}