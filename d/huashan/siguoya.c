// Room: /d/huashan/siguoya.c
// Date: Look 99/03/25

inherit ROOM;

void quarter_pass();

void create()
{
	set("short", "˼����");
	set("long", @LONG
���ǻ�ɽ��˼���¡�Σ�����и�ɽ�����ǻ�ɽ���������ӷ���������ܷ�
֮�������Ϲ�ͺͺ�Ĵ�ݲ���������һ����ľ����Σ�����������ഫ����Ů��
���ϵ�һ�����飬���껪ɽ�ɵ���ʦ�Դ�Σ��Ϊ�ͷ�����֮������Ҫ�Ǳ��һ
���޲���ľ���޳������ܷ��ĵ��������˼��֮ʱ������Ϊ�������ţ�����
���͡�
LONG
	);
        set("outdoors", "��ɽ");

	set("exits", ([
	  "eastdown" : __DIR__"xiaolu2",
	  "enter" : __DIR__"hole",
	]));
	set("objects", ([ 
		__DIR__"npc/linghuchong" : 1,
	]));

	setup();
	quarter_pass();
}

void quarter_pass()
{
	mixed *local;

	local = localtime(time() * 60);
	if (local[2] < 6 || local[2] >= 21) {
		set("long", @LONG
���ǻ�ɽ��˼���¡�Σ�����и�ɽ�����ǻ�ɽ���������ӷ���������ܷ�
֮�������Ϲ�ͺͺ�Ĵ�ݲ���������һ����ľ����ɫ�Ұ������ѿ��������ܵ�
���
LONG
		);
		delete("exits/enter");
	}
	else {
		set("long", @LONG
���ǻ�ɽ��˼���¡�Σ�����и�ɽ�����ǻ�ɽ���������ӷ���������ܷ�
֮�������Ϲ�ͺͺ�Ĵ�ݲ���������һ����ľ����Σ�����������ഫ����Ů��
���ϵ�һ�����飬���껪ɽ�ɵ���ʦ�Դ�Σ��Ϊ�ͷ�����֮������Ҫ�Ǳ��һ
���޲���ľ���޳������ܷ��ĵ��������˼��֮ʱ������Ϊ�������ţ�����
���͡�
LONG
		);
		set("exits/enter", __DIR__"hole");
	}
	call_out("quarter_pass", 30);
}

int get_object(object ob)
{
        if(userp(ob))
        return 1;
        return 0;
}

int valid_leave(object me, string dir)
{
	object *inv = deep_inventory(me);
	object *obj;
	obj = filter_array(inv,(:get_object:));
	if( sizeof(obj) && dir =="enter" )
		return notify_fail("�㸺�ع��࣬�ж����ڱ�׾������һ��ײ��ɽ���ϡ�\n");
	if (me->query("fengset") && dir=="enter" ) {
		me->move(__DIR__"jiabi");
		return notify_fail("��ѭ�Ÿ��ٵĽݾ�һ���ӽ����˼�ɽ�ڡ�\n");
	}
	return ::valid_leave(me, dir);
}
