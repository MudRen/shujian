inherit ROOM;

void create()
{
	set("short", "���Ϲٵ�");
	set("long",@long
������һ����ʯ����ϣ����������ǳ���æ����ʱ����������ҴҶ�����
�����ǳ������ν��뺣�ڵĵط���������ͨ�����ճǡ�
long);
	set("outdoors", "����");
	set("exits",([
		"southeast" : "/d/suzhou/qsgdao6",
		"north" : __DIR__"jiangnan",
	]));
	setup();
}

void init()
{
	object me = this_player();

	if ( me->query("gb_job")){
		me->add("job_time/ؤ��", me->query("gb_job"));
		me->delete("gb_job");
	}
	if ( me->query("gb_job2")){
		me->add("job_time/��Ч����", me->query("gb_job2"));
		me->delete("gb_job2");
	}
}
