// Room: /d/city/dongdajie2.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ����������ʯ��ֵ���������ͷ���졣���߲�ʱ�ش�������ײ��
���������������ӡ�������һ�����ӵ�Ժ�ӣ������εĴ����Ϸ�д�š���¹��
Ժ���ĸ��̽���֣��Ծ����������治ʱ�ش���ѧ��������ٴ�Ķ���������
����һ���ӻ��̡�
LONG
	);
        set("outdoors", "����");

        set("objects", ([
                CLASS_D("gaibang") + "/kong" : 1,
        ]));

	set("exits", ([
		"east" : __DIR__"dongdajie1",
		"south" : __DIR__"zahuopu",
	        "west" : __DIR__"dongdajie3",
		"north" : __DIR__"shuyuan",
	]));

	set("coor/x",110);
  set("coor/y",-10);
   set("coor/z",0);
   setup();
}

