#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
   set_name("����ɢ", ({"qingxin san", "qingxin","san"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("value", 5000);
      set("unit", "Щ");
      set("long","����һ�������ɵ�����ɢ�����Խⶾ��\n");
      set("base_value", 5000);
      set("base_unit", "��");
      set("base_weight", 30);
   }
   set_amount(1);
}

int init()
{
   add_action("do_eat", "fu");
}

int do_eat(string arg)
{
   object me = this_player();

   if(!id(arg))
       return notify_fail("��Ҫ��ʲô��\n");

   if (!me->query_condition("xx_poison"))
           return notify_fail("�����ڲ���Ҫ������ɢ��\n");
   else {       
        if(me->query_condition("xx_poison") > 5)
           me->apply_condition("xx_poison", me->query_condition("xx_poison")-5);
        else
           me->clear_condition("xx_poison");
        message_vision("$N����һ������ɢ�����ϵ�������ɢ��һ�㡣\n", this_player());
        add_amount(-1);
        return 1;
        }
}
