// shaojiu.c  �վ�

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("�վ�", ({"shao jiu", "shaojiu"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ������װ���վƵ�ţƤ��ƴ������װ�ðˡ������ľơ�\n");
                set("unit", "��");
		set("value", 80);
		set("max_liquid", 15);
	}

	set("liquid", ([
		"type": "alcohol",
		"name": "�����վ�",
		"remaining": 15,
		"drunk_supply": 6,
	]));
}

