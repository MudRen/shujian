// Room: zanpugc.c
// Lane@ln 2004.7.1

#include <ansi.h>
inherit ROOM;
/*
int sort_file(string file)
{
	int i;
	if( file[<2..<1] != ".c" ) return 0;
	if( !sscanf(file, "%*s.c") )  return 0;
	if( sscanf(file, "%*s_noshow.c") )  return 0;
	i = strlen(file);
	while(i--){
		if( file[i] == '.' ) continue;
		if( file[i] < 'a' || file[i] > 'z' )
			return 0;
	}

	return 1;
}
*/
void create()
{
	set("short", "���չ㳡");
	set("long", @LONG
�����ǻʳ����ĵ�һƬ�㳡���㳡����������ެ���յ�ʯ��������������
�����в����������𾢵�ߺ���š��㳡���������ڽ����е���ެ�»ʹ���һ�Ӷ�
���������װ��ʯ��ľ�ϵ��Ƴ��߹�ȥ��������ެ��ʿ������·�ڣ������ע��
���������������ˡ������Ƿ����ţ���ͨ����ެ�������´����µıϾ�֮·��
LONG);

	set("exits", ([
		"west" : __DIR__"fozhaomen",
		"east" : __DIR__"huanggong",
		"north" : __DIR__"jiedao3",
		"south" : __DIR__"jiedao2",
	]));

	set("objects", ([__DIR__"npc/tufanwushi" : 3,]));
	set("outdoors", "ѩɽ");
	set("job_lane", 1);
	setup();
}
/*
void init()
{
	object me = this_player();

	if( (int)me->query("combat_exp") > 100000 && me->query("family/family_name") == "������" 
	 && random(me->query("kar")) > 10 && query("job_lane") >= 1 && random(50) == 20 ) {
		add("job_lane", -1);
		call_out("do_job", 1 + random(5), me);
	}
} 

void do_job(object me)
{
	object *list;
	object target, obj;
	string *file, where;

	if( !me ) return;

	if( query_temp("count") > 10 ) {
		delete_temp("count");
		return;
	}

	list = filter_array(users(), (: $1->query("combat_exp")>=100000 :));
	target = list[random(sizeof(list))];

	if( (!environment(target)) || target->query("env/invisibility")
	 || !interactive(target) || target->query("id") == me->query("id")
	 || target->query("family/family_name") == me->query("family/family_name") ) {
		add_temp("count",1);
		call_out("do_job", 1, me);
		return;
	} else {

		file = get_dir("d/xueshan/");
		if( sizeof(file) > 0 ) file = filter_array(file, (: sort_file :) );

		where = "/d/xueshan/" + file[random(sizeof(file))];

		tell_object(me, YEL+where+"\n"NOR);

		obj = new(__DIR__"npc/job_npc");
		obj->do_copy(target);
		obj->move(where);
		obj->set("family/family_name", target->query("family/family_name"));
		obj->set("kill_party", me->query("family/family_name"));
		CHANNEL_D->do_channel(me, "party", "��˵" + target->query("family/family_name") + 
		HIR + target->query("name") + HIW + "(" + target->query("id") + ")" + HIG
		"��"BLU"Ӱ����ʿ"HIG"ǰ��ѩɽ���ң�������" + HIR + environment(obj)->query("short") + HIG + "һ�����ֹ���\n");
	}
}
*/
