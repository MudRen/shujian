inherit ITEM;
#include <ansi.h>
void create()
{
       set_name(HIM"率意帖"NOR, ({ "shuaiyi tie", "tie", "shuaiyi" }) );
       set_weight(100);
       if( clonep() )
               set_default_object(__FILE__);
      else {
               set("unit", "本");
               set("long", WHT @LONG
这便是唐朝张旭的率意帖，但见帖上的草书大开大
阖，便如一位武林高手展开轻功，窜高伏低，虽然
行动迅捷，却不失高雅的风致。帖尾写满了题跋盖
了不少图章，料想此帖的是非同小可。
LONG NOR);
               set("value", 100000);
               set("no_give",1);
               set("treasure",1);
               set("no_put",1);
               set("no_drop",1);
               set("material", "jade");
       }
       setup();
}

