// cyzi-1.c
// by zqb

inherit ROOM;

void create()
{
	set("short", "��԰��");
	set("long", @LONG
�����������µĲ�԰�ӣ���Բ��������Ķ�أ�����������߲ˣ������
����������ġ����ڷ����ɮ�ˣ�Ҳ�������������Щ���񣬽��صĿ���
�����������԰������ʮ����ɮ��æµ�ĸ����ţ������м������Ͼ�Ȼ����
����
LONG
	);
        set("outdoors", "shaolin");

	set("exits", ([
		"south" : __DIR__"cyzi-2",
		"north" : __DIR__"xiaolu-3",
                "east" : __DIR__"cyzi-4",
	]));
        set("objects",([
		__DIR__"npc/yuan-gen" : 1,
	]));
	set("coor/x",100);
  set("coor/y",190);
   set("coor/z",110);
   setup();
}

