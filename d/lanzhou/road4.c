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
		"southeast" : __DIR__"road3",
		"west" : __DIR__"yongdeng",
	]));

	setup();
}
