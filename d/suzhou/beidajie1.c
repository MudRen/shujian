inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����æ�Ľֵ��ϣ����Ų�����ǻ������������ɫ�Ҵң������
�����ϱ���ȥ��������һ�����ֵ�ͤ�ӡ���������һ��Ϸ԰�ӣ���ʱ������
���������Ը��ص����ǽ����������ڶ�����һ���͵ꡣ������һ����ǡ�
LONG
	);
        set("outdoors", "suzhou");

	set("exits", ([
		"west" : __DIR__"majiu",
                "east" : __DIR__"kedian",
"south" : __DIR__"canglangting",
		"southwest" : __DIR__"xiyuanzi",
		"north" : __DIR__"beidajie2",
	]));
	set("coor/x",110);
  set("coor/y",-210);
   set("coor/z",0);
   set("incity",1);
	set("incity",1);
	setup();
}

