// Room: /dali/nanjie3.c
// bbb 1997/06/11
// update cool 98.2.21
// Modify By River 98/12/
inherit ROOM;

void create()
{
	set("short", "̫���Ͻ�");
	set("long", @LONG
������̫���Ͻ��ϣ�����ʮ�ְ�����������ճ����ߵ�����޲�������
�Ų����Ծ�����Ŀ���򱱿�ȥ�����߹���ʯ�־��Ǵ���ʹ��ˡ��������߶���
�����ϴ�֣�������Ǵ���������ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"east" : __DIR__"nanjie4",
		"west" : __DIR__"nanjie2",
		"south" : __DIR__"nanmen",
		"north" : __DIR__"qsjie2",
	]));

	set("outdoors", "����");
	setup();
}
