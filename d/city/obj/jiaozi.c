// ����

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(MAG "��" NOR HIR"��" NOR, ({ "hua jiao", "huajiao", "jiaozi", "jiao" }) );
	if ( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һ������װ�ι��Ĵ�컨�Σ����Ķ��Ӳ����ţ��Ľ����Ŵ�컨���ĸ����Ӷ��òʴ����š�\n");
		set("material", "wood");
		set("no_get", "�������������뿪�Ƕ���\n");
		set("no_drop", "�������������뿪�㡣\n");
	}
	setup();
}