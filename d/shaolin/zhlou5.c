// Room: /d/shaolin/zhonglou5.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "��¥���");
	set("long", @LONG
һ����ȥ��ֻ��������ƣ���ɽ���У����˽�����֮������Ϊһһɨ��
����ǰ�����������¥�����������¾����۵ס���������������������
һƬ�񺣡�����Χ��ȫ�µ����������ѵ����֣�һ���������ߡ�
LONG
	);

	set("exits", ([
		"up" : __DIR__"zhlou6",
		"down" : __DIR__"zhlou4",
	]));

	set("coor/x",70);
  set("coor/y",230);
   set("coor/z",160);
   setup();
}



