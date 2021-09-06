#include <weapon.h>
#include <ansi.h>

inherit DAGGER;

void create()
{
  set_name(HIW"百辟匕首"NOR, ({ "bishou", "bi shou", "dagger" }) );
  set("long", "魏太子丕，造百辟匕首三，其一理似坚冰，名曰清刚；其二曜似朝日，名曰扬文，其三状似龙文，名曰龙鳞。\n诗曰：少年学剑术，凌轹白猿公。\n珠袍曳锦带，匕首插吴鸿。\n由来百夫勇，挟此生雄风。\n");
  init_dagger(80);
  set("unit", "柄");
  set("no_sell", 1);
  set_weight(600);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 60000);
    set("material", "metal");
  }
  set("wield_msg","$N手指轻弹，一柄$n无声无息的出现在手中。\n");
  set("unwield_msg", "$N将手中的$n收回袖中。\n");
  setup();
}

