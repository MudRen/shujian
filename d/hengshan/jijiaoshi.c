// Room: /d/hengshan/jijiaoshi.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "����ʯ");
        set("long", @LONG
����������࣬��һ���������ʯͷ���Ƽ���ʯ����֮����������������
�����������峿�û�������ɽ�Ȼ�������Ⱥ���������ͳơ��𼦱�������
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "east"  : __DIR__"beiyuemiao",
        ]));
        set("outdoors", "��ɽ");
        set("no_clean_up", 0);
        setup();
}
