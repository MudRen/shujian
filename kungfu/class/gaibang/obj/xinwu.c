
inherit ITEM;

void create()
{
	set_name("����", ({"xinwu"}));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
"����һ�����ص���Ʒ��������һ�����ɵ���ɱ��Ȩ��\n");
		set("value", 0);
		set("material", "wood");
}
   }
