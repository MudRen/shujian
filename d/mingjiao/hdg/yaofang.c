// ҩ�� yaofang.c
 
#include <ansi.h>
inherit ROOM;

void create() 
{ 
        set("short", "ҩ��");
        set("long", @LONG
�����Ǻ���ţ��ҩ������ǽ�߶���һ��һ�ŵ�ҩ��ÿ��ҩ���϶���һ��
��ֽ������д���˶�ҩ�ĵ�ע�͡��ݵ������룬��һ��С¯�ӣ�һ��Сͯ����
��¯���ԣ�����һ�����ӣ���ͣ��ɿ�Ż���������һ����ҩ����Ϣ���ϱ���
�������ܰ�����
LONG
        );

        set("exits", ([
            "north" : __DIR__"xfang3",
            "west" : __DIR__"maowu",
            "south" : __DIR__"xfang1",
        ]));

        set("objects",([
            __DIR__"npc/xtong2" : 1,
        ]));

        setup();
}
