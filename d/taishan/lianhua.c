// Room: /d/taishan/.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������ʵ��������ɽ���ܴض��ɣ�״������������Ϊ����������Σ����
�𣬽��廨�¡�����������󣬿ɿ������̵��е�������С�ϰ��������󣬹�
���������ֽ����˷塣�����߱���������ķ嶥��
LONG
	);

	set("exits", ([
		"westup" : __DIR__"tianjie",
		"northup" : __DIR__"shixin",
	]));

	set("outdoors", "̩ɽ");
	setup();
}
