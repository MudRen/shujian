// shitou.c By River 98/08/29

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short",HIC"ʯ��"NOR);
	set("long", @LONG
�˵ع������Ӵ�������֮�á����Ͻ��м������ţ�������Ĺ�������ڱ�Ŀ
���������ʯǽ( qiang)�Ͽ��Ų�������, ��ϸһ����ԭ������¼��������
���ȹż�����������Ĺ�������������
LONG
	);

	set("exits", ([
		"west" : __DIR__"gmqs",
		"south" : __DIR__"yaofang",
		"north" : __DIR__"lgf",
	]));

	set("item_desc", ([
		"qiang" : "ǽ��д���˸��ֹż����֡�\n",
	]));

	create_door("west", "ʯ��", "east", DOOR_CLOSED);

	setup();
}

void init()
{
	add_action("do_du","read");
	add_action("do_lingwu","yanxi");
}

int do_du(string arg)
{
	mapping fam;
	object me = this_player(); 

	if ( !living(me) ) return 0;
	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ģ�\n");
	if (!(fam = me->query("family")) || fam["family_name"] != "��Ĺ��")
		return notify_fail("�㲻�ǹ�Ĺ���ˣ�����������Ĺ�书��\n");
	if (arg == "qiang"){                 
		if ((int)me->query("jing") < 20 )
			return notify_fail("����ú���,����˯����\n");
                if ( me->query_skill("literate",1) >150)
			return notify_fail("���Ѿ���ȫ������ǽ�ϵ����֡�\n");
		if ( me->query("potential", 1) < 1)
			return notify_fail("���Ǳ��û�ˣ������ټ�����ϰ�ˡ�\n");
		me->add("potential", -1);
                me->receive_damage("jing", 100 / (int)me->query("int"));
                me->improve_skill("literate", me->query_int() *3/2 );
		write("�����ʯ�ڣ��·���������\n");
		return 1;
	}
	return notify_fail("��Ҫ��ʲô��\n");
}

int do_lingwu(string arg)
{
	mapping fam;
	object me;
	int lvl;
         
	me = this_player();

	if (! living(me)) return 0;

	if( me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ء�\n");

	if (!(fam = me->query("family")) || fam["family_name"] != "��Ĺ��")
		return notify_fail("�㲻�ǹ�Ĺ���ˣ�����������Ĺ�书��\n");

	if (! arg ) return 0;

	if ( arg != "parry" && arg != "sword" && arg != "cuff" && arg != "hand"
	 &&  arg != "strike" && arg != "force" && arg != "throwing" && arg != "dodge" )
		return notify_fail("���޷������������������书��\n");

	lvl = me->query_skill( arg, 1);

	if ( lvl < 101 ) 
		return notify_fail("���"+to_chinese(arg)+"̫�ͣ��޷��ڴ�����\n");

	if ( lvl > 120 ) 
		return notify_fail("���Ѿ��޷�����������ʲô�ˡ�\n");

	if (me->query("jing") < 40)
		return notify_fail("�㾫�����ܼ���,ȥ����ЪϢ�ɡ�\n");

	if ((int)me->query_skill("literate", 1) < 100)
		return notify_fail("�����д�ֵȼ��������޷�����˴��İ�� \n");

        me->receive_damage("jing", 10 + random(10));
        me->improve_skill( arg, (int)(me->query_int())+ (int)(me->query_skill(arg, 1)/2 ));
	tell_object(me,"�����ʯ�ڣ���"+to_chinese(arg)+"��������\n");
	return 1;
}
