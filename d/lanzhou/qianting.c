//by tangfeng@SJ 2004

inherit ROOM;
#include <ansi.h>
#define QUESTDIR2 "quest/ѩɽ�ɺ�/����ƪ/"

void create()
{
	set("short",HIW "ǰ��" NOR);
	set("long", @LONG
�������ׯ��ǰ���������޽������Զ������������Ϊ�¾ɣ�������Ϊ��
����ȫû�г����լ������֮����
LONG);
	set("exits", ([ 
	  "east" : __DIR__"zhengmen",
	  "north" : __DIR__"zhenting",
]));
            set("quest",1);
	setup();
}
void init()
{
  object me,obj;
  me = this_player();
  if (me->query(QUESTDIR2+"start")
 		 &&!me->query_condition("killer")
		  &&!me->query(QUESTDIR2+"over")
		  &&!me->query_temp(QUESTDIR2+"have_kill")//����һ����ǣ�ԭ�����е����ˣ�
     &&me->query_temp(QUESTDIR2+"answer")
     &&!me->query_temp(QUESTDIR2+"huyidao")
     &&!me->query_temp(QUESTDIR2+"kill"))
  {
     tell_object(me,HIC"�����ӻ����ڿ��У�ͻȻ����������Ӵ������զ��Ϊ�Լ����α����֣�����ȴ�����˷緢��ʹ��֮������͵��һ�������һ������\n" 
                       "����һ�����ҵ����ţ����˷�˫�����ۣ�����ʹ��֮ɫ������һ��֮�䣬��������Ȼѩ�����Ǻ������ۼ����ߣ����·���ء�\n"NOR+
                    RED"���������ߣ���"NOR+HIC"��������Ǻ�������ȥ���;��������������һ�ɸ����ޱȵ�����ֱ���Լ����ģ�ֻ��˫�Ʒ�����������ж��\n"NOR); 
     message_vision(HIR"\n$NƮȻ��أ�ֻ��ǰ����վ�����������ˣ�����һ�������˺���������һ���ϡ�\n"NOR, me);
     obj=new(__DIR__"npc/heiyiren");
     obj->set("kill_id",me->query("id"));
     obj->move(environment(me));      
     obj=new(__DIR__"npc/heiyiren");
     obj->set("kill_id",me->query("id"));
     obj->move(environment(me));        
     obj=new(__DIR__"npc/heiyiren");
     obj->set("kill_id",me->query("id"));
     obj->move(environment(me));    
     remove_call_out("killme");
     call_out("killme", 5, me);        
    }      
}
void killme(object me)
{
	object obj;
  if(!me) return;

  if (me->query(QUESTDIR2+"start")
 		 &&!me->query_condition("killer")
 		  &&!me->query_temp(QUESTDIR2+"have_kill")//����һ����ǣ�ԭ�����е����ˣ�
     &&me->query_temp(QUESTDIR2+"answer")
     &&!me->query_temp(QUESTDIR2+"huyidao")
     &&!me->query_temp(QUESTDIR2+"kill"))
  {
     obj=new(__DIR__"npc/heiyiren");
     obj->set("kill_id",me->query("id"));
     obj->move(environment(me)); 
     tell_object(me,HIG"\n\n���������������֣�ֻ������Ϊ����˱��ɡ���֪�������������Σ�����֮�����Ǿ�������ǰ���ˡ�\n"NOR); 
     message_vision(HIC"$N������������֮��Ϯ��ͷ�����м��������Ť����������֪�����ڹ�������ǹһ��������$N����ٿ�������ץס��$n�����ڹ��Ĺ�ͷһ����\n"NOR, me,obj);
     message_vision(HIC"��$n��������һ�����ֱ����飬���ڹ���Ȼ���֣�$N˳�ֻӳ����ĵ�һ�죬����$p����֮�ϡ�$n��ʱ���������˹�ȥ��\n\n"NOR, me,obj);
     obj->unconcious();
  }  
}
int valid_leave(object me, string dir)
{
       if (me->is_fighting())
                return notify_fail(RED"\n�����˴����ȵ��������ߡ�һ����ס�㣬�㾹Ȼ�޷��뿪��\n"NOR);
       if (present("heiyi ren",this_object()))
                return notify_fail(RED"\n�����˴����ȵ��������ߡ�һ����ס�㣬�㾹Ȼ�޷��뿪��\n"NOR);
   		if(me->query_condition("killer")) 
   		          return notify_fail(RED"\n��ô�����ģ��������wiz�ɡ�\n"NOR);
        return ::valid_leave(me, dir);
}

