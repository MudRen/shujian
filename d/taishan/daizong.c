// Room: /d/taishan/.c

inherit ROOM;

void create()
{
	set("short", "��ڷ�");
	set("long", @LONG
λ��̩���س��Ա�Լһ��˴��ǵ�̩ɽ����ڡ��ഫ�����ϼԪ������
����ϷŪ������Ͷ���廨Ь�Զ�̩ɽ�ؽ磬�����ϼԪ��ֻ�ܰ��廨Ь��ɽ��
�����˴����Ӵ�̩ɽ���Դ�Ϊ��㡣
LONG
	);

        set("objects", ([
		__DIR__"npc/shangren" : 1,
	]));

	set("exits", ([
		"northup" : __DIR__"baihe",
		"east" :__DIR__"haitan",
		"west" : "/d/huanghe/huanghe5",
		"south" : "/d/group/entry/tsyidao3",
	]));

	set("outdoors", "̩ɽ");
	setup();
}
