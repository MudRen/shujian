// Room: /d/dzd/pubu.c

#include <ansi.h>
inherit __DIR__"dzd_room";

void create()
{
	set("short","�ٲ�");
	set("long",@LONG
һ���޴��ˮ����ɽ�Ϸ������£��γ�һ���ٲ�������һ���߹�����ɽ�����е�����
����������һ���ؾ��������ǰ���Ƿɽ���ˮ¶����ɽǰƮ�����֮�ڰ�����һƬ����
��Ʈ����ɢ������֮�գ�����ͷף���ʶ�Ŀ��ʹ��������������ɾ���͸��ˮ������
�ɿ���һ�����ڡ�
LONG
	);
	set("outdoors","���ǵ�");
	set("exits",([
		"east" : __DIR__"senlin6",	
		"south" : __DIR__"xiliu3",
		"southwest" : __DIR__"caodi3",
	]));
}

void init()
{
	::init();
	add_action("do_tiao","tiao");
}

int do_tiao(string arg)
{
	object me = this_player();
	if(me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");
	if(!arg || arg == "" || arg!="pubu")
		return notify_fail("�������Ķ�����\n");

	message_vision(HIC"$N���������������ٲ��ķ����Ծ��ȥ��\n"NOR, me);
        if ( me->query_dex() < 40 || me->query("neili") < 2000 ){
          write(HIR"\n���Ȼ�о�ˮ���������Լ��޷�������ˮ���࿹����������ѹ����ҡ�һϡ�\n"NOR);
          tell_room(environment(me), HIR"\nֻ�������项��һ����"+me->name()+"���絾��һ�㱻�ٲ��ļ���ˮ���������˳�����\n"NOR, ({ me }));
          me->unconcious();
          return 1;
        }

        me->move(__DIR__"rukou");
        message_vision(HIW"\n$N����������Ծ�����ٲ�֮�У�ʹ�˸���ǧ��׹�������������̣�����վס��\n"NOR, me);
        return 1;
}
	