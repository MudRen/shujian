// chanfang-2
// by zqb

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������о���������������һ��С��¯�����������̴���ɢ����������
���䷿�ڡ�����͸������������ʯ���ϣ����������γɸ���ҫ�۵Ĺ�������
�еĵ���ɢ���ż������ţ����������ɮ������Ŀ���������ϡ�
LONG
	);
	set("exits", ([
//		"north" : __DIR__"chanfang-2",
                "south" : __DIR__"chanfang-1",
//              "east" : __DIR__"zdyuan",
	]));
//	set("objects", ([
//		"/d/village/obj/zhujian" : 1]));

	set("no_fight", 1);
	
	set("coor/x",20);
  set("coor/y",250);
   set("coor/z",110);
   setup();
}
