// Room: /u/jpei/thd/zoulang3.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һ�����Ӵ��������䳡�Ļ��ȡ�
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","�һ���");

	set("exits", ([
		"west": __DIR__"lianwuchang",
		"east": __DIR__"zoulang1",
	]) );

	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "west" && me->query("family/family_name") != "�һ���")
		return notify_fail("һλ������ס���㣬�����ƱȻ��ű�ʾ�Ǳ߲���ȥ��\n");
	
	return ::valid_leave(me, dir);
}
