inherit ROOM;

void create()
{
	set("short", "����ͤ");
	set("long", @LONG
��˵���ڻ�Ȫ·�ϣ������κ��ţ�������ͤ������������ͤ������һ����
ò��ɭ���ϸ������š��ƹܣ����Ǹ���Ͷ̥���ڴ˹�·�ĵ������궼Ҫ������
�����������������Ժ󣬽���ȴ���еĶ�Թ������
LONG);
	set("exits", ([ 
		"out" : "/d/death/gate",
	]));
	set("no_fight", 1);
	set("objects", ([
		__DIR__"npc/mengpo": 1
	]) );
	setup();
}

int valid_leave(object me, string dir)
{
	if( wizardp(me) || !userp(me) ) return 1;
	if( dir == "out") 
		return notify_fail("���Ŷ�����̾�˿���������������������������ɡ�����������ʲô�������ˣ�\n");
	else return 1;
}
