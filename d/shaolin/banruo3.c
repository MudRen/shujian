// Room: /d/shaolin/banruo3.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "����������");
	set("long", @LONG
����һ�伫Ϊ��ª���������������ܣ����˼�������⣬���ڿյ�����
���������������İڷ��ż��������ҷ��ڵĻƲ����ţ���λ�뷢���׵�
��ɮ�������������Ŀ�붨�������Ǳ���ʮ���޺��������еĵط������پ�
���书�����ڴ������
LONG
	);

	set("exits", ([
		"south" : __DIR__"banruo2",
		"north" : __DIR__"banruo4",
	]));

	set("objects",([
		CLASS_D("shaolin") + "/cheng-si" : 1,
	]));
	set("coor/x",110);
  set("coor/y",250);
   set("coor/z",110);
   setup();
}



