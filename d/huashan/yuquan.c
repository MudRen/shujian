// Room: /d/huashan/yuquan.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
	set("short", "��ȪԺ");
	set("long", @LONG
�������ݺ����Ȫ�����������δ���ϣ�����ӵĵط�����Χ����ʮ�����
���٣�ز�ö��ˣ�֦���пգ�����������ƣ��ഫ��ϣ����������������ֲ��
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"path1",
	]));

	set("no_clean_up", 0);
       set("objects", ([
                __DIR__"npc/teller": 1 ]) );

	set("outdoors", "��ɽ" );
	set("coor/x",40);
  set("coor/y",110);
   set("coor/z",0);
   setup();
}
