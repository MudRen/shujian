// Room: niupidazhang.c

inherit ROOM;

void create()
{
	set("short", "ţƤ����");
	set("long", @LONG
����������ʮ��ţƤ��͵��ɹ����񣬴�Լ��Բ����ʮ�ɣ���ƽ��������
���˼���һ�������ڳ�����Ϊ���ӣ�����һ�Ű������������Ÿ����꣬���ű�
�������Ա�վ�ŵ�һ��ɮ�˺�һ�������������ʲô��
LONG
	);

	set("exits", ([
		"south" : __DIR__"shenfeng",
	]));
	set("objects", ([
		__DIR__"../npc/hubilie" : 1,
		CLASS_D("xueshan") + "/fawang" : 1,
		__DIR__"../npc/daerba" : 1,
		__DIR__"../npc/nimoxing" : 1,
	]));
	setup();
}
