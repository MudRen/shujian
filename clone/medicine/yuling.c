#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
   set_name("����ɢ", ({"yuling san", "yuling","san"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("value", 20000);
      set("unit", "Щ");
      set("long","����һ�ݻ�ɽ�ɵ�����ɢ�����ڽ��ȶ���\n");
      set("base_value", 20000);
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

   if (!me->query_condition("hot_poison"))
           return notify_fail("�����ڲ���Ҫ������ɢ��\n");
   else {       
        if(me->query_condition("hot_poison") > 10)
           me->apply_condition("hot_poison", me->query_condition("hot_poison")-10);
        else
           me->clear_condition("hot_poison");
        message_vision("$N����һ������ɢ����ɫ������ʼ��ת�����ϵ��ȶ�Ҳ��ʼ��ɢ�ˡ�\n", this_player());
        add_amount(-1);
        return 1;
        }
}
