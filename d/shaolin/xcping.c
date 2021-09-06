#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIG"����ƺ"NOR);
	set("long", @LONG
������һƬ�ּ�յأ����滷����ǧ������������������дкò�ïʢ��
������һ����������ʯ��������ʯ����Ϊ���࣬����������������֪ǰ��ɮ
����������������������á�ʯƺ��ɨ����Ϊ�ྻ��ֻ�����ֱ���һ��С��
ʯ����Ϊ��Ŀ��������һ��ʯ���������������������֡�һλ��ɮб����ʯ
�����ƺ����ΰ��ѡ�
LONG
     );
	set("exits", ([
		"north" : __DIR__"xctang",
		"west"  : "/d/shaolin/fatang",
	]));
	set("outdoors", "����");
	set("objects",([
		__DIR__"npc/huu" : 1,
	]));
	setup();
}
void init()
{
	add_action("do_huadi", "huadi");
}
int do_huadi()
{
	object me=this_player();

	if (((int)me->query("max_neili",1)>1000)&&((int)me->query("neili",1)>500)) {
		message("vision","\nֻ�� " + me->query("name")+"������·�Լ���һ���ʯ,\n"
		" ����ʯ���ϻ�������,����ʱ�㻭����һ���ݺ�ʮ�ŵ��Ĵ�Χ����,����\n"
		"��ƽ��ֱ,�˵�������似��\n",
			environment(me), ({me}) );
	write("������ʯ���ϻ�����һ��������\n");
	me->receive_damage("neili",500);
	me->set_temp("huadi",1);
	}
	else {
		message("vision", me->query("name")+ "ſ�ڵ��ϻ����ֶ�����,��ʯ�ʼ�Ӳ,��һ���ƶ�û�С�\n",
			environment(me), ({me}) );
		write("�㻮�˰������������������޷������κ�ӡ�ǡ�\n");
	}
	return 1;
}

int valid_leave(object me, string dir)
{
	if (( me->query("family/family_name") != "������" || (me->query("family/generation") >35 && me->query("pass_xin")==0))
	&& dir == "north"
	&& !wizardp(me) )
		return notify_fail("ְ��ɮ������ס�㣬�����ò������롣\n");
	return ::valid_leave(me, dir);
}
