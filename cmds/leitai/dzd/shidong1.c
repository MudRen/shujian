// Room: /d/dzd/shidong1.c

inherit __DIR__"dzd_room";

void create()
{
	set("short","����ʯ��");
	set("long",@LONG
����һ����Ȼ�γɵ�����ʯ���������еĵضκ�ֱ���еĵض��ֺ��䣻�еĵض�����԰�еľ�����
�ȣ�����ǰ�������г���ɽǰ����·֮�棻���еĵض����������ľ�������������������
��������һ��֮�С����й����������������ȷ紵����
LONG
	);
	set("exits",([
		"northeast" : __DIR__"shidong4",
		"east" : __DIR__"shidong2",
		"southeast" : __DIR__"rukou",
	]));
	setup();
}
