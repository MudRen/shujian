// Room: /d/huashan/v-road-4.c
// Date: Look 99/03/25
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�ͱ�");
        set("long", @LONG
��������ʵ����̫���ͣ����޷����㡣��Ů��߸ߵ������棬˼����ʱ��
ʱ�֡�
LONG    );
        set("outdoors", "��ɽ");
        setup();
}

int init()
{
        call_out("go_down",2,this_player());
}

int go_down(object me)
{
        me->move(__DIR__"v-road-3");
	tell_object(me, "��վ���ͱ��Ͽ���һƬ�����деĹ�ľ�ԣ��ڹ�ľ�Ժ������һ�����ǽ��\n");
        tell_object(me, HIR"�㻹ûվ���ֻ���������\n"NOR);
        message("vision", "ֻ��" + me->query("name") + "�����滬��������\n", environment(me), me);
        return 1;
}