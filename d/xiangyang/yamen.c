// Room: /d/city/yamen.c
// Lklv 2001,9,25

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIR"����"NOR);
        set("long", @LONG
���������Ŵ��ţ�������ľ���Ž����ر��š����ྲ�����رܡ������ӷ�
����ͷʯʨ�ӵ��Աߡ�ǰ����һ����ģ���Ȼ�ǹ�С����ԩ�õġ�����������
��ǰѲ�ߡ�
LONG
        );
        set("xyjob", 1);
        set("exits", ([
                "east" : __DIR__"njie1",
                "north" : __DIR__"ymzhengting",
                "south" : __DIR__"chucshi",
        ]));

        set("objects", ([
                __DIR__"npc/yayi" : 2,
        ]));

	set("incity",1);
	setup();
}

int valid_leave(object me, string dir)
{
        if (!wizardp(me) && objectp(present("ya yi", environment(me))) && dir != "east"){
        	if( me->query_condition("killer"))
        		return notify_fail("���ۺȵ���������˭������뿪�����\n");
        	if( !objectp(present("tiebu wenshu", me)) )
                	return notify_fail("���ۺȵ������������䡭������\n");
        }
        return ::valid_leave(me, dir);
}
