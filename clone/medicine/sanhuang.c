#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
   set_name("���Ʊ�����", ({"baola wan", "sanhuang","baola", "wan"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("value", 15000);
      set("unit", "Щ");
      set("heal_up", 1);
      set("long","����һ���䵱�����Ƶ���ҩ���ں���ơ��ۻơ��ٻ����ơ�\n");
      set("base_value", 15000);
      set("base_unit", "��");
      set("base_weight", 20);
   }
   set_amount(1);
}

int init()
{
   add_action("do_eat", "fu");
}

int do_eat(string arg)
{

   if(!id(arg))
       return notify_fail("��Ҫ��ʲô��\n");

   if ((int)this_player()->query("eff_qi") == 
       (int)this_player()->query("max_qi"))
           return notify_fail("�����ڲ���Ҫ�����Ʊ����衣\n");
   else {
        this_player()->receive_curing("qi", 200+random(200));
        message_vision("$N����һ�����Ʊ����裬��ɫ��ʼ����ת�졣\n", this_player());
        add_amount(-1);
        return 1;
        }
}
