//xtg-quest item

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HBBLU"五篇灵文另"NOR, ({ "lingwen", "wupian lingwen", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "页");
		set("long", HIG"这是一页王重阳手书的赤莲真人五篇灵文的注解，密密麻麻的写满了重阳真人对先天功和玄门心法的注解。\n"NOR);
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
