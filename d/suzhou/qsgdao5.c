inherit ROOM;

void create()
{
	set("short", "������");
	set("long",@long
�����ݳ�����������Լ��ʮ��͵���������򡣾�ʷ�����أ��Ƴ���Ԫ
��䣬ʫ���ż̸���Ӧ����ڣ���;�۴�ͣ�����ţ���ʫһ�ף�����������˪
���죬�������Գ��ߣ����ճ��⺮ɽ�£�ҹ��������ʹ������Ӵˣ�ʫ����
���������˿ڣ�����ʫ���������£�������Ҳ��������ʤ�ء�
long);
	set("outdoors", "����");
	set("exits",([
		"east" : __DIR__"qsgdao4",
		"northwest" : __DIR__"hanshansi",
		"south" : __DIR__"tulu1",
	]));
	set("objects", ([
		NPC_D("youke") : 2,
	]));
	setup();
}
