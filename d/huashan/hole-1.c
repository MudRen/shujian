// Room: /d/huashan/hole-1.c
// Date: Look 99/03/25

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "խ��");
	 set("long", @LONG
����ǳ��ڰ������ֲ�����ָ����ʲôҲ��������
LONG);
        set("no_clean_up", 0);
        setup();
}
 
int init()
{
	add_action("do_use","use");
}

int do_use(string arg)
{
	object me;
	object room;
	object fire;
	me = this_player();
       if (!(fire=present("fire", me)))  return 0;
	if ( !arg || arg =="") return 0;
	if ( arg != "fire" ) return 0;
	write(	"���ȼ�˻��ۣ�ֻ������һ��խխ�Ŀ׵����������ǰ����ʮ���ɣ���\n"
		"����Ȼδ����ͷ���������ɣ�˳����ת��������ǰ������һ������\n"
		"��ʯ����\n");
	if ( !(room == find_object(__DIR__"hole-2")) )
		room = load_object(__DIR__"hole-2"); 
	set("exits/west", __DIR__"hole-2");
	set("exits/out", __DIR__"hole");
	call_out("close_out",10);

	return 1;
}

int close_out()
{
	object room;
        if (! (room == find_object(__DIR__"hole-1")) )
		room = load_object(__DIR__"hole-1"); 
	room->delete("exits/out");
	room->delete("exits/west");
	return 0;
}