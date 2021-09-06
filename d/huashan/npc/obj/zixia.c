// ITEM: /d/huashan/npc/obj/zixia.c
// Date: Look 99/03/25

inherit ITEM;

void create()
{
    set_name( "��ϼ�ؼ�", ({ "zixia miji", "miji", "book" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�Ừɽ�ɵ���ϼ���ؼ���\n");
              set("unique", 1);
		set("treasure",1);
		set("value", 500);
		set("material", "paper");
		set("skill", ([
            "name": "zixia-gong",   // name of the skill
			"exp_required":	0,	// minimum combat experience required
                        "jing_cost":    55,     // jing cost every time study this
			"difficulty":	30,	// the base int to learn this skill
                        "max_skill":    220     // the maximum level you can learn
		]) );
	}
}
