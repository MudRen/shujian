// Room: /d/dali/dg3.c
// bbb 1997/06/10 
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "��԰��");
	set("long", @LONG
���ﳣ������԰�������ظ����裬��ɽ�˺�����ʱ���ٰ촫ͳ�ƻᣬÿ��
�οͲ�����������֮ҹ�������������������£�¥��ͤ�ߣ���׺�ʵƷ���
�°ף���ظ���ҫ�������ˮӯӯ�������������������Ʈ�ݣ���������
LONG
	);
        set("outdoors", "����");

	set("exits", ([
		"east" : __DIR__"dg2",
	]));

	set("objects",([
		NPC_D("kid") : 1,
	]));

	setup();
}

void init()
{
	object me = this_player();
	if(me->query_temp("xuncheng")){
		me->set_temp("dali_xc/dg3",1);
	}
}
