// Room: /d/huashan/zhengqi.c
// Date: Look 99/03/25

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "������");
	set("long", @LONG
���ǻ�ɽ��������Ⱥ�ľ�����������Ϊ�������˴���ǰ�������Ϲ��š���
���á������Ҷ���кܿ���ȴûʲô���裬��ǽ�������ѽ��Σ���������
��Ⱥ���¡���ͽ�ĵط���
LONG
	);

	set("valid_startroom", 1);
	set("no_sleep_room",1);
set("no_fight", 1);
	set("objects",([
		__DIR__"npc/yuebuqun" : 1,
		__DIR__"npc/ningzhongze" : 1,
	]));
	set("exits", ([
		"north" : __DIR__"qianting",
		"south" : __DIR__"houtang",
	]));

	set("indoors", "��ɽ" );
	setup();
}

void init()
{       
	object me = this_player();
	int lvl,lvl1,lvl2;
	lvl = me->query_skill("zhengqi-jue", 1);
	lvl1 = me->query_skill("zixia-gong", 1);
	if (lvl > 200 && !me->query("cut/huashan")){
		lvl2 = (lvl - 200)/ 4;
		me->set_skill("zhengqi-jue", 200);
		me->set_skill("zixia-gong", lvl1 + lvl2);
		me->set("cut/huashan", lvl2 * 4);
		write(HIG "ϵͳ�ѽ�������ġ���������ת��Ϊ����ϼ������\n" NOR);
	}
	if ( me->query("hs_job")){
		me->add("job_time/��ɽ", me->query("hs_job"));
		me->delete("hs_job");
	}
}
