// tieqinju.c ���پ�

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short",MAG"���پ�"NOR);
        set("long",@long
������ǡ�������������̫��ľӴ������������Ϊ���ɣ���Ʒ��������
�����ǲ�ͬ�����������ɵ��������������������ɫ������ͨ����ʥ�ã���
��ͨ�����ң�������Ǻ�̫���ճ����ڵ�������֮����
long);

        set("objects",([
            __DIR__"npc/kl-dizi2.c" :   1,
           __DIR__"npc/kl-dizi4.c" :   1,
        ]));

        set("exits", ([
             "northeast" : __DIR__"jiuqulang1",
             "west" : __DIR__"sleeproom",
             "up" : __DIR__"tieqinju1",
        ]));

        set("no_clean_up", 0);
        create_door("west", "С��", "east", DOOR_CLOSED);
        setup();
}

