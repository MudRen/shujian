#include <ansi.h>
#include <room.h>;
inherit ROOM;

void create()
{
  set("short","������");
  set("long",@LONG
һ�����������ţ������������ٺ�ľ���������ģ�һ��紵����
��ҡҡ��׹����С��������������ϣ�ץ�����ߵ����������ŽŲ���
�Ű壬�����Ե���Զ�ֳ��������"������"ֱ����
LONG);
     set("outdoors", "������");
     set("exits",([
           "south" : __DIR__"bzqs",
           "north" : __DIR__"bzqn",
     ]));

     set("coor/x",-390);
  set("coor/y",-280);
   set("coor/z",30);
   setup();
}
void init()
{
    object me = this_player();
    if (random(100) > me->query_skill("dodge", 1)){
         message_vision(HIR"һ���紵����$N��С�ģ������ϵ�����ȥ��\n"NOR, me);
    if(me->query_skill("dodge", 1) < 30){
       me->receive_damage("qi", 50);
       me->receive_wound("qi",  50);
       } 
    me->set_temp("last_damage_from", "ʧ������ϵ���");
    me->move(__DIR__"goudi");
    tell_room(environment(me), "һ���紵����"+me->name()+"ʧ������ϵ���������\n",({ me }));
    }
}


