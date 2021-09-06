// liangyijian-book.c

inherit ITEM;

string* titles = ({
	"���ǽ��ĵ�",
});

void create()
{
	set_name(titles[random(sizeof(titles))], ({ "shu", "book" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����������ǰ�����ܽ�������ǽ������ؼ���\n");
		set("value", 500);
		set("unique", 1);
		set("treasure", 1);
		set("newbie", 1);
		set("material", "paper");
		set("skill", ([
			"name": "sword",     // name of the skill
			"exp_required": 10000,      // minimum combat experience required
			"jing_cost":    20,     // jing cost every time study this
			"difficulty":   30,     // the base int to learn this skill
			"max_skill":    30      // the maximum level you can learn
		]));
	}
}
