
#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
	set_name(MAG "��ɫˮ������" NOR, ({ "shuijing xianglian", "xianglian" }) );
	set_weight(1000);
	if (clonep()) set_default_object(__FILE__);
	else
	{
		set("long","��ˮ��������顢�ǻ۵������������Ե���и���ɷ��\n");
		set("female_only",1);
		set("unit", "��");
		set("value", 10000);
		set("material", "jade");
		set("armor_prop/armor",1);
		set("no_get",1);
		set("no_drop",1);
		set("remove_msg","$Nϸ�ĵý�"+name()+"ժ�£����������ղء�\n");
		set("wear_msg","$N��"+name()+"�����Լ����ϣ�����Ƿ���\n");
	}
	setup();
}

int query_autoload()
{
	return 1;
}