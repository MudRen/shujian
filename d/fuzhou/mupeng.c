// mupeng Сľ��
// By Looklove for a Quest

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","Сľ��");
	set("long", @LONG
����һ�������õ��ϵ���ľ��ʱ��������Сľ������Զ���Ѿ�û��֪
����ʲôʱ��ʲô�������ｨ���ˡ�ľ����Ȼ���ƾɣ������������ǵ���Ψһ
���Ա���ĵط�������ż�������˹�ˡ����������һЩ���������̳ɢ��
���
LONG
        );
	set("exits",([
		"out" : __DIR__"rock",
        ]));
        setup();
}
void init()
{
        add_action("do_find","find");
}

int do_find()
{
        object me = this_player();
        object gan;

	if (me->is_busy())
		return notify_fail("��������æ���أ�\n");

	if (!me->query_temp("find/yugan")){
		me->start_busy(random(2));
		return notify_fail("�����˰��죬û����ʲô�������õĶ�����\n");
	}

	if (present("yu gan", this_player()))
		return notify_fail("�����ϲ����������ô��\n");

	if ( present("yu gan",  environment(me)) )
		return notify_fail("������ͣ�����ûʲô�������õĶ����ˡ�\n");

	if ((int)me->query("jingli") <50 ) {
		write("�㻹��ЪЪ�ѡ�\n");
		return 1;
	}
        message_vision("$N�ڽ����������﷭����ȥ��\n", me);
        me->start_busy(random(2));
        me->add("jingli",-20);

        if(random(6)<1) {
		write("���ҵ���һ�Ѳ�֪��˭��������ľ���͡�\n");
		gan=new("/d/gb/obj/yugan");
		gan->move(me);
		me->delete_temp("find/yugan");
	}
        return 1;
}
