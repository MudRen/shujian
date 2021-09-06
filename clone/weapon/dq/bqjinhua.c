#include <ansi.h>
#include <weapon.h>
inherit COMBINED_ITEM;
inherit THROWING;

void create()
{
       set_name(HIC "暴雨梨花针" NOR, ({"jin hua", "jin", "hua" }));
       if( clonep() )
               set_default_object(__FILE__);
       else {
		set("long", "此物扁平如匣，长七寸，厚三寸。上用小篆字体雕刻：“出必见血，空回不祥；急中之急，暗器之王”。发射之时，共三百六十五枚银针激射而出，端的是厉害无比\n");               
               set("unit", "只");
	        set("no_sell", 1);
               set("base_value", 72000);
               set("base_unit", "枚");
               set("base_weight", 10);
       }
       set_amount(365);
       init_throwing(120);
}

