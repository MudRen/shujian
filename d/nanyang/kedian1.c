// Room: d/nanyang/kedian.c
// Lklv Modify 2001.10.10

inherit ROOM;
void create()
{
	set("short", "��ջ");
	set("long", @LONG
���Ǹ���Զ��������������ջ������ǳ���¡������οͶ�ѡ����������
�ţ��������������������صķ������顣��С����������æ������ת���Ӵ�
����ǻ�����Ŀ��ˡ�ǽ�Ϲ���һ������(paizi)��
LONG
	);

	set("valid_startroom", 1);
	set("item_desc", ([
		"paizi" : "¥���ŷ���ÿҹ����������\n",
	]));
           set("no_fight", 1);
	set("objects", ([
		__DIR__"npc/xiao-er" : 1,
                "/clone/npc/jingcheng/ku" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"xujiaji",
		"up" : __DIR__"kedian2",
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	if ( !me->query_temp("rent_paid") && dir == "up" )
		return notify_fail("��С��һ�µ���¥��ǰ������һ���������ţ����ס����\n");
	if ( me->query_temp("rent_paid") && dir == "west" )
		return notify_fail("��С���ܵ��ű���ס���͹��Ѿ��������ӣ����᲻ס��������أ�\n"
	+"���˻���ΪС���ź����أ�\n");

	return ::valid_leave(me, dir);
}
