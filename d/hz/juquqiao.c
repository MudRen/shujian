// /u/beyond/hangzhou/jiuquqiao.c ������
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",RED"������"NOR);
        set("long", @LONG
���ϵľ����Ų��ƾ��ף�������ͨ�ġ���ǽ��ʹ���С�ͥԺ�������
֮�С��϶˵ġ�������ӡͤ����֮�����ϵ�ʯ����������̶ӳ�µ��������ڡ�
LONG
        );
        set("exits", ([
        "north" : __DIR__"xiaoying",
        "south" : __DIR__"santan",
	]));
	set("outdoors", "����");
        setup();
}
