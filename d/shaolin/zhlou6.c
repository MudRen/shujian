// Room: /d/shaolin/zhonglou6.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "��¥����");
	set("long", @LONG
�ش�������һ����������ɽ�磬������ˡ������ɼ����ֵľ�ͷ������
ɽ�Ķ��崦����һƬСС��ƽ�أ�����ֲ�����þ��ɣ����ƺ���ʲô������
�������⡣ͷ���ϵ�¥�忪�˸��󶴣�����һ�ڴ��ӡ�������ֻ�ܿ�������
���±�Ե������ڶ����ģ�ʲôҲ��������
LONG
	);

	set("exits", ([
		"up" : __DIR__"zhlou7",
		"down" : __DIR__"zhlou5",
	]));

	set("coor/x",70);
  set("coor/y",230);
   set("coor/z",170);
   setup();
}



