// fadao.c ����
// By Looklove@SJ 2000/10/06

#include <ansi.h>
#include <weapon.h>

inherit BLADE;
#include "/inherit/item/embed.h"

void create()
{
	set_name(HIW "����" NOR, ({ "fa dao", "dao", "knife"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("damage", 15);
		set("embed", 1);
		set("unit", "��");
		set("throw_msg", HIW"$N����һ����һ��С�������ķɳ�ֱ��$n�����ȥ��\n"NOR);
		set("long", "һö���ֵ�С��������ѩ��������ü��Ǿ��¡������ޱȡ�\n");
		set("value", 300);
		set("wield_msg", "$N��ָһ������֪ʲôʱ�������Ѿ�����һ��С����\n");
		set("unwield_msg", "$N����һ�գ�$nͻȻ��ʧ�����С�\n");
	}
        init_blade(160);
	setup();
}
