// Room: /d/hengshan/cuipinggu2.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����Ͽ�����ʯ�ڶ�ֱ�����±�����һ����������������ƾ��յĺ�ɽ
ɽ���У�ȴ����ʮ���������ڴ���ɽ������������Σ�ң�������ȣ��������£�
��������¥�Կ���ȽȽ���䡣�Ǿ����������ˡ�
LONG
	);
	set("exits", ([
		"up"         : __DIR__"cuiping1",
		"northwest"  : __DIR__"cuipinggu1",
	]));

        set("outdoors", "��ɽ");
        set("no_clean_up", 0);
        setup();
}
