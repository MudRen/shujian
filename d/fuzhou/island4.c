// island4.c ɳ̲
// Looklove 2k/5/18
// 2001.9.27 update

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIW"ɳ̲"NOR);
        set("long", @LONG
����һ��Ƭɳ̲����Χ�����˱��ǣ������з�ڶ���ð����ĭ��ůů����
���������ϣ�ɹ�������������ġ������ĺ�ˮһ�������������ˢ�������
��Сʯ�ӡ�Զ���м����ʯ���������ﾭ���Ų��εĳ����
LONG
        );
        set("outdoors","����");
        set("exits",([
		"east" : __DIR__"island3",
		"south" : __DIR__"island5",
		"west" : __DIR__"island1",
        ]));
	set("objects", ([
		__DIR__"npc/dylaozhe" : 1
	]));
        setup();
}


