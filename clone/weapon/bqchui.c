// ��

#include <weapon.h>
#include <ansi.h>

inherit HAMMER;


void create()
{
	set_name(WHT"���ô�"NOR, ({ "kulou chui", "chui", "hammer" }));
	set_weight(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�˴����غ������ͣ����͹��죬����������ͷ��������϶������֮ʱ���ɷ�������֮ �����������������ž޿ڣ��������Է����У�ʮ���Ѳ���\n");
                set("value", 75000);
		set("no_sell", 1);
              set("weapon_prop/parry", 50);
		set("material", "steel");		
		set("wield_msg", "$N����һ��$n���ٺٺ�...����Ц������\n");
	}
        init_hammer(50);
	setup();
}
