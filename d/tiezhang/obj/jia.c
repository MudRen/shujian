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
        set("long", "����һ��ר�������Ÿ��ֱ����ļ��ӡ�
�����У�
       ��(bian)��        ��(dao)�� 
       ��(gangzhang)��   ��(jian)��
       ��(bi),           ��(fu),

���������ߡ�\n");
        set("material","wood");
        set("no_get",1);
        }
        setup();
}
void init()
{
    add_action("do_get",({"get","na"}));
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
  if(me->query_temp("tz_marks/��"))
       return notify_fail("���Ѿ��ù��ˡ�\n");
    switch (arg1){
          case "jian":      ob=new(BINGQI_D("sword")); break;             
          case "dao":       ob=new(BINGQI_D("blade")); break;   
          case "bian":      ob=new(BINGQI_D("whip")); break;         
          case "fu":        ob=new("/d/tiezhang/obj/gangfu"); break;
          case "gangzhang": ob=new(BINGQI_D("staff")); break;
          case "bi":        ob=new("/d/tiezhang/obj/tiebi"); break;    
          default :
                 return notify_fail("û�����ֱ�����\n");
          }
     if(ob) ob->move(me);
       message_vision("$N�ӱ��������ó�һ��$n��\n",me, ob); 
       me->set_temp("tz_marks/��",1);
       return 1;

}

