// zhuhu.c  ���

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("���", ({"zhuhu", "hu"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ������װ��ˮ��������ô������ɡ�\n");
		set("unit", "��");
		set("value", 100);
		set("max_liquid", 15);
	}

	
	set("liquid", ([
		"type": "water",
		"name": "��ˮ",
		"remaining": 15,
		"drunk_apply": 15,
	]));
}
