// chanfang-3
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
		"north" : __DIR__"chanfang-1",
//              "south" : __DIR__"chanfang-1",
//              "east" : __DIR__"zdyuan",
	]));
//	set("objects", ([
//		"/d/village/obj/zhujian" : 1]));
set("objects",([
__DIR__"obj/fojing2"+random(2) : 1
]));
	set("no_fight", 1);
	
	set("coor/x",20);
  set("coor/y",230);
   set("coor/z",110);
   setup();
}
