// Room: /d/shaolin/banruo4.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "�������Ĳ�");
	set("long", @LONG
����һ�伫Ϊ��ª���������������ܣ����˼�������⣬���ڿյ�����
���������������İڷ��ż��������ҷ��ڵĻƲ����ţ���λ�뷢���׵�
��ɮ�������������Ŀ�붨�������Ǳ���ʮ���޺��������еĵط������پ�
���书�����ڴ������
LONG
	);

	set("exits", ([
		"south" : __DIR__"banruo3",
		"north" : __DIR__"banruo5",
	]));

	set("objects",([
		CLASS_D("shaolin") + "/cheng-shi" : 1,
	]));
	set("coor/x",110);
  set("coor/y",260);
   set("coor/z",110);
   setup();
}



