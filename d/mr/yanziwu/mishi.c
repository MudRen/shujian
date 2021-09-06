// jinku.c
// this is made by leontt
// update 2000.10.04

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIG"����"NOR);
	set("long",
"������Ľ�ݲ�Ĺ�ڵ�һ�����ҡ����Ϸ��˼������������"HIC"������"NOR"(box)��\n"
"ǽ�Ϲ����˴���������ʵ۵Ļ��������а���һ��"HIY"����"NOR"(chair)��\n"
);
	set("exits",([
		"south" : __DIR__"fenmu",
	]));
	set("item_desc", ([
		"chair" : "�����������ҷ����ϸ���һ���񹤾�ϸ����ͷ(tou)��\n",
		"box": "����һ����̾�������ɫ����Ĵ����ӣ�����϶��в��ٱ��\n",
	]));
	setup();
}

int init()
{
	add_action("do_sit","sit");
	add_action("do_zhuan","zhuan");
	add_action("do_open","open");
}

int do_sit(string arg)
{
	object me = this_player();
	if ( !arg || (arg != "chair") )
		return notify_fail("��Ҫ��ʲô���棿\n");
	if (me->query("family/family_name") != "����Ľ��")
		return notify_fail("�㲻�ǹ���Ľ�ݼҵ��ˣ��������㲻�����߳�ô����\n");
	if (me->query_temp("mark/sit"))
		return notify_fail("���Ѿ������ˡ�\n");
        me->set_temp("mark/sit", 1);
        return notify_fail("�����һ������ҡ��ڵ������������ϡ�\n");
}

int do_zhuan(string arg)
{
	object me = this_player();
	if ( !arg || ((arg != "left tou") && (arg != "right tou")) )
		return notify_fail("��Ҫתʲô��\n");
	if (me->query("family/family_name") != "����Ľ��")
		return notify_fail("��Ҫ��ʲô ����\n");
        if (!me->query_temp("mark/sit"))
                return notify_fail("��Ҫ��ʲô ����\n");
	if ((int)me->query("neili") < 6000 )
                return notify_fail("��׷��˰��쾢�����ʲôҲûת����\n");
	if (arg == "left tou"){
		me->add_temp("left/tou",1);
		tell_object(me,"�����ߵ���ͷת��һȦ��\n");
	}
	if(arg == "right tou"){
		me->add_temp("right/tou",1);
		tell_object(me,"����ұߵ���ͷת��һȦ��\n");
	}
	if((int)me->query_temp("left/tou") == 5
	 &&(int)me->query_temp("right/tou") == 6){
		message_vision("ֻ������ͻȻת����ǽ����ת������ʱ��$N�Ѿ������ˡ�\n",me);
		me->move(__DIR__"mishi1");
		message_vision("ֻ��ǽ�ڷ�ת��$N��ǽ��ת�˳�����\n",me);
	}
	if((int)me->query_temp("left/tou") > 5
	 ||(int)me->query_temp("right/tou")> 6){
		me->delete_temp("left/tou");
		me->delete_temp("right/tou");
	}
        return 1;
}

int do_open(string arg)
{
	object me = this_player();
	if (!arg || (arg != "box"))
		return notify_fail("��Ҫ��ʲô��\n");
	message_vision("ֻ��һ���Ҽ������$N�߶�û�ߣ����ض�����\n",me);
	me->set_temp("last_damage_from", "��ײ���ر��Ҽ���");
	me->die();
	return 1;
}
