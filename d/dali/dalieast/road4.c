// Modify By River 98/12
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"ɽ��С·"NOR);
        set("long", @LONG
ת��һ��ɽ�ڣ�·��ƽ̹��ǰ����Լ����һ��������
LONG);
        set("outdoors", "����");
        set("exits", ([
               "southeast" : __DIR__"simen",   
               "northwest" : __DIR__"road3",   
        ]));

	setup();
}
