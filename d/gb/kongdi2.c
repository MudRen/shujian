// Room: kongdi2.c �յ�

inherit ROOM;

void create()
{
	set("short", "�յ�");
	set("long", @LONG
������������м��һƬ�յء����ܵ����Ϲ���һ������¨�������кܶ඾��
���䶯��һ������ؤ���ڵ��������������ߡ�ؤ����ӿ����������ʳ³�����
��ץ�ߵ��¡�
LONG
	);
	set("outdoors", "����");

	set("exits", ([
		"east" : __DIR__"xinglin9",
	]));

	set("objects", ([
		CLASS_D("gaibang") + "/chen" : 1,
	]));

	setup();
}

void init()
{
	object me = this_player();
	if ( me->query("snake_job")){
		me->add("job_time/ץ��", me->query("snake_job"));
		me->delete("snake_job");
	}
	if( me->query("job_time/ؤ��׽��") )
	{
		me->add("job_time/ץ��", me->query("job_time/ؤ��׽��") );
		me->delete("job_time/ؤ��׽��");
	}
}
