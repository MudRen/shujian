// ITEM: /d/huashan/obj/qingshui-hulu.c
// Date: Look 99/03/25

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("��ˮ��«", ({"qingshui hulu", "hulu", "bottle"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ���ú�«�Ƴɵ�ˮ����\n");
		set("unit", "��");
		set("value", 100);
		set("max_liquid", 10);
	}

	set("liquid", ([
		"type": "water",
		"name": "��ˮ",
		"remaining": 10,
		"drunk_supply": 10,
	]));
}
