// Room: /d/dzd/shidong3.c

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
		"northwest" : __DIR__"shidong4",
		"west" : __DIR__"shidong2",
		"southwest" : __DIR__"rukou",
	]));
	setup();
}