// /area/jiangbei/wudang/gsdao6.c �����
// By River@SJ

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", YEL"�����"NOR);
        set("long", @LONG
�������ʵ����ͨ���䵱ɽ�ϵ�С�����ഫԶ��ʱ����Ӵξ������γ���
�����ߵĵ�·�Ӷ�������ʵ���Ϲ����������Ͽ��֮�У����｣��ˮ���겻��
�������ʣ�ɽ�Ϲ������죬Ͽ��������Ũ�ܣ����䵱ɽһ�羰����֮����
LONG
        );

        set("exits", ([
                "westdown" : __DIR__"qtguan",
                "eastup" : __DIR__"hldong",
        ]));

        set("no_clean_up", 0);

        set("outdoors", "�䵱");

        set("objects",([
                __DIR__"npc/jxk" : random(2)+1,
        ]));

        setup();
}
