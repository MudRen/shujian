
inherit ITEM;

void create()
{
	set_name("��������", ({ "chandao", "shu", "book" }));
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
			"����һ����ҵ����ؼ�\n"
			"��һ���ɾ���������������в���ɮ����ִ�䵶�˻���Ų�ĳ��档\n");
//          set("treasure", 1);
		set("value", 200);		set("material", "paper");
		set("skill", ([
			"name":	"blade",	// name of the skill
			"exp_required":	1000,	// minimum combat experience required
			"jing_cost":	20,	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	50	// the maximum level you can learn
		]) );
	}
}
