// Room:  /dali/nanjie2.c
// bbb 1997/06/11
// Modify By River 98/12/
inherit ROOM;

void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
�����ڴ����ϴ���ϣ����ﰲ�����ˣ���������ߵ�����޲������˽�
�����Ծ�����Ŀ���򶫿�ȥ�����߹�ȥ���Ǵ���ʹ��ˡ������Ǵ����˾����
�ض����������������̫�Ͷ��֡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"nanjie1",
		"east" : __DIR__"nanjie3",
		"south" : __DIR__"dinganfu",
	]));
	set("outdoors", "����");
	setup();
}
