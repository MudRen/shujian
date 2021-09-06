
 // by snowcat oct 15 1997
#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
  set_name(HIR"战袍"NOR, ({"zhan pao", "pao"}));
  set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "一件战袍。\n");
    set("material", "cloth");
    set("unit", "件");
    set("value", 600);
    set("armor_prop/armor", 30);
  }
  setup();
}

