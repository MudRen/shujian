#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIW "������" NOR, ({ "bingqi jia", "jia" }) );         
        set_weight(30000000);
        if( clonep() )
                set_default_object(__FILE__);
        else{
        set("unit", "��");
        set("long", "����һ��ר�������ű����ļ��ӡ�
�����У�\n\n"
                   HIY"������"NOR"(duo) \n\n" 
                   HIR"���Ʊ�"NOR"(bi)
\n");
        set("material","wood");
        set("no_get",1);
        }
        setup();
}
void init()
{
    add_action("do_get","na");
}

int do_get(string arg)
{
  object me,ob;
  string arg1,arg2;
  me=this_player();
  if(!arg || sscanf(arg, "%s from %s", arg1, arg2)!=2)
   return notify_fail("�����ʽ: na <��������> from jia��\n");
  if (arg2!="jia")
     return notify_fail("�����ʽ: na <��������> from jia��\n");
  if(me->query_temp("tz_marks/��2"))
       return notify_fail("���Ѿ��ù��ˡ�\n");
    switch (arg1){
          case "duo":      ob=unew(__DIR__"jinlong-duo"); break;             
          case "bi":       ob=unew(__DIR__"huoyun-bi"); break;
          default :
                 return notify_fail("û�����ֱ�����\n");
          }
     if(!ob)
       return notify_fail("�����Ѿ����������ˡ�\n");
     if(ob) ob->move(me);
       message_vision("$N�ӱ��������ó�һ��$n��\n",me, ob); 
       me->set_temp("tz_marks/��2",1);
       return 1;


}

