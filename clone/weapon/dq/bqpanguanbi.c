#include <ansi.h>
#include <weapon.h>
inherit BRUSH;

void create()
{
	set_name(HIM"�йٱ�"NOR, ({ "Panguan bi", "bi" }));
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "ֻ");
		set("long", "����йٱʿ�����������ͨ������ֻҪ΢΢�������أ�����˲�䱩�����磬��в���󣬲������վ���֮ʿ���Զ�ܡ���\n");
		set("value", 60000);
		set("material", "steel");
		set("no_sell", 1);
		set("wield_msg", "$N��������һֻ$n������д����ڿ�����ġ�˼��ʡ�\n");
		set("unwield_msg", "$N�����е�$n��ر��ʣ��������С�\n");
	}
	init_brush(100);
	setup();
}
