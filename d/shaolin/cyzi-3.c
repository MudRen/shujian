// cyzi-3.c
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
		"west" : __DIR__"cyzi-2",
		"north" : __DIR__"cyzi-4",
	]));
	set("coor/x",110);
  set("coor/y",180);
   set("coor/z",110);
   setup();
}

