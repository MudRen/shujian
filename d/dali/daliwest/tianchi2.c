// Room: /d/dali/tianchi2.c
// bbb 1997/06/10 
// cool 98.3.17
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "��ذ�ɽ");
	set("long", @LONG
��ذ�ɽ��ɭ�ֲԴ�ï�ܣ�ʱ��������ż���޼����峿�ɵ����屦ɽ�翴
�ճ���Զɽ����������ȽȽ���ڣ�����׳�ۡ�Զ��������ѩɽ��ѩ���������
���Ƹߣ���ɫ���棬������ˬ��Ұ���ͷף�ÿ�����£����Ƕ����͡�
LONG
	);
        set("outdoors", "����");

	set("exits", ([
		"down" : __DIR__"tianchi1",
	]));

	set("objects",([
		NPC_D("caiyaoren") : 1,
	]));

	setup();
}

void init()
{
	object me = this_player();
	if(me->query_temp("xuncheng")){
		me->set_temp("dali_xc/tianchi2",1);
	}
}
