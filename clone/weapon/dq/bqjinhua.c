#include <ansi.h>
#include <weapon.h>
inherit COMBINED_ITEM;
inherit THROWING;

void create()
{
       set_name(HIC "�����滨��" NOR, ({"jin hua", "jin", "hua" }));
       if( clonep() )
               set_default_object(__FILE__);
       else {
		set("long", "�����ƽ��ϻ�����ߴ磬�����硣����С׭�����̣������ؼ�Ѫ���ջز��飻����֮��������֮����������֮ʱ����������ʮ��ö���뼤��������˵��������ޱ�\n");               
               set("unit", "ֻ");
	        set("no_sell", 1);
               set("base_value", 72000);
               set("base_unit", "ö");
               set("base_weight", 10);
       }
       set_amount(365);
       init_throwing(120);
}

