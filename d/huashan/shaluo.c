// Room: /d/huashan/shaluo.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
	set("short", "ɯ��ƺ");
	set("long", @LONG
������Ȫ��̤������ʯ������ɽ�����ζ��ϣ���������ɯ��ƺ��������ɽ
·��ʼ���ͣ�����һ���ػ�������ɽ����������ʮ���̡���ͨ��ɽ�ϡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"northwest" : __DIR__"path1",
		"southup" : __DIR__"qingke",
		"northeast" : __DIR__"shanhong",
	]));

	set("no_clean_up", 0);
	set("outdoors", "��ɽ" );

	set("objects", ([ 
		__DIR__"npc/haoke" : 1,
	]));

	set("coor/x",50);
  set("coor/y",90);
   set("coor/z",0);
   setup();
}