// mupeng.c
// ľ��
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "ľ��" );
        set("long",@long
�����Ƕ����ɵ��е������Լ����ִ�İ���֮�����������Թ��彨����
������Ů���ӾӶ࣬����е����ǰ����ǽ�������ôƫƧ�ĵط�������Ķ���
�������أ����˼���ľ�崲�����û��ʲô��Ķ����ˡ�
long);
        set("sleep_room", 1);
        set("exits",([
             "south":__DIR__"wanfoding",
]));
        setup();
}

void init()
{
    add_action("do_xian", ({"xian", "move"}));
    add_action("do_zuan", ({"zuan", "enter"}));
}             

int do_xian(string arg)
{
    object me = this_player();
    if (me->query_temp("marks/zuan"))
	return notify_fail("��Ա��˳ŵģ��������ƿ�����\n");
    if (!arg) return 0;
    if (arg != "ľ�崲" && arg != "��" && arg != "chuang" && arg != "bed")
	return 0;
    message_vision("$N�ƿ��˴��塣\n", me);
    tell_object(me, "�㷢�ִ�������һ�����ڿ������ȥ��\n");
    me->set_temp("marks/zuan", 1);
    return 1;
}

int do_zuan(string arg)
{
    object me = this_player();
    if (!arg) return 0;
    if ( arg != "hole" && arg != "��" && arg != "dong" && arg != "����" && arg != "dongkou")
	return 0;
    if (!me->query_temp("marks/zuan"))
	return 0;
    message_vision("$Nһͷ����˴��µĶ��ڡ�\n", me);
    me->delete_temp("marks/zuan");
    me->move(__DIR__"houshanxl");
    return 1;
}

