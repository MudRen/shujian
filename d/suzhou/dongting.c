// Room: /city/dongting.c

inherit ROOM;

void create()
{
	set("short", "���Ŷ���");
	set("long", @LONG
���������Ŷ�������֪���д����˵����ڡ����а���һ��ɼľԲ���ͼ���
���ӣ�������һ�׾��µ����˴�����ǽ�Ϲ���һ�����ã��������ͻ���ɽ����
��֪�����ֱʡ�
LONG
	);

	set("exits", ([
		"west" : __DIR__"ymzhengting",
	]));

	set("incity",1);
	setup();
}
