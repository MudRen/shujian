// Room: chiyangmen.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������ʯ����Բ��С���ţ���������е����һ�ֵ��պ��գ������
���ƺ����У��Ӻ������ķ������ϼ�����������������������ý���ɫ��
�ſ����ҷֱ�����һֻ���ޣ�Ϊͭ������һΪ�����������״��һΪǰ��
����״��
LONG
	);

        set("exits", ([
		"west" : __DIR__"rimulundian",
		"enter" : __DIR__"qingxinshe",
	]));

	setup();
}
