// Room: //dali/ximen.c
// bbb 1997/06/11
// Modify By River 98/12/
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������ͨ��������ɲ�ıؾ�֮�أ��������鷸�ƵĴ�ͽ�������������ɽ
�У������ڴ�ֵ�ڵ��佫�ٱ��ܻ񣬶���ү���ǳ����Լ���������������������
�����Խ������������ﲻ����
LONG
	);
	set("outdoors", "����");
	set("no_fight",1);
	set("exits", ([
		"westup" : "/d/tls/diancang",
		"east" : __DIR__"xijie4",
	]));
	set("objects", ([
		__DIR__"npc/zhudanchen" : 1,
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
	]));
	setup();
}

void init()
{
 object me = this_player();
me->set("env/brf_go",1); 
 if(!me->query("cw_exp")) 
                          me->delete("relife/exp_ext");
if(me->query("combat_exp")<100000)
      me->apply_condition("db_exp", 1000);
 }
