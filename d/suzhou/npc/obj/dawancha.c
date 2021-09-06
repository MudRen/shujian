inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("´É²èÍë", ({"wan", "cha wan","ci wan"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»¸öÀ¶±ß´Ö´Å´óÍë¡£\n");
		set("unit", "¸ö");
		set("value", 0);
        set("max_liquid", 4);
    }

    // because a container can contain different liquid
    // we set it to contain tea at the beginning
    set("liquid", ([
        "type": "tea",
        "name": "²èË®",
        "remaining": 4,
        "drunk_supply": 0,
    ]));
}
