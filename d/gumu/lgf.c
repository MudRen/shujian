// lgf.c
// By River 98.08.29
inherit ROOM;
#include <ansi.h>
void create()
{
    set("short",HIY"������"NOR);
    set("long", @LONG
���ǹ�Ĺ�ڵ�һ��ʯ�ҡ���Χ�Ļ�ѽ�ʯ���յĵƻ�ͨ�����տ���һ��ʯ
�ң�û���κΰ��衣ʯ�������м������˵���ӡ����ʯ���֣��Լ��Ǹ����ཻ
��Ϊ��ʯ���������һ��ʯ�ˣ�����Ĺ���������������á�
LONG
        );

    set("exits", ([
	"south" : __DIR__"shitou",
    ]));

    set("objects", ([
           __DIR__"npc/shiren" : 1,
    ]));

    setup();
}
