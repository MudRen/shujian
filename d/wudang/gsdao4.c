// /area/jiangbei/wudang/gsdao4.c �����
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
                "northdown" : __DIR__"zhenqing",
                "southup" : __DIR__"shijie4",
        ]));

        set("no_clean_up", 0);

        set("outdoors", "�䵱");

        setup();
}
