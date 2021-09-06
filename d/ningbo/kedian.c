// /u/beyond/ningbo/kedian.c �͵�

inherit ROOM;
#include <wanted.h>

void create()
{
	set("short", "�͵�");
	set("long", @LONG
�������������һ��С�͵꣬�͵���ſ�վ��һλ��С�����������߹�����
Ц�Ǻǵ�������к����͵��������һ����ǣ�ר��Ϊ��������Ĺ����ÿ���
����ι�����ġ�ǽ�Ϲ���һ������(paizi)��
LONG
	);

	set("valid_startroom", 1);
        set("no_sleep_room",1);

	set("item_desc", ([
		"paizi" : "¥���ŷ���ÿҹ����������\n",
	]));

	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
	]));

	set("exits", ([
		"north" : __DIR__"ningbo",
		"up" : __DIR__"kedian2",
		"west" : __DIR__"majiu",
		"northeast" : __DIR__"dongqianhu",
	]));
	setup();

}

int valid_leave(object me, string dir)
{
	if (dir == "up" && is_wanted(me))
		return 0;
	if ((string)me->query_temp("rent_paid") != "������ջ" && dir == "up")
		return notify_fail("��ô�ţ����ס����\n");

	if ((string)me->query_temp("rent_paid")=="������ջ" && dir == "west" )
		return notify_fail("�͹��Ѿ��������ӣ���ô��ס��������أ����˻���ΪС���ź����أ�\n");
	return ::valid_leave(me, dir);
}
