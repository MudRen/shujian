// Room: /d/fouzhou/huadian.c
// lklv 2001.9.8

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","����");
        set("long", @LONG
���Ǹ��ݳ������������һ�һ��꣬����ڷ��Ÿ��ָ������ʻ���������
��ɢ�����˵Ļ��㡣��һ�߽������ͻ᲻�������������ˡ�������ʻ�Ʒ�ֺ�
ȫ������ȫ�����صĶ��С������������������ü��������޼���֦��
LONG
        );
        set("exits", ([
                "east" : __DIR__"xixiang3",
        ]));
        set("objects", ([
                NPC_D("flowergirl") : 1,
        ]));
	setup();
}
