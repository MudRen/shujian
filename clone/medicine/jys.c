#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
   set_name("��Ԫɢ", ({"jinyuan san", "jinyuan","san"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("value", 5000);
      set("unit", "Щ");
      set("long","����һ�ݲɼ������������֮ҩ���Գ�������������Ч��\n");
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

   if (!me->query_condition("ill_kesou") && !me->query_condition("ill_shanghan") 
   && !me->query_condition("ill_zhongshu") && !me->query_condition("ill_dongshang")
   && !me->query_condition("ill_fashao"))
           return notify_fail("�����ڲ���Ҫ�ý�Ԫɢ��\n");
     
        if(me->query_condition("ill_kesou") > 5)
        {
           me->apply_condition("ill_kesou", me->query_condition("ill_kesou")-5);
           message_vision("$N����һ�ݽ�Ԫɢ���о�����һ���Ӻ��˺ܶࡣ\n", me);
           add_amount(-1);
           return 1;
        }
        else if(me->query_condition("ill_kesou") > 0) {
           me->clear_condition("ill_kesou");
           message_vision("$N����һ�ݽ�Ԫɢ���о������Ѿ���ȫ���ˡ�\n", me);
           add_amount(-1);
           return 1;
        }
        
        if(me->query_condition("ill_shanghan") > 5)
        {
           me->apply_condition("ill_shanghan", me->query_condition("ill_shanghan")-5);
           message_vision("$N����һ�ݽ�Ԫɢ���о��˺�һ���Ӽ�����ࡣ\n", me);
           add_amount(-1);
           return 1;
        }
        else if(me->query_condition("ill_shanghan") > 0) {
           me->clear_condition("ill_shanghan");
           message_vision("$N����һ�ݽ�Ԫɢ���˺����Ѿ���ȫ�����ˡ�\n", me);
           add_amount(-1);
           return 1;
        }
        
        if(me->query_condition("ill_zhongshu") > 5)
        {
           me->apply_condition("ill_zhongshu", me->query_condition("ill_zhongshu")-5);
           message_vision("$N����һ�ݽ�Ԫɢ�����յ�����֢״������ࡣ\n", me);
           add_amount(-1);
           return 1;
        }
        else if(me->query_condition("ill_zhongshu") > 0) {
           me->clear_condition("ill_zhongshu");
           message_vision("$N����һ�ݽ�Ԫɢ�������Ѿ���ȫ�����ˡ�\n", me);
           add_amount(-1);
           return 1;
        }
        
        if(me->query_condition("ill_dongshang") > 5)
        {
           me->apply_condition("ill_dongshang", me->query_condition("ill_dongshang")-5);
           message_vision("$N����һ�ݽ�Ԫɢ���о�����һ���Ӻ��˺ܶࡣ\n", me);
           add_amount(-1);
           return 1;
        }
        else if(me->query_condition("ill_dongshang") > 0) {
           me->clear_condition("ill_dongshang");
           message_vision("$N����һ�ݽ�Ԫɢ�������Ѿ���ȫ�����ˡ�\n", me);
           add_amount(-1);
           return 1;
        }
        
        if(me->query_condition("ill_fashao") > 5)
        {
           me->apply_condition("ill_fashao", me->query_condition("ill_fashao")-5);
           message_vision("$N����һ�ݽ�Ԫɢ���о�����һ���Ӻ��˺ܶࡣ\n", me);
           add_amount(-1);
           return 1;
        }
        else if(me->query_condition("ill_fashao") > 0) {
           me->clear_condition("ill_fashao");
           message_vision("$N����һ�ݽ�Ԫɢ�������Ѿ���ȫ�����ˣ�����Ҳ�ָ���������\n", me);
           add_amount(-1);
           return 1;
        }
        
}
