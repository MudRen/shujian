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
	set("outdoors", "����");

	set("exits", ([
		"southeast" : "/d/group/entry/lzsroad3",
		"north" : __DIR__"sroad1",
	]));

	set("objects",([
		__DIR__"npc/keshang" : 1,
	]));
        
	setup();
}
