//woshi.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIC"��ů��"NOR);
        set("long", @LONG
��������ݹ�������ɽ�����ң����Ӳ����󣬺�������ӣ����ӵ�������
���룬���ӹ��������������߰���һ���辰��һ��С�������ż����顣������
��͸�������������ֱ�������
LONG
        );       
		 
        set("exits", ([
               "south" : __DIR__"zoulang3",               
        ]));        
        set("objects", ([
             __DIR__"npc/wan" : 1,
        ]));
        setup();
}
void init()
{
	add_action("do_jump", ({"jump", "tiao"}));
}
int do_jump(string arg)
{
	object room,me = this_player();
    if( arg == "chuang" || arg == "window" || arg == "chuanghu" || arg == "chuangkou")
    {
		if(me->query_skill("dodge")<100) 
		{
			message_vision(HIY"\n$N����һ��������Ӵ�������ȥ��\n"NOR,me);
			return notify_fail("����ɽ��ǰ����һ�죺"+RANK_D->query_respect(me) +"��Ҫ��ʲô����\n");
		}
		if (!(room = find_object(__DIR__"houyuan2")))
			room = load_object(__DIR__"houyuan2");
		if(!room)
		{ 
			tell_object(me,HIR"\n��������ô�������ֶ�����ԭ��!\n");
			log_file("quest/LCHJ", sprintf("%s(%s)ȱ��houyuan2.c�ļ���\n", me->name(1),me->query("id")) );	
		}
		else
		{
			message_vision(HIY"\n$N����һ������������ɽ��ע�⣬ͻȻֱ�ӴӴ������˳�ȥ��\n"NOR, me);
			me->move(room);
			me->start_busy(1);
			tell_room(environment(me),"\nֻ��һ����Ӱ���������ԭ����"+me->name()+"�Ӵ�������������\n"NOR, ({me}));                       	
		}
		return 1;
	}
	return notify_fail("����ɽ��ǰ����һ�죺"+RANK_D->query_respect(me) +"��Ҫ��ʲô����\n");
}

