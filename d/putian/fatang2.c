// Room: /d/putian/fatang2.c ����
// lklv 2001.9.10

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
�������н����ķ��ã�����ͬʱ���ɼ����˶��������⡣������������
˵�𾭣��𷨺���伯��ĳ�������������ķ���һ���ŵ����ţ��Թ�����
�ߴ���֮�á�
LONG
        );

        set("exits", ([
                "east" : __DIR__"houdian",
        ]));
        setup();
}
