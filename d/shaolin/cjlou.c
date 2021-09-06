// Room: /d/shaolin/cjlou.c

inherit ROOM;

void create()
{
	set("short", "�ؾ���һ¥");
	set("long", @LONG
�����������������--���ֲؾ��󡣲���Ϊ��ԭ�𷨵���Դ�������´�
���ؾ�֮�������º�����ƥ�����ﶼ���������飬�߼��������ܣ���ܼ�
��������һ��ͨ�еĿ�϶�����Ŵ�����м䣬����ط������ɳ���������Ŀ
�⼰�����㿴�����Ϸ��˼����𾭡�
LONG
	);

	set("exits", ([
		"out" : __DIR__"xiaoxi1",
		"up" : __DIR__"cjlou1",
	]));
	set("cant_hubiao", 1);

	set("objects",([
		CLASS_D("shaolin") + "/dao-yi" : 1,
	]));

	setup();
}


int valid_leave(object me, string dir)
{
	if (me->query("family/family_name") == "����Ľ��" && me->query("family/generation") <3);
	else if (me->query("family/family_name") == "������" && me->query("family/generation") <36);
        else if( !present("shou yu", me) && (objectp(present("daoyi chanshi", environment(me)))) )
		if (dir == "up" ) return notify_fail("��һ˵��: ��δ����ɣ������϶�¥��\n");
	return ::valid_leave(me, dir);
}
