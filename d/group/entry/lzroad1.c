// By River@SJ

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
�������������˿���̵���ӭ���������һ����ɳ���������岼춻�ԭ֮
�ϡ�һ���ɳ�������󵶸�һ��˺�����������������ͨ�������˿���·��
�����ĳ���������������ţ�ӭ���������������ˡ���ʱ��һ�Ӷ����˴���
��߲�����������������ݣ����������߱��Ǿ�������ɽ�ˡ�
LONG);
	set("outdoors", "���ݳ�");
	set("group", 1);
	set("exits", ([
		"northeast" : "/d/lanzhou/jingyuan",
		"southwest" : "/d/lanzhou/road5",
	]));

	setup();
}
