// hdjiudai.c  ����ƴ�
// Lklv 2001.9.28 update

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("����ƴ�", ({"huadiao jiudai", "jiu dai", "huadiao", "dai"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ������װ�߼�����ƵĴ�ƴ���\n");
		set("unit", "��");
		set("value", 120);
		set("max_liquid", 20);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "�����",
		"remaining": 20,
		"drunk_apply": 6,
	]));
}