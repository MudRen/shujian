// Room: /d/shaolin/zhonglou3.c
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
		"up" : __DIR__"zhlou4",
		"down" : __DIR__"zhlou2",
	]));

	set("coor/x",70);
  set("coor/y",230);
   set("coor/z",140);
   setup();
}



