// By River@sj 99.5.24

#include <ansi.h>
#include <room.h>
#include <wanted.h>

inherit ROOM;

string pubu(object);

void create()
{
	set("short",HIW"�ٲ�"NOR);
	set("long", @LONG
ת��һ��ɽϿ��ˮ�����������ֻ��ɽ���һ��������Ƶ��ٲ�(pubu)��
к���£�����һ��Ϫ������ʤ�������ļ��쳣��ˮ��Ю����֦ʯ�飬ת�۱���
�ò�֪ȥ���Ĺ�ˮ�����ɣ�εΪ��ۡ�
LONG
    );

	set("outdoors", "����");

	set("item_desc", ([
		"pubu" : (: pubu :),
	]));

	set("exits", ([
		"west" : __DIR__"xiaolu3",
	]));
	setup(); 
}

void init()
{
	if (!is_wanted(this_player()))
		add_action("do_tiao", "tiao");
}

string pubu(object me)
{
	return HIW"\n\tһ��������µ��ٲ���ˮ�����������˸о��ľ���ս��\n\n"NOR;
}

int do_tiao(string arg)
{
	object me = this_player();

	if (me->is_busy() || me->is_fighting()) 
		return notify_fail("����æ���أ�\n");

	if( !arg || arg == "" || arg != "pubu" )
		return notify_fail("��Ҫ����������\n");

	if (me->query_dex() < 27 )
		return notify_fail("����ͼ�����ٲ��У���¡¡��ˮ��ʹ�����е㷢��\n");

	if (me->query_skill("dodge", 1) < 100)
		return notify_fail("����ͼ�����ٲ��У�ȴ�����Լ�Ŀǰ���Ṧ����ʵ�֡�\n");

	if (me->query_skill("force", 1) < 110)
		return notify_fail("����ͼ�����ٲ��У�ȴ�����Լ��ڹ���Ϊ�ƺ���Ƿȱ���\n");

	message_vision(HIC"$N���������������ٲ��ķ����Ծ��ȥ��\n"NOR, me);
	if ( !me->query("ygpass") || me->query("neili") < 2000 ){
		write(HIR"\n���Ȼ�о�ˮ���������Լ��޷�������ˮ���࿹����������ѹ����ҡ�һϡ�\n"NOR);
		tell_room(environment(me), HIR"\nֻ�������项��һ����"+me->name()+"���絾��һ�㱻�ٲ��ļ���ˮ���������˳�����\n"NOR, ({ me }));
		me->unconcious();
		return 1;
	}
	me->move(__DIR__"pubu1");
	message_vision(HIW"\n$N����������Ծ�����ٲ�֮�У�ʹ�˸���ǧ��׹�������������̣�����վס��\n"NOR, me);
	return 1;
}
