// Room: /d/dali/hg2.c
// bbb 1997/06/10
// cool 98.3.17
// Modify By River 98/12
// Update by Lklv 2001.10.17

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����������ɽ��һ����ˮ���̲��Ƶ����׷���㣬��û��ʣ�б�»�����
��ϸ���ɳ�̵׵ĺ�̲��ˮ��ɳ�ף����Ŀɰ����Ǹ�����ѵ���Ȼ��Ӿ����ÿ
��ʢ�ģ�����������֯���������У�ɳ̲�ϣ��������ἷ��һȺȺ��һ�����
���ĵ����ˡ�
LONG
	);
        set("outdoors", "����");
	set("exits", ([
		"north" : __DIR__"hg1",
	]));
        set("objects",([
		"/d/dali/npc/qiaozi" : 1,
        ]));
	setup();
}

void init()
{
	object me = this_player();
	if(me->query_temp("xuncheng")){
		me->set_temp("dali_xc/hg2",1);
	}
}
