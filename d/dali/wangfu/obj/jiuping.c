//   jiuping.c
// Modify By River 98/12
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("ϸ�ž�ƿ", ({"jiu ping", "jiu", "ping"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ������װ�׾Ƶľ�ƿ��\n");
		set("unit", "��");
		set("value", 100);
		set("max_liquid", 15);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "�׾�",
		"remaining": 15,
		"drunk_apply": 3,
	]));
}
