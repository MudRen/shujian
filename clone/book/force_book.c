// force_book.c �ڹ��ķ�

inherit ITEM;

void create()
{
	set_name("̫��ʮ����", ({ "shisan shi", "shu", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����װ�飬������������Ļ��˲��ٴ������ŵ����ơ�\n");
		set("unique", 1);
		set("newbie", 1);
		set("treasure", 1);
		set("value", 500);
		set("material", "paper");
		set("skill", ([
			"name":	"force",	// name of the skill
			"exp_required":	3000,	// minimum combat experience required
			"jing_cost":	30,	// jing cost every time study this
			"difficulty":	10,	// the base int to learn this skill
			"max_skill":	30	// the maximum level you can learn
		]) );
	}
}
