inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("�ɲ���", ({"ci chawan", "chawan","ci"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ�����ߴִŴ��롣\n");
		set("unit", "��");
		set("value", 100);
		set("max_liquid", 4);
	}

    // because a container can contain different liquid
    // we set it to contain tea at the beginning
	set("liquid", ([
		"type": "tea",
		"name": "��ˮ",
		"remaining": 4,
		"drunk_supply": 0,
	]));
}
