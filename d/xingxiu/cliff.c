//tangfeng@SJ 2004

#include <ansi.h>
inherit ROOM;
#define QUESTDIR3 "quest/�����˲�/��������ƪ/"

void create()
{
	set("short", HIC"�ͱ�"NOR);
	set("long", @LONG
��������Ħ��֮�ͱڣ���������ȥ��������������һ�������������Źء�
վ�ڸߴ����㲻�ɸе�������޺á�
LONG
	);
 set("no_get_from", 1); 
           set("quest",1);
 set("no_sleep_room", 1);
 setup();
}

void init()
{
	object me = this_player();
  if(me->query_condition("killer")||me->query_condition("job_busy"))
  {
     message_vision(HIC"\nͻȻ����֪�������ﴫ��һ�������������ﲻ��ӭ$N��\n"NOR,me); 
     tell_object(me,HIR"���ţ���֪����������һֻ��ŷ���һ�ţ�����һ���߷ɳ�ȥ��\n"NOR);
     tell_room(environment(me),HIR"\n��֪����������һֻ��ŷ���һ�ţ���"+ me->name()+ "�߷ɳ�ȥ��\n"NOR, ({ me }));
     if(random(2)) me->move("/d/xingxiu/silk3");
     else me->move("/d/xingxiu/jyg");
     tell_room(environment(me), HIR"\nֻ��"+ me->name()+ "���һ���ɹ�����ˤ�˸�����ʺ����˧Ŷ~~~~~~~~\n"NOR, ({ me }));
     me->start_busy(1);
     return;
  }
	if (me->query(QUESTDIR3+"start")&&me->query_temp(QUESTDIR3+"askxiao") && !me->query_temp(QUESTDIR3+"lookcliff")&& !me->query(QUESTDIR3+"over")) {
		add_action("do_look", ({"look"}));
	}
  add_action("do_jump", ({"jump", "tiao"}));
}
int do_look(string arg)
{
	object me = this_player();

	if (me->query(QUESTDIR3+"start")&&me->query_temp(QUESTDIR3+"askxiao") && !me->query_temp(QUESTDIR3+"lookcliff")&& !me->query(QUESTDIR3+"over")) {
	 if (!arg) {
		set("long", @LONG
��������Ħ��֮�ͱڣ���������ȥ��������������һ�������������Źء�
վ�ڸߴ����㲻�ɸе�������޺á�ֻ�ǲ���һ��Ƭ�⻬֮���ǳ���֡�
LONG
);
		me->look(arg);
	 }
         else if (arg == "�⻬֮��"||arg == "����"||arg == "cliff" ||arg == "stone") {
		tell_object(me,HIR"����ϸ�ع۲����ͱڣ�ֻ����һƬɽ��������ƽ���⻬��������һ��Ƭɽʯ��ȴ���Ǹ����ӡ�ۣ�\n"
		                  "�Զ��׼��������˹��⽫���µ��ּ���ȥ�ˡ�\n"NOR);
    tell_room(environment(me),HIC"\n"+me->name()+"�ս��ͱڣ��ƺ���Ѱ��ʲô��\n"NOR, ({ me }));                       
		tell_object(me,HIC"�㰵�������ֻ��������������������ˡ�\n"NOR);
		me->set_temp(QUESTDIR3+"lookcliff",1);
		me->start_busy(5);
		remove_call_out("xiaofeng");
		call_out("xiaofeng",3,me);
		return 1;
	 }
	}
	else
	{
		set("long", @LONG
��������Ħ��֮�ͱڣ���������ȥ��������������һ�������������Źء�
վ�ڸߴ����㲻�ɸе�������޺á�
LONG
);
		me->look(arg);
	}		
}
void xiaofeng(object me)
{
	object obj;
	if(!me) return;
	if(!me->query(QUESTDIR3+"start")||!me->query_temp(QUESTDIR3+"lookcliff")|| me->query(QUESTDIR3+"over"))return;
  if(present("xiao feng", environment(me)))return;
  obj=new("/d/nanyang/npc/xiaofeng");
  obj->move(environment(me));	
	return;
}
int do_jump(string arg)
{
		object room,me = this_player();

    if( arg == "down" || arg == "cliff" || arg == "�ͱ�")
    {
		    if(me->query_skill("dodge")<200) 
	 	    {
           message_vision(HIC"\n$N����һ���������������ͱڣ�ȴͻȻ���ַ��ɽ�ߣ�ȴ���˻�����\n"NOR,me);
           return 1;
	      }
        message_vision(HIC"\n$N����һ������һ�������Ѿ������ͱڡ�\n"NOR, this_player());
        if (!(room = find_object(__DIR__"silk3")))
          room = load_object(__DIR__"silk3");
        if(!room)
        { 
      	  tell_object(me,HIR"\n��������ô�������ֶ�����ԭ��!\n");
      	  log_file("quest/TLBB", sprintf("%s(%s)ȱ��silk.c�ļ���\n", me->name(1),me->query("id")) );	
        }
        else
        {
        	me->move(room);
          tell_room(environment(me),HIC"\nֻ��һ����Ӱ������£�ԭ����"+me->name()+"���ͱ������¡�\n"NOR, ({ me }));                       
        }
        return 1;
    }
    return 0;
}
