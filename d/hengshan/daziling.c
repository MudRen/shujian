// Room: /d/hengshan/daziling.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�����������ɽ����֮·��ʯ�������� "����" ���֣��߿����ɣ�������
���������ۻ롣
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "west"      : __DIR__"yunge",
           "northeast" : __DIR__"hufengkou",
        ]));
        set("outdoors", "��ɽ");
        set("no_clean_up", 0);
        setup();
}
