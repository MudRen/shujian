// Room: /d/tianshan/duanhunya.c
// By Linux

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "�ϻ���");
	set("long",
"�������£���һƬ��С������֮�أ������Х������������岻�ɵ�����
ҡ�ڡ��㲻�ɵĲ��˰Ѻ�����ͷ������·���Ѿ���û������֮���ˡ���������
������"HIW"�ϻ���"NOR"��������ʵ�����д�ա�����һ����ң����ġ����ɸߣ���ʱ
���������ܷ�ѩ��ʴ�����ǻ������֣�������һ��С��(zi)��    
");
	 set("exits", ([
                "east" :__DIR__"banshan",
	        "northup" :__DIR__"shizhuyan",
	        "westdown":__DIR__"shanjian",
        ]));
	 set("objects", ([
                __DIR__"npc/lu" : 1,
        ]));  
	 set("item_desc", ([                    
                "zi":HIR"
\tһ   ��
\tʧ   ͷ
\t��   ��
\t��   ֪
\tǧ   ��
\t��   ��
\t��   ��\n\n"NOR,
		"down":"��������Ʈ���ƺ��и��޴��ˮ̶��\n",
        ])
        );
	set("outdoors", "��ɽ");
	setup();
}

void init()
{
	add_action("do_jump",({"tiao","jump"}));
}

int do_jump(string arg)
{
	object me = this_player();
	
	if(!arg) return notify_fail("��Ҫ����������\n");
	if(arg=="down")
	{
		object tmp;
		object room;
		if(!me->query_temp("comfy_tiao"))
		{
			me->set_temp("comfy_tiao",1);
			return notify_fail(HIR"��Ȼ�����Ǹ�ˮ̶�������˴�̫������ȥ��Σ�յģ���������������ɡ�\n"NOR);
		}
		me->delete_temp("comfy_tiao");
		tell_object(me,"�Ǻðɡ��������ˡ���\n");
		tell_object(me,HIR"��ֻ���ö��ߺ����������죬����ɿ������׺ȥ....\n"NOR);
		room=find_object(__DIR__"longtan")?find_object(__DIR__"longtan"):load_object(__DIR__"longtan");
		tell_object(room,me->name()+"������Ķϻ�������������\n");
		me->move(room);
		message_vision(HIW"�����ٶ�̫��$Nһͷ����ˮ̶�\n"NOR,me);
		tell_object(me,"��ֻ���ú���Խ��Խ���ѡ�\n");
		me->set_temp("last_damage_from","������̶��");
		me->unconcious();
        	me->die();
        	if (tmp = present("corpse", room )) {
        		object* ob;int i;
        		ob = deep_inventory(tmp);
        		i = sizeof(ob);        	
        		while (i--) if (userp(ob[i])){
        			ob[i]->move(room);
        			ob[i]->set_temp("last_damage_from","ˤ�¶ϻ��µ�");
        			ob[i]->die();
			}
			destruct(tmp);
			if (me)
			{
				tell_room(this_object(), me->name()+"��ʬ�Ƕ��Ҳ����ˡ�\n");
				tell_room(room, me->name()+"��ʬ�Ƕ��Ҳ����ˡ�\n");
			}
		}
		return 1;
	}
	return 0;	
}
