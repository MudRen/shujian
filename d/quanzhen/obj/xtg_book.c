//xtg-quest item

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HBBLU"��ƪ������"NOR, ({ "lingwen", "wupian lingwen", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "ҳ");
		set("long", HIG"����һҳ����������ĳ���������ƪ���ĵ�ע�⣬���������д�����������˶����칦�������ķ���ע�⡣\n"NOR);
		set("unique", 1);
//		set("newbie", 1);
		set("treasure", 1);
		set("value", 500000);
		set("material", "paper");
		set("skill", ([
			"name":	"taoism",	// name of the skill
			"exp_required":	1200000,	// minimum combat experience required
			"jing_cost":	30,	// jing cost every time study this
			"difficulty":	60,	// the base int to learn this skill
			"max_skill":	220	// the maximum level you can learn
		]) );
	}
}
