// longwang.c ������
// Modify By River@SJ 99.06

#include <ansi.h>
#include <wanted.h>
inherit ROOM;
void create()
{
       set("short",MAG"������"NOR);
       set("long", @LONG
������רΪ���������������˿������еҲ�����޼ɽ���Ϊ�ټ�����
������ʾ����ȥ�񡢳��������Ľ�ּ֮�����������һ���㰸�����궼������
ȼ�ţ�����Ѭ����ͷ�����εġ�
LONG);
	set("exits", ([
		"east" : __DIR__"jyt",
		"west" : __DIR__"tuqi",
                "northwest" : __DIR__"yuanzi",
	]));

        set("objects",([
		__DIR__"npc/f-dizi" : 1,
                __DIR__"npc/m-dizi" : 1,
                CLASS_D("mingjiao") + "/yang" : 1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	object ob;
	mapping myfam;

	myfam = (mapping)me->query("family");
	ob = present("yang xiao", environment(me));

	if (dir == "northwest" && is_wanted(me))
		return 0;
	if (dir == "northwest" && (!ob || !living(ob)) && !wizardp(me))
		return notify_fail(YEL"\nͻȻһ������������������ô�����ʹŮ���Ĺ뷿��ɱ��\n\n"NOR);
	if (dir == "northwest" && !myfam && ob && !wizardp(me))
		return notify_fail("���а���һ����ס���ȥ·���ô���Ů���Ĺ뷿��ɱ��\n");
	if ((!myfam || myfam["master_name"] != "���޼�" || !me->query_temp("mj_jiaozhu"))
	 && dir == "northwest"
	 && objectp(ob)
	 && !wizardp(me))
		return notify_fail(YEL"\n���а���һ����ס���ȥ·����������Ů���Ĺ뷿����׼���Խ��룡\n\n"NOR);
	return ::valid_leave(me, dir);
}
