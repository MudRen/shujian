// Room: /d/fuzhou/haigang.c ����
// Lklv 2001.9.10
// 2001.9.27 update ����С���������������ɳ���

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIB"����"NOR);
	set("long", @LONG
�����ǴӸ��ݳ����ıؾ�֮�أ��ۿ���ͣ�źܶ��ʽ������ֻ����������
ȥ����Լ���Կ���һ���������ۡ����ߵķ��򲻶ϴ���һ���������������
��ż�����ܿ���һ��ֻ��Ÿ����Ӱ�����Ϸ���ȥ�����Կ��������ﲻԶ����
һ��С�������밶�ߺܽ���������������(swim)��ȥ��
LONG
	);
	set("outdoors", "����");
	set("exits", ([
        	"east" : __DIR__"yugang",
                "west" : __DIR__"dongjie",
	]));

	set("objects", ([
                NPC_D("boy"):1,
                NPC_D("girl"):2,
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

        if (me->is_busy() || me->is_fighting())
                return notify_fail("��������æ���أ�");
        message_vision("$Nһ�����壬�������������һ��Ͳ����ˡ�\n", me);
        tell_object(me,"������һ�ᣬ������С����Զ������ʯһ����Ծ����ȥ��\n");
        me->move(__DIR__"island1");
        tell_room(environment(me), me->name() +
                "ץ�Ű��߽�ʯ�������������������\n", me);
        return 1;
}
