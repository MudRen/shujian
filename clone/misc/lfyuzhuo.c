// liao_kao.c

#include <ansi.h>
#include <armor.h>

inherit BANGLE;

void create()
{
	set_name(HIG "��������" NOR, ({ "longfeng yuzhuo", "yuzhuo" }) );
	set_weight(1000);
	if (clonep()) set_default_object(__FILE__);
	else
	{
		set("long","���������������������ͼ������ףԸ���˳�˫�ɶԣ���ͷ���ϵ����ξ��䡣\n");
		set("female_only",1);
		set("unit", "��");
		set("value", 10000);
		set("material", "jade");
		set("armor_prop/armor",1);
		set("no_get",1);
		set("no_drop",1);
		set("remove_msg","$Nϸ�ĵý�"+name()+"ժ�£����������ղء�\n");
		set("wear_msg","$N��"+name()+"�����Լ������ϣ�����Ƿ���\n");
	}
	setup();
}

int query_autoload()
{
	return 1;
}