// 针

#include <weapon.h>
#include <ansi.h>

inherit HAMMER;


void create()
{
	set_name(WHT"骷髅锤"NOR, ({ "kulou chui", "chui", "hammer" }));
	set_weight(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "此锤昆仑寒铁铸就，造型怪异，其形如骷髅头，间有罅隙，挥舞之时，可发出狰狞之 声，扰人心神。其所张巨口，可锁定对方兵刃，十分难缠。\n");
                set("value", 75000);
		set("no_sell", 1);
              set("weapon_prop/parry", 50);
		set("material", "steel");		
		set("wield_msg", "$N拿起一柄$n「嘿嘿嘿...」奸笑几声。\n");
	}
        init_hammer(50);
	setup();
}
