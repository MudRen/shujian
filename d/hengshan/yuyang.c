// Room: /d/hengshan/yuyang.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
�����ͱ��¶��ϣ���ʯ���ۣ�ɢ�����£�����������£����ж��У�����
�ڳԲݵ���ֻ������Ǻ͡��𼦱����������ĺ�ɽʤ�����������ơ���
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "westdown"    : __DIR__"beiyuedian",
        ]));
        set("outdoors", "��ɽ");
        set("no_clean_up", 0);
        setup();
}
