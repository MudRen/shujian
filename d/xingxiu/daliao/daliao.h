#include <ansi.h>

int valid_leave(object me, string dir)
{
  if(present("liao bing",environment(me)))  return notify_fail("�ɱ�һ�ѽ�����ס�������ܣ�\n" );
  return ::valid_leave(me, dir);
}
void init()
{
  object me,obj;
  me = this_player();
   if(me->query_condition("killer"))
  {
   message_vision(HIC"\nͻȻ$N�ƺ���Ѫ��Щ��˳������һ����������ȥ��\n"NOR,me); 
   tell_object(me,HIR"��ͻȻ�е�һ�������������㣬˲����ʧȥ֪����\n"NOR);
   tell_room(environment(me),HIR"\nֻ��������ͻȻ����һ���Ѷ���"+ me->name()+ "һͷ������ȥ��˲����ʧ��\n"NOR, ({ }));
   me->move(__DIR__"shanlu1"); 
   tell_room(environment(me), HIR"\n����У��ƺ�һ���˵����������㶨��һ����Ȼ��"+ me->name()+ "��\n"NOR, ({}));
   me->unconcious();
   return;
  }
  if(!me->query("quest/�����˲�/���ɾ�Ԯƪ/start")) return;
   if(me->query("quest/�����˲�/���ɾ�Ԯƪ/over")) return; 
  if(!me->query_temp("quest/�����˲�/���ɾ�Ԯƪ/godaliao")) return; 
 
  obj=new(__DIR__"npc/liaobing");
  obj->set("teamleader",1);
  obj->set("fight_id",me->query("id"));
  obj->move(environment(me)); 
}
