// Room: /d/xingxiu/jyg.c
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"���Ź�"NOR);
        set("long", @LONG
�����ǳ��������Ĺذ����Źأ��ֳƼ����ء����²�ɣ���ڲ�ס���ķ�ɡ�
Ⱥɽ����֮�£����������ۻ롣���������߱��������ġ�˿��֮·����ֵͨ��
������˳�����ﳤ�Ǳ��ͨ����ԭ�����פ���б߷����ӣ���ʱ����������
�ˡ���С�����������뿪���Ƿ�֮�ء�
LONG);
        set("outdoors", "������");
        set("exits", ([
                "east" : __DIR__"jyge",
                "north" : __DIR__"xiaowu",
                "west" : __DIR__"jygw",
                "south" : __DIR__"jyg_1",
        ]));

	set("objects", ([
               __DIR__"npc/wujiang2" : 1, 
                __DIR__"npc/wujiang1" : 2, 
        ]));
	setup();
}
