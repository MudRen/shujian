// by XiaoYao

#include <room.h>

inherit ROOM;
void create()
{
        set("short", "�ƺӰ���");
        set("long", @LONG
�����ǻƺӰ��ߡ��ƺ����ʵ�����Ӵ���������ɫ�ĺ�ˮ�ھ�������
��ȥ��ʹ������������ˮʱ�Ŀ�����
LONG );
        set("exits", ([
                "northeast" : __DIR__"huanghe7",
                "southwest" : __DIR__"huanghe5",
        ]));
        set("objects",([
		__DIR__"yyd/npc/renfy" : 1,
		__DIR__"yyd/npc/linyl" : 1,
        ]));
        set("outdoors", "�ƺ�");
	setup();
}
