// Room: /d/shaolin/gulou3.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "��¥����");
	set("long", @LONG
���������ƺ�Խ��Խխ��¥��Ҳ��Ϊ���ơ������ϲ����໵����������
ľ����ɫҲ���¾ɲ�ͬ���Ӵ������������������Կ��������еĲؾ�¥�ͷ�
��¥¶������һ�ǣ���������ǰ����ݶ����ݼ������˸����ġ����֡�
LONG
	);

	set("exits", ([
		"up" : __DIR__"gulou4",
		"down" : __DIR__"gulou2",
	]));

	set("coor/x",20);
  set("coor/y",230);
   set("coor/z",140);
   setup();
}



