#include <ansi.h>

inherit ITEM;

void create()
{
      set_name(HIY"ҩ��" NOR, ({ "yao fang"}));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ��ҩ�������Գ��Ը���֮�֣�\n"
		            +HIG"��ɫҩ�������Ǻ��ġ��غ컨�����������˲Ρ�\n\n"NOR
		            +"���⣬���滹��¼����ҩ¯��ʹ�÷�����\n"
		            +RED"��¯��open������ҩ��add������ˮ��pour����\n"
                            +"��¯��close�������dianhuo�����ȷ磨burn����\n"
		            +"��ҩ��aoyao�������miehuo����ȡҩ��qu����\n"NOR);
		set("value", 10000);
		set("material", "paper");
    set("no_give",1);
    set("no_drop",1);
    set("no_sell",1);
  }
	setup();
}
