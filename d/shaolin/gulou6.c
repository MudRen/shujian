// Room: /d/shaolin/gulou6.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "��¥����");
	set("long", @LONG
�ش�������һ����������ɽ�磬������ˡ������ɼ����ֵľ�ͷ������
ɽ�Ķ��崦����һƬСС��ƽ�أ�����ֲ�����þ��ɣ��м����ƺ���ʲô��
�����������⡣¥�ϴ���һ������ƵĹ�����
LONG
	);

	set("exits", ([
		"up" : __DIR__"gulou7",
		"down" : __DIR__"gulou5",
	]));

	set("coor/x",20);
  set("coor/y",230);
   set("coor/z",170);
   setup();
}



