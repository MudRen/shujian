// /d/hmy/changlang6.c

inherit ROOM;
void create()
{
	set("short", "����");
	set("long",@long
һ·�߹���ֻ��������������ʿ�������ԣ����и�ͦһ�����λεĳ�����
����ƽ�٣�����֮�˶�Ҫ������ͷ���������ٱ�������ֻҪ��һ��ͻȻ���䣬
�㲻�������촦��
long);
	set("exits",([
		"north" : __DIR__"changlang4",
		"south" : __DIR__"houdian",
		"east" : __DIR__"yiting",
		"west" : __DIR__"dadian",
	]));
	setup();
}
