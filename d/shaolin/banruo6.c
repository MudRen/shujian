// Room: /d/shaolin/banruo6.c
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
		"south" : __DIR__"banruo5",
		"north" : __DIR__"banruo7",
	]));

	set("objects",([
		CLASS_D("shaolin") + "/cheng-xin2" : 1,
	]));
	set("coor/x",110);
  set("coor/y",280);
   set("coor/z",110);
   setup();
}



