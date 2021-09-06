#include <ansi.h>
#include <weapon.h>
inherit COMBINED_ITEM;
inherit THROWING;

#include "/inherit/item/embed.h"

void create()
{
       set_name(HIC "暴雨梨花针" NOR, ({"zhen", "lihuan zhen" }));
	set_weight(100);

       if( clonep() )
               set_default_object(__FILE__);
  
     else {
 set("long", "此物扁平如匣，长七寸，厚三寸。上用小篆字体雕刻：“出必见血，空回不祥；急中之急，暗器之王”。\n发射之时，共三百六十五枚银针激射而出，端的是厉害无比。\n");  
               set("unit", "盒");
                set("no_sell", 1);
   set("unique", 1);
               set("value", 270000);
               set("base_unit", "枚");
               set("embed", 1);
             set("damage", 100);
               set("base_weight", 10);
       }
       set_amount(365);
       init_throwing(20);
	setup();

}

