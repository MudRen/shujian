// Room: /d/hengshan/cuiping2.c

inherit ROOM;

void create()
{
	set("short", "����ɽ��");
	set("long", @LONG
�����ڴ���ɽ���ϣ���ľ���죬�Ѽ����ա�ɽ�־��ף������������ã�һ
�г��׾���ϴ����ɽ���о�������ɽ��ɫ��
LONG
	);
	set("exits", ([
		"eastup"   : __DIR__"xuankong1",
		"eastdown" : __DIR__"cuiping1",
	]));

        set("outdoors", "��ɽ");
        set("no_clean_up", 0);
        setup();
}
