// Room: /d/changle/dating.c
// River 2003.2.26
inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIG"С��"NOR);
	set("long", @long
���ǰ������ܹ����ֻ��ܴ��µ����ڣ�������һ��̫ʦ�Σ����ϵ��Ű��
�ĺ��������ǽ�ϸ�ӹ���ŵع��ż���ɽˮ�ֻ���һ����֪��������֮������
ǰ����ջ�����ʮ�ַ�ï��
long
	);
        set("no_fight", 1);
	set("exits", ([
                "east" : __DIR__"huayuan",
                "north" : __DIR__"woshi",
                "south" : __DIR__"zoulang4",
	]));

	set("objects", ([
		__DIR__"npc/bei" : 2,
		__DIR__"npc/mi": 1,
	]));

	setup();
}
