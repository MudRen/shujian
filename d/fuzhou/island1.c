// island1.c С��
// Modify by Looklove 2k/5/18
// 2001.9.27 update

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",YEL"С��"NOR);
        set("long", @LONG
����һ�����½��Զ��С���������м�ǳǳ�ĺ�Ͽ���������������½��
����ۡ����������ɳ̲�ϲ����������ı��ǣ�һЩС��СϺ���ڰ��ߵĺ�ˮ
���������ڵ�������ȥ����ˮһ��һ��ӿ��������ʪ�����Ь�ӡ�
LONG
        );
        set("outdoors","����");
        set("exits",([
		"west"  : __DIR__"island"+(1+random(3)),
		"east"  : __DIR__"island"+(1+random(3)),
		"north" : __DIR__"island3",
		"south" : __DIR__"island"+(1+random(3)),
        ]));
	set("objects", ([
		MISC_D("beike") : 1,
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
        tell_object(me,"������һ�ᣬת�۵��˰��ߣ�����ʯ��һ����Ծ����ȥ��\n");
        me->move(__DIR__"haigang");
        tell_room(environment(me), me->name() +
	"ץ�Ű�����ʯ�������������������\n", me);
        return 1;
}