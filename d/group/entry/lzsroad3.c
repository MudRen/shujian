// By River@SJ

inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
������ͨ�������˿���·�������ĳ���������������ţ�ӭ���������
������ˡ���ʱ��һ�Ӷ����˴�����߲�����������߾ͽӽ������ݳǣ�����
�Ϸ�����ȥ��ǵĵ�·��
LONG);
	set("outdoors", "���ݳ�");
	set("group", 1);
	set("exits", ([
		"southeast" : "/d/lanzhou/qingcheng",
		"northwest" : "/d/lanzhou/sroad2",
	]));
        
	setup();
}
