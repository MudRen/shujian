// /d/wudang/shanlu1.c ɽ·
// by ydh
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",YEL"ɽ·"NOR);
        set("long", @LONG
�����ڵ�ɽ��·���ϣ�·�����Ʊ���ɽ�ڣ��ұ߶��д������������һ��
ɽ�ȣ����ﳤ����ɽ��ɽ��һ�����䲨���������ʤ��!
LONG
        );
        set("exits", ([
                "westup" : __DIR__"yuxu",
                "northdown" :__DIR__"wdbolin",
        ]));
        set("outdoors","�䵱");
        setup();
}
