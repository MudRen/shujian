// Room: /d/shaolin/gulou5.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "��¥���");
	set("long", @LONG
һ����ȥ��ֻ��������ƣ���ɽ���У����˽�����֮������Ϊһһɨ��
����ǰ���������̨�����������¾����۵ס���������������������һ
Ƭ�񺣡�������Χ��ȫ�µ����������ѵ����֣�һ���������ߡ�
LONG
	);

	set("exits", ([
		"up" : __DIR__"gulou6",
		"down" : __DIR__"gulou4",
	]));

	set("coor/x",20);
  set("coor/y",230);
   set("coor/z",160);
   setup();
}



