// ITEM: /d/huashan/obj/ziyin_book_1.c
// Date: Look 99/03/25

inherit ITEM;

void create()
{
	set_name("������ϲ�", ({ "ziyin yin", "book" }));
	set_weight(200);
	set("unit", "��");
	set("long", "����һ��������ϲᣬ���滭���˸��ִ������ŵ����ơ�\n");
//	set("treasure",1);
	set("value", 3000);
        set("unique", 1);
	set("material", "paper");
	set("skill", ([
			"name":	"ziyin-yin",	// name of the skill
			"exp_required":	100,	// minimum combat experience required
			"jing_cost": 15+random(15),// jing cost every time study this
			"difficulty":   20, // the base int to learn this skill
			"max_skill":	40	// the maximum level you can learn
		      ]) );
}
