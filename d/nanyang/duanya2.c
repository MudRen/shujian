// update by Lklv for new nanyang city 2001.10.11

#include <ansi.h>
inherit ROOM;
#define QUESTDIR3 "quest/�����˲�/��������ƪ/"

void create()
{
	set("short", "����");
	set("long", @LONG
ǰ����һ��ʮ�ֶ��͵Ķ��£��վ��쳣��������Խ��������ƺӲ�Զ����
�����ʵ�����Ӵ���������ɫ�ĺ�ˮ�ھ���������ȥ��ʹ����������
��ˮʱ�Ŀ�����
LONG
	);
           set("quest",1);
	set("outdoors", "�ƺ�");
	set("exits", ([
		"north" : __DIR__"yidao4",
	]));
	setup();
}

void init()
{
  object me,obj;
  me = this_player();
  if (!me->query(QUESTDIR3+"start")) return;
  if (!me->query_temp(QUESTDIR3+"kill")) return;
  if (me->query(QUESTDIR3+"over")) return;
  if (!me->query_temp(QUESTDIR3+"help")) return;
  if(present("xiao feng", environment(me)))return;
  me->start_busy(1);
  obj=new(__DIR__"npc/xiaofeng");
  obj->set("qi", obj->query("max_qi")/3);
  obj->set("eff_qi", obj->query("max_qi")/3);
  obj->set("jing", obj->query("max_jing"));
  obj->set("eff_jing", obj->query("max_jing"));
  obj->add("neili", obj->query("max_neili")*2);
  obj->set("jingli", obj->query("max_jingli"));
  if(obj->is_busy()) obj->start_busy(-1);	  
  if(!present("xiao feng", environment(me)))
  {
      obj->move(environment(me));
  }
}
int valid_leave(object me, string dir)
{
   object obj;
   if(obj=present("xiao feng", environment(me)))
   {
	   message_vision(HIY"\n$N���˵�ͷ������$n��ȻҪ���ˣ���Ҳ�뿪�����ˣ�������һ���ط�������˵����\n" NOR, obj,me); 
       message_vision(HIY"\n$N΢һ�����������������ȫ��ǽڷ���һ�󱬶�������죡\n" NOR, obj); 
	   message_vision(HIY"\n$N��$n�������֣���������������Ȭ�����Ҿͻ�ȥ����ġ���\n" NOR, obj,me); 
	   message_vision(HIY"\n$N���¶��£�һת�۲�����Ӱ�ˡ�\n" NOR, obj); 
       destruct(obj);
   }
   return ::valid_leave(me, dir);
}

