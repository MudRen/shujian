// By River@SJ

inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
�������������˿���̵���ӭ���������һ����ɳ���������岼춻�ԭ֮
�ϡ�һ���ɳ�������󵶸�һ��˺�����������������ͨ�������˿���·��
�����ĳ���������������ţ�ӭ���������������ˡ���ʱ��һ�Ӷ����˴���
��߲�����������߾������ݳ��ˡ�
LONG);
	set("outdoors", "����");
   set("quest",1);

	set("exits", ([
		"north" : __DIR__"lanzhous",
		"south" : __DIR__"sroad2",
                "west" : __DIR__"zhengmen",
	]));
        
	setup();
}
