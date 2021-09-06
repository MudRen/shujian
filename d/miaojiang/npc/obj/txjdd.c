#include <ansi.h>

inherit ITEM;

void create()
{
   set_name("���Ľⶾ��", ({"tianxinjiedu dan", "dan"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("unit", "��");
      set("value", 1000);
   }
   setup();
}

int init()
{
   add_action("do_eat", "eat");
}

int do_eat(string arg)
{
   object me = this_player();

   if(!id(arg))
       return notify_fail("��Ҫ��ʲô��\n");

   message_vision("$N����һ��" + name() + "��\n", me);
   if ((int)me->query_condition("qzhu_poison") > 0) {
      me->apply_condition("qzhu_poison", -5);
   }

   destruct(this_object());
   return 1;
}
