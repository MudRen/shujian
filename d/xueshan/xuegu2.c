// By Spiderii@ty �޸��ж�,��ֹsrf���� bug 
#include <ansi.h>

inherit ROOM;
#include "/d/suzhou/npc/lchj.h";
int do_chanhui(string arg);
int do_jump(string arg);

void create()
{
        set("short", HIW"��ʯ"NOR);
        set("long", @LONG
������Ⱥɽ�����е�һ��ɽ�ȣ��˼��������������Ͽ�������ɽ��������ƣ�
�����ű�ѩ����������һ��޴����ʯ���ڱ�������ѩ��
LONG
        );
	set("objects", ([
		__DIR__"npc/diyun" : 1,
		//__DIR__"npc/shuisheng" : 1,
	]));
	set("outdoors", "ѩɽ");
	setup();
}

void init()
{
	object me = this_player();
	if ( me->query("xs_job") > 0) {
		me->add("job_time/ѩɽ", me->query("xs_job"));
		me->delete("xs_job");
	}
	add_action("do_jump", ({"jump", "tiao","yue"}));
	add_action("do_chanhui", ({"mianbi", "chanhui"}));
}
int do_jump(string arg)
{
	object room,me = this_player();
    if( arg == "up")
    {
		if(me->query_skill("dodge")<150) 
		{
			message_vision(HIC"\n$N����һ��������������ѩ�ȣ�ȴͻȻ���ַ��ɽ�ߣ�ȴ���˻�����\n"NOR,me);
			return 1;
		}
		if (!(room = find_object(__DIR__"xuegu")))
			room = load_object(__DIR__"xuegu");
		if(!room)
		{ 
			tell_object(me,HIR"\n��������ô�������ֶ�����ԭ��!\n");
			log_file("quest/LCHJ", sprintf("%s(%s)ȱ��xuegu.c�ļ���\n", me->name(1),me->query("id")) );	
		}
/*
		else
		{
			message_vision(HIC"\n$N��׼һ����һ����ʯ������һ������ͻȻ�߸�Ծ��\n"NOR, me);
			obj=present("di yun",this_object());
			if(!me->query_temp("quest/outxuegu")|| !obj) 
			{
				message_vision(HIC"$NͻȻ�о��������㣬��æԾ��һ�ߵ���ʯ�ϡ�\n"NOR, me);
				tell_object(me,HIY"����ͼ�뿪ѩ�ȣ������������̣��޷��ɹ���\n"NOR);                       
			}
*/
			else
			{
                          //message_vision(HIC"$N���������㣬������һ�ɴ�����$N����Ծ��Ծ����յ���ʯ���漴����ѩ�ȡ�\n"NOR, me);

				message_vision(HIC"$N��׼һ������ͻ�����ʯ������һ�������߸�Ծ��˳������ʯ��΢һ�������漴����ѩ�ȡ�\n"NOR, me);
				me->move(room);
				me->delete_temp("quest/outxuegu");//
				me->start_busy(1);
                                tell_room(environment(me),HIC"\nֻ��һ����Ӱ���������ԭ����"+me->name()+"��ѩ������������\n"NOR, ({me}));                       
			}
	
		return 1;
	}
	return 0;
}
int do_chanhui(string arg)
{
	object me = this_player();
	object obj;
	if(arg) return 0;
	obj=present("di yun",this_object());
    if(!obj) return 0;
	
	message_vision(HIY"\n$N�������ȥ������Ϊ������Ϊ�Լ������Ķ��ж�������\n"NOR,me);
	if(me->query("shen")>0) 
	{
		message_vision(HIG"$N������$n��ͷ���������ڽ��������ɼ������Ѿ������ˡ���\n"NOR,obj,me);
		return 1;
	}
	if(random(2)) message_vision(HIG"$N����������$n���лڸģ�Ҳ��Ĺ����¡��Ժ��������壬Ҳ�ǹ�����������\n"NOR,obj,me);
	else message_vision(HIG"$N��$n���˵�ͷ��\n"NOR,obj,me);
        me->start_busy(1+random(3));
	message_vision(HIG"$N������$n��ͷ����$nЦ��һ�¡�\n"NOR,obj,me);
	tell_object(me,HIY"��ĬĬΪ�Լ�����Ϊ��ڣ��о�����һ������֮������\n"NOR);                       
	me->add("shen",60+random(140));
	return 1;
}
