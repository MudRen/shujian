// Room: /d/taishan/.c

inherit ROOM;

void create()
{
	set("short", "���ɷ�");
	set("long", @LONG
������ʮ���̵��м䣬���������˵�һ�γ�Ϊ��ʮ�ˣ�������ֱ��������
��һ�γ�Ϊ��ʮ�ˡ��ɴ˿���ʯ���ϣ�������˿��Կ���ǰ����˵�Ь�ף�ǰ
����˻�ͷ��ɼ���������˵ķ�����������һ����ÿ��ʮ������Ҫ��һ��Ϣ��
LONG
	);

	set("exits", ([
		"northup" : __DIR__"nantian",
		"southdown" : __DIR__"longmen",
	]));
	set("objects",([
		__DIR__"npc/qinbing1" : 2,
		__DIR__"npc/yujizi" : 1,
		__DIR__"npc/jianchu" :1,
	]));
	set("outdoors", "̩ɽ");
	setup();
}
