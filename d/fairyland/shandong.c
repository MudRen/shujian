// Room: /u/qingyun/jyzj/shandong.c
// Written by qingyun
// Updated by jpei
// Modify By River@SJ

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIB"ɽ��"NOR);
	set("long", @LONG
����һ��Խ��Խխ��ɽ�������ڽ�����Ϊ��Ӳ����ʯ���������ܿ�������
�պ��ܽ�һ�ˣ������С��ͷ�����ײ��ɽʯ������ʮ���ɺ󣬸�����խ����
���Ѳ��������ת���ˣ���������Դ���������ڡ��ٽ����ɺ󣬺���ǰ��
͸�����⣬�ƺ�����һ����ء� 
LONG	);

	set("no_clean_up", 0);

	setup();
}

void init()
{
	add_action("do_climb", ({"climb", "pa", "zuan"}));
        add_action("do_back", ({ "back", "houtui"}));
}

int do_climb(string arg)
{
	object me = this_player();
        if(me->is_busy() || me->is_fighting())
              return notify_fail("����æ���أ�\n");
	if (me->query("str") >= 25 && me->query_skill("force", 1) < 150) {
		write(HIY"\n���˾�˫�磬�ֽż��ã���ǰ��ȥ�����׵�ȷʵ̫С�����ܽ�ȥ��\n\n"NOR);
		write(HIR"\n��ֻ�����������屻Ƕ�ڿ��У������ƶ��ˡ�\n"NOR);
		me->start_busy(10);
		return 1;
	}
	if (me->query("str") < 25) {
		message("vision", me->name() + "������ǰ��ȥ��\n", environment(me), ({me}));
		write("��������ã�Ѹ�����й���֮����ȥ��\n");
	}
	else {
		message_vision("$N�����ڹ���Ӳ��������ǰ��ȥ��\n", me);
	}
	write(HIG"\n����ǰ��Ȼһ������Ȼ��һ������ɽ�ȣ�\n\n");
	me->move(__DIR__"cuigu");
        me->start_busy(1);
	message("vision", me->name() + "�Ӷ������˳�����\n", environment(me), ({me}));
	return 1;
}

int do_back()
{
        object me = this_player();
        if(me->is_busy() || me->is_fighting())
              return notify_fail("����æ���أ�\n");
        message_vision("$N�ۿ�����ǰ�У�ֻ�����㲢�ã���������˳���ɽ����\n",me);
        me->move(__DIR__"dapingtai");
        me->start_busy(1);
	message("vision", me->name() + "��ɽ���е����˳�����\n", environment(me), ({me}));
        return 1;
}
