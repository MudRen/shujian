#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", MAG"�껨��"NOR);
        set("long",@LONG
�껨������������֮һ��Ϊ�ؾ�����֮�����ıڿ�ǽ����������
�ܣ����Ͼ������ײ��������������������ǵ�������֮�أ�ÿ������
���������ӵܵ����г��ݣ�ÿ����һ�Σ����з���װ�ޡ������и�С
��ͨ����Ժ��������֡�
LONG);
        set("exits", ([
                "out" : __DIR__"yuhua",
                "north" : __DIR__"road7",

	]));

        set("objects",([
                __DIR__"npc/liao-si" : 1,
    //            __DIR__"obj/fojing2"+random(2) : 1
        ]));

        setup();
}
