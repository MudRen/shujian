// Room: /d/dzd/shidong2.c

inherit __DIR__"dzd_room";

void create()
{
	set("short","����ʯ��");
	set("long",@LONG
��Ȼ�γɵ�����ʯ���������еĵضκ�ֱ���еĵض��ֺ��䣻�еĵض�����԰�еľ���
���ȣ�����ǰ�������г���ɽǰ����·֮�棻���еĵض����������ľ�������������������
��������һ��֮�С����й����������������ȷ紵����
LONG
	);
	set("exits",([
		"east" : __DIR__"shidong3",
		"west" : __DIR__"shidong1",
		"north" : __DIR__"shidong4",
		"south" : __DIR__"rukou",
	]));
	set("objects",([
		__DIR__"npc/bear" : 1,
	]));
	setup();
}