//Created by Redhat@Sjmud 2009/4/7
//updated by Zhuifeng@SJFY 2010/7/27

inherit ROOM;
#include <ansi.h>
#define QUESTDIR "quest/���Ӣ�۴�/��ѩ����/"
void create()
{
	set("short", "���С��");
	set("long", @LONG
����һ��ʮ����ˬ���񷿣��Ҿ߰���һӦ��ȫ��ֻ�Ƕ�����һ���������
���м���һ��С�������ϵı��뻹��û�г�ȥ����������ȥ�ĺܴ�æ��ǽ�Ϲ�
��һ�˶̱����������ǹ(Tieqiang)��
LONG
	);

	set("item_desc", ([
		"tieqiang" : "һ���þ��˵���ǹ��������ԭ��Ӧ����һ�Եģ���֪Ϊ��ֻʣ��һ�ˡ�\n",
	]) );

	set("exits", ([
		"north" : __DIR__"houyuan.c",
	  "south" : __DIR__"qianyuan.c",
	]));

	setup();
}

void init()
{
  object me,obj;
  me = this_player();
  if (me->query(QUESTDIR+"start")
 		 &&!me->query_condition("killer")
		  &&!me->query(QUESTDIR+"over")
		  &&!me->query_temp(QUESTDIR+"have_kill")
     &&!me->query_temp(QUESTDIR+"kill"))
  {
     tell_object(me,HIC"������ŭ�����ߣ������߳��������ȵ������Ҿ��������ģ����Ǹ���ô����������������һ�������»��ת���˿�����\n" 
                       "�����һ����������߽����е������ã����������ģ����Ҽ���ȥ�������ˣ�������������һӵ���ϡ������ĵ�תǹ����\n"NOR+
                    RED"һ�С��׺羭�족������������ɨ���ڵأ�����һ�С�������ŭ����ǹ������һ�����������˶ѣ��ȵ�����Ҫ���ˣ��ȵ�˵˵�ҷ�����ô���\n"NOR); 
     message_vision(HIR"\n���ͻȻ����$N��������ȫ��һ㶣�ͻȻһ�������˵�������ҵ���ү׽��Ҫ��������ɱ�ˡ���\n"NOR, me);
     obj=new(__DIR__"npc/jinbing");
     obj->set("kill_id",me->query("id"));
     obj->move(environment(me));      
     obj=new(__DIR__"npc/jinbing");
     obj->set("kill_id",me->query("id"));
     obj->move(environment(me));        
     obj=new(__DIR__"npc/jinbing");
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

  if (me->query(QUESTDIR+"start")
 		 &&!me->query_condition("killer")
 		  &&!me->query_temp(QUESTDIR+"have_kill")
     &&!me->query_temp(QUESTDIR+"kill"))
  {
     obj=new(__DIR__"npc/jinbing");
     obj->set("kill_id",me->query("id"));
     obj->move(environment(me)); 
     tell_object(me,HIG"\n\n��ֻ�о�����������Ϊ����˱��ɣ���Ȼ����������ɱ�ˣ����ɻ������ǣ����̶Խ������������\n"NOR); 
     obj->unconcious();
  }  
}
int valid_leave(object me, string dir)
{
       if (me->is_fighting())
                return notify_fail(RED"\n��������ȵ��������ߡ�һ����ס�㣬�㾹Ȼ�޷��뿪��\n"NOR);
       if (present("jin bing",this_object()))
                return notify_fail(RED"\n��������ȵ��������ߡ�һ����ס�㣬�㾹Ȼ�޷��뿪��\n"NOR);
   		if(me->query_condition("killer")) 
   		          return notify_fail(RED"\n��ô�����ģ��������wiz�ɡ�\n"NOR);
        return ::valid_leave(me, dir);
}

