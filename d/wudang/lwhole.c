// Room: lwhole.c

#include <ansi.h>;

inherit ROOM;

void create()
{
     set("short", "ʯ���Ҷ�");
     set("long", @LONG
����һ��Ȼʯ�������Ǻ����̫������ʱ��ֱ��ȫ��������������
��ס����������һʯ������߷���һЩʯ�룬�����ʯ��(wall)ʮ��ƽ����
LONG
        );
     set("exits", ([
         "out" : __DIR__"wanniansong",
             ]));    
     set("item_desc", ([
          "wall" : HIW "  ......��֮��������֮Ƥë����֮������˹��˫��֧�ţ�һ����ͨ��
���������飬������ȥ�����������飬������ȥ......\n"NOR,
             ]));
     set("no_fight", 1);
     setup();
}

void init()
{
     add_action("do_study", "study");
}

int do_study(string arg)
{
     object me;
     me = this_player();

     if ( !living(me) ) return 0;

     if ((int)me->query_skill("literate", 1) < 10)
      return notify_fail("����Ҳ����ʶ����,����ж������ķ���\n");

     if ( arg =="wall" )
  {
     if ( (int)me->query("jing")<30) 
      { write("��̫���ˣ�����Ъ�����ж��ɣ�\n");
        return 1;
      }
     if ((int)me->query_skill("yinyun-ziqi", 1) >= 41)
     {
      write("�����ʯ����ϰһ�ᣬֻ���������Ѿ������ء�\n");
      return 1;
     }
     message_vision("$N��ʼ�����ĥ��\n", me);
     write("�㾲����ϰʯ���ϵ��ؼ������ڹ��ķ���Щ����\n");
     me->receive_damage("jing", 40);
     me->receive_damage("jingli", 15);
     me->improve_skill("yinyun-ziqi", (int)me->query("int"));
     return 1;
   }
}