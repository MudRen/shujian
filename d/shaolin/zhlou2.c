// Room: /d/shaolin/zhonglou2.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "��¥����");
	set("long", @LONG
ÿ��¥���϶������˽�ʵ��ľ¥�壬�˽��ε�ǽ�����������ȴ󴰡�
�Ӵ��׿���ǽ��Ҳ�Ǽ�Ϊ��ʵ���������������������Կ���Χ�����ܵ�С԰
�Լ����ߵ����֣����Ʈ��������Ҷ�����㡣
LONG
	);

	set("exits", ([
		"up" : __DIR__"zhlou3",
		"down" : __DIR__"zhlou1",
	]));

	set("coor/x",70);
  set("coor/y",230);
   set("coor/z",130);
   setup();
}



