// �᷿ xfang4.c
 
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create() 
{ 
        set("short", "�᷿");
        set("long", @LONG
����һ����µ��᷿���ƿ����ţ��ҿ��������������ںڳ���������ҹ��
���������еĴ�������ձ����ס�ˣ����ϵ�����Ҳ�ص�����ʵʵ�����������
�ǡ��������ȡ�����ţ��Ϣ�ĵط��ˡ�
LONG
        );

        set("exits", ([
              "out" : __DIR__"caotang",
        ]));

        set("objects",([
            __DIR__"npc/hu" : 1,
        ]));
        set("no_fight",1);

        create_door("out", "����", "enter", DOOR_CLOSED);
        setup();
}
