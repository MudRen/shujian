// Room: /d/shaolin/luohan4.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "�޺����Ĳ�");
	set("long", @LONG
����һ�伫Ϊ��ª���������������ܣ����˼�������⣬���ڿյ�����
���������������İڷ��ż��������ҷ��ڵĻƲ����ţ���λ�뷢���׵�
��ɮ�������������Ŀ�붨�������Ǳ���ʮ���޺��������еĵط������پ�
���书�����ڴ������
LONG
	);

	set("exits", ([
		"south" : __DIR__"luohan3",
		"north" : __DIR__"luohan5",
	]));

	set("objects",([
		CLASS_D("shaolin") + "/cheng-jing" : 1,
	]));
	set("coor/x",-10);
  set("coor/y",270);
   set("coor/z",120);
   set("coor/x",-10);
 set("coor/y",270);
   set("coor/z",120);
   setup();
}



