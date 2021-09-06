// gangzhang.c

#include <weapon.h>
inherit STAFF;

void create()
{
        set_name("天蛇杖", ({ "tianshe zhang", "zhang", "staff", "tianshe" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
                set("long", "这是一柄百年紫荆制作的天蛇杖，长约六尺，形若怪蛇，虬盘而蠖伸，杖头即是蛇头，看上去极其怪异。\n");
                set("value", 75000);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n背到背后。\n");
	}
        init_staff(60);
	setup();
}
