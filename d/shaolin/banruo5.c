// Room: /d/shaolin/banruo5.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "�������岿");
	set("long", @LONG
����һ�伫Ϊ��ª���������������ܣ����˼�������⣬���ڿյ�����
���������������İڷ��ż��������ҷ��ڵĻƲ����ţ���λ�뷢���׵�
��ɮ�������������Ŀ�붨�������Ǳ���ʮ���޺��������еĵط������پ�
���书�����ڴ������
LONG
	);

	set("exits", ([
		"west" : __DIR__"lwc11",
		"south" : __DIR__"banruo4",
		"north" : __DIR__"banruo6",
	]));

	set("objects",([
//		CLASS_D("shaolin") + "/xuan-nan" : 1,
		CLASS_D("shaolin") + "/cheng-zhi2" : 1,
//		__DIR__"npc/xiao-nan" : 1
	]));

	set("coor/x",110);
  set("coor/y",270);
   set("coor/z",110);
   setup();
}
