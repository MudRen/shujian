// /d/suzhou/qsgdao6.c

inherit ROOM;
void create()
{
	set("short", "���ݱ���");
	set("long",@long
�������ݱ�����һ����ʯ�����·�����������ǳ���æ����ʱ����������
��ҴҶ�����������һƬ�����͵ĵ��Զ�����м���С��̯���ƺ���һ����
�С�һƬ����ˮ��ľ�ɫ�����������߾������ݳ��ˡ�
long);
	set("outdoors", "suzhou");
	set("exits",([
		"northwest" : "/d/city/sroad1",
		"southwest" : __DIR__"huqiushan",
		"south" : __DIR__"northgate",
		"west" : "/d/gb/tianjing",
	]));
	setup();
}
