// Modify By River 98/12/

inherit ROOM;

void create()
{
	set("short", "��վ");
	set("long", @LONG
���Ǵ�����վ�������ͺʹ��ι������ָ������ɵĹ��ģ��ܺ��������
��ɭ�ϣ������ĵģ�ֻ����ʱ���˽����������ּ���ææ���뿪���ſڵ�ľ��
�ϱ�����һ�����ӣ�sign)��
LONG
	);
	set("no_fight",1);
	set("no_sleep_room",1);

	set("item_desc", ([
		"sign": "����\"ask wanli about ���� \" ��ȡ����\n",
	]));

	set("exits", ([
		"west" : __DIR__"qsjie2",
	]));

	set("objects", ([
		__DIR__"npc/bing" : 2,
		__DIR__"npc/zhuwanli" : 1,
	]));
	setup(); 
}

void init()
{
	object me = this_player();
	if(me->query_temp("xuncheng")){
		me->set_temp("dali_xc/yizhan",1);
	}
	if ( me->query("dali_job")){
		me->add("job_time/����", me->query("dali_job"));
		me->delete("dali_job");
	}
}
