// suyou  ����

inherit ITEM;

void create()
{
	set_name("����", ({"su you","you"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "���������ؼ��ܱߵ������������ͣ������ӹ�����ʳ�á�\n");
		set("unit", "��");
		set("value", 1000);
	}
}
