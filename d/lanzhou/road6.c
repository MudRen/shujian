// By River@SJ

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
�������������˿���̵���ӭ���������һ����ɳ���������岼춻�ԭ֮
�ϡ�һ���ɳ�������󵶸�һ��˺�����������������ͨ�������˿���·��
�����ĳ���������������ţ�ӭ���������������ˡ���ʱ��һ�Ӷ����˴���
��߲��������
LONG);
	set("outdoors", "����");

	set("exits", ([
		"southeast" : __DIR__"lanzhouw",
		"west" : __DIR__"road2",
	]));

	setup();
}
