// �������� damen.c
// zly 99.6.21

#include <room.h>
#include <ansi.h>
#include <wanted.h>

inherit ROOM;

void create()
{ 
       set("short",MAG"��������"NOR);
       set("long", @LONG
�����ǽ��������������ס�������Ĵ��ţ�������ŵ����Ϸ���һ�����
�ڵ׵ĳ��ң����顰�������������֣��ſ��������������ʯʨ���������䡣
�����������Ĵ����������ǻƺ������ˡ�
LONG);    
        set("exits", ([
		"north" : __DIR__"dating",
		"southeast" : "/d/huanghe/huanghe7",
        ]));    
        set("no_fight", 1);

        set("objects",([
		__DIR__"npc/zhang" : 1,
        ]));         
	setup();        
}

int valid_leave(object me, string dir)
{
	if (dir == "north" && is_wanted(me))
		return 0;
        if ( !me->query_temp("yyd_jinchai") && dir == "north" )
        return notify_fail("����һ�ְ���ץס��˵������һ����Ҳ��������\n");
        return ::valid_leave(me, dir);
}
