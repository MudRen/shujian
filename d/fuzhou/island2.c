// island2.c ɳ̲
// Looklove rebuild at 2k/5/18
// 2001.9.27 update

#include <ansi.h>
inherit ROOM;


void create()
{
        set("short",HIM"ɳ̲"NOR);
        set("long", @LONG
����С����һƬ������ɳ̲��������������������ݵĸۿڣ����������
�ܽ����ƺ���(swim)Ҳ�εû�ȥ������ɳ̲�ϲ����˱��ǣ����в����з����
ʯ�Ķ���������ĭ��ǰ�洦��Զ�ǿ����ʯ���Աߴ���һ��Сľ�
LONG
        );
        set("outdoors","����");
        set("exits",([
		"west" : __DIR__"island1",
		"east"  : __DIR__"island"+(1+random(3)),
		"north" : __DIR__"island"+(1+random(3)),
		"south" : __DIR__"island"+(1+random(3)),
        ]));
        setup();
}

void init()
{
        add_action("do_swim","swim");
        add_action("do_swim","youyong");
}

int do_swim()
{
        object me = this_player();

        if (me->is_busy())
                return notify_fail("��������æ���أ�");
        message_vision("$Nһ�����壬�������������һ��Ͳ����ˡ�\n", me);
        tell_object(me,"������һ�ᣬ�����밶�߲�Զ������ʯһ����Ծ����ȥ��\n");
        me->move(__DIR__"yugang");
        tell_room(environment(me), me->name() +
                "ץ�Ű��߽�ʯ�������������������\n", me);
        return 1;
}